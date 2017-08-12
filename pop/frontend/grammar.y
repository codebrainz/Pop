%pure-parser
%locations
%error-verbose
%parse-param { Pop::ParseState *state }
%lex-param { void *scanner }

%union {
	int ival;
	char *sval;
	Pop::Node *nval;
}

%token <ival> T_BREAK T_CASE T_CLASS T_CONTINUE T_DEFAULT T_DO T_ELSE
%token <ival> T_ENUM T_FOR T_FUNCTION T_GOTO T_IF T_LET T_NAMESPACE
%token <ival> T_RETURN T_SWITCH T_WHILE
%token <ival> T_ELLIPSIS T_RIGHT_ASSIGN T_LEFT_ASSIGN
%token <ival> T_ADD_ASSIGN T_SUB_ASSIGN T_MUL_ASSIGN T_DIV_ASSIGN T_MOD_ASSIGN
%token <ival> T_AND_ASSIGN T_XOR_ASSIGN T_OR_ASSIGN T_RIGHT_OP T_LEFT_OP
%token <ival> T_INC_OP T_DEC_OP T_PTR_OP T_AND_OP T_OR_OP
%token <ival> T_LE_OP T_GE_OP T_EQ_OP T_NE_OP
%token <ival> T_NULL T_TRUE T_FALSE
%token <sval> T_IDENTIFIER T_INT T_FLOAT T_STRING

%type <nval> add_expr
%type <nval> and_expr
%type <nval> arg_list
%type <nval> assign_expr
%type <nval> block_stmt
%type <nval> case_list
%type <nval> case_stmt
%type <nval> class_decl
%type <nval> class_field
%type <nval> class_fields
%type <nval> cond_expr
%type <nval> constant
%type <nval> eq_expr
%type <nval> expr
%type <nval> expr_stmt
%type <nval> func_decl
%type <nval> func_expr
%type <nval> iter_stmt
%type <nval> jump_stmt
%type <nval> log_and_expr
%type <nval> log_or_expr
%type <nval> mul_expr
%type <nval> or_expr
%type <nval> param_decl
%type <nval> param_list
%type <nval> post_expr
%type <nval> prim_expr
%type <nval> rel_expr
%type <nval> sel_stmt
%type <nval> shift_expr
%type <nval> stmt
%type <nval> stmts
%type <nval> unary_expr
%type <nval> var_decl
%type <nval> xor_expr

%destructor { free($$); } <sval>
%destructor { Pop::node_unref($$); } <nval>

%nonassoc NO_ELSE
%nonassoc T_ELSE

%code requires {
#ifndef POP_LIB_COMPILATION_
# error "Inclusion of private header, use '<pop/pop.hpp>' instead to include all public headers."
#endif

#include <pop/ir/ast.hpp>
#include <pop/frontend/parse-state.hpp>

#define YY_EXTRA_TYPE Pop::ParseState*

using namespace Pop;
}

%{
#ifdef HAVE_CONFIG_H
# include <pop/config.h>
#endif

#include <pop/common/logger.hpp>
#include <pop/common/utils.hpp>
#include <pop/ir/operators.hpp>

extern int yylex(YYSTYPE *, YYLTYPE *, void*);

using namespace Pop;

void yyerror(YYLTYPE *locp, ParseState *state, const char *err) {
  state->log.error(state->file, locp->first_line, locp->first_column, err);
}

#define scanner state->scanner

#define mknode(T, loc, ...) \
	Pop::make_node<T>(state->file, loc.first_line, loc.first_column, ##__VA_ARGS__)

#define list_append(lst, elem) \
	dynamic_cast<NodeList*>(lst)->append_take(elem)

%}

%%

start
	: stmts { state->roots = $1; }
	;

param_decl
	: T_IDENTIFIER          { $$ = mknode(Variable, @1, $1, nullptr); free($1); }
	| T_IDENTIFIER '=' expr { $$ = mknode(Variable, @1, $1, $3); free($1); }
	;

param_list
	: param_decl                { $$ = mknode(NodeList, @1, $1); }
	| param_list ',' param_decl { $$ = $1; list_append($1, $3); }
	;

func_expr
	: T_FUNCTION '(' param_list ')' '{' '}'       { $$ = mknode(Function, @1, $3, nullptr); }
	| T_FUNCTION '(' param_list ')' '{' stmts '}' { $$ = mknode(Function, @1, $3, $6); }
	| T_FUNCTION '(' ')' '{' stmts '}'            { $$ = mknode(Function, @1, nullptr, $5); }
	| T_FUNCTION '(' ')' '{' '}'                  { $$ = mknode(Function, @1, nullptr, nullptr); }
	;

constant
	: T_NULL       { $$ = mknode(Null, @1); }
	| T_TRUE       { $$ = mknode(Bool, @1, true); }
	| T_FALSE      { $$ = mknode(Bool, @1, false); }
	| T_INT
		{
			try {
				long long int val = Pop::parse_int($1);
				$$ = mknode(Int, @1, val);
				free($1);
			} catch (...) {
				state->log.error(state->file, @1.first_line, @1.first_column,
					"invalid integer literal '%'", $1);
				free($1);
			}
		}
	| T_FLOAT
		{
			try {
				long double val = Pop::parse_float($1);
				$$ = mknode(Float, @1, val);
				free($1);
			} catch (...) {
				state->log.error(state->file, @1.first_line, @1.first_column,
					"invalid floating-point literal '%s'", $1);
				free($1);
			}
		}
	| T_STRING { $$ = mknode(String, @1, $1); free($1); }
	| T_IDENTIFIER { $$ = mknode(Symbol, @1, $1); free($1); }
	;

prim_expr
	: constant     { $$ = $1; }
	| '(' expr ')' { $$ = $2; }
	| func_expr    { $$ = $1; }
	;

arg_list
	: expr              { $$ = mknode(NodeList, @1, $1); }
	| arg_list ',' expr { $$ = $1; list_append($1, $3); }
	;

post_expr
	: prim_expr                  { $$ = $1; }
	| post_expr '[' expr ']'     { $$ = mknode(Binary, @2, Operator::INDEX, $1, $3); }
	| post_expr '(' ')'          { $$ = mknode(Call, @2, $1, nullptr); }
	| post_expr '(' arg_list ')' { $$ = mknode(Call, @2, $1, $3); }
	| post_expr '.' T_IDENTIFIER
		{
			Node *id = mknode(Symbol, @3, $3);
			$$ = mknode(Binary, @2, Operator::MEMBER, $1, id);
			free($3);
		}
	| post_expr T_INC_OP         { $$ = mknode(Unary, @2, Operator::POSTINC, $1); }
	| post_expr T_DEC_OP         { $$ = mknode(Unary, @2, Operator::POSTDEC, $1); }
	;

unary_expr
	: post_expr           { $$ = $1; }
	| T_INC_OP unary_expr { $$ = mknode(Unary, @1, Operator::PREINC, $2); }
	| T_DEC_OP unary_expr { $$ = mknode(Unary, @1, Operator::PREDEC, $2); }
	| '+' unary_expr      { $$ = mknode(Unary, @1, Operator::POS, $2); }
	| '-' unary_expr      { $$ = mknode(Unary, @1, Operator::NEG, $2); }
	| '!' unary_expr      { $$ = mknode(Unary, @1, Operator::NOT, $2); }
	| '~' unary_expr      { $$ = mknode(Unary, @1, Operator::COMPL, $2); }
	;

mul_expr
	: unary_expr              { $$ = $1; }
	| mul_expr '*' unary_expr { $$ = mknode(Binary, @2, Operator::MUL, $1, $3); }
	| mul_expr '/' unary_expr { $$ = mknode(Binary, @2, Operator::DIV, $1, $3); }
	| mul_expr '%' unary_expr { $$ = mknode(Binary, @2, Operator::MOD, $1, $3); }
	;

add_expr
	: mul_expr              { $$ = $1; }
	| add_expr '+' mul_expr { $$ = mknode(Binary, @2, Operator::ADD, $1, $3); }
	| add_expr '-' mul_expr { $$ = mknode(Binary, @2, Operator::SUB, $1, $3); }
	;

shift_expr
	: add_expr                       { $$ = $1; }
	| shift_expr T_LEFT_OP add_expr  { $$ = mknode(Binary, @2, Operator::LSHIFT, $1, $3); }
	| shift_expr T_RIGHT_OP add_expr { $$ = mknode(Binary, @2, Operator::RSHIFT, $1, $3); }
	;

rel_expr
	: shift_expr                  { $$ = $1; }
	| rel_expr '<' shift_expr     { $$ = mknode(Binary, @2, Operator::LT, $1, $3); }
	| rel_expr '>' shift_expr     { $$ = mknode(Binary, @2, Operator::GT, $1, $3); }
	| rel_expr T_LE_OP shift_expr { $$ = mknode(Binary, @2, Operator::LE, $1, $3); }
	| rel_expr T_GE_OP shift_expr { $$ = mknode(Binary, @2, Operator::GE, $1, $3); }
	;

eq_expr
	: rel_expr                 { $$ = $1; }
	| eq_expr T_EQ_OP rel_expr { $$ = mknode(Binary, @2, Operator::EQ, $1, $3); }
	| eq_expr T_NE_OP rel_expr { $$ = mknode(Binary, @2, Operator::NE, $1, $3); }
	;

and_expr
	: eq_expr              { $$ = $1; }
	| and_expr '&' eq_expr { $$ = mknode(Binary, @2, Operator::BAND, $1, $3); }
	;

xor_expr
	: and_expr              { $$ = $1; }
	| xor_expr '^' and_expr { $$ = mknode(Binary, @2, Operator::BXOR, $1, $3); }
	;

or_expr
	: xor_expr             { $$ = $1; }
	| or_expr '|' xor_expr { $$ = mknode(Binary, @2, Operator::BOR, $1, $3); }
	;

log_and_expr
	: or_expr                       { $$ = $1; }
	| log_and_expr T_AND_OP or_expr { $$ = mknode(Binary, @2, Operator::LAND, $1, $3); }
	;

log_or_expr
	: log_and_expr                     { $$ = $1; }
	| log_or_expr T_OR_OP log_and_expr { $$ = mknode(Binary, @2, Operator::LOR, $1, $3); }
	;

cond_expr
	: log_or_expr                        { $$ = $1; }
	| log_or_expr '?' expr ':' cond_expr { $$ = mknode(IfExpr, @2, $1, $3, $5); }
	;

assign_expr
	: cond_expr                             { $$ = $1; }
	| unary_expr '=' assign_expr            { $$ = mknode(Binary, @2, Operator::ASSIGN, $1, $3); }
	| unary_expr T_ADD_ASSIGN assign_expr   { $$ = mknode(Binary, @2, Operator::ADD_ASSIGN, $1, $3); }
	| unary_expr T_SUB_ASSIGN assign_expr   { $$ = mknode(Binary, @2, Operator::SUB_ASSIGN, $1, $3); }
	| unary_expr T_MUL_ASSIGN assign_expr   { $$ = mknode(Binary, @2, Operator::MUL_ASSIGN, $1, $3); }
	| unary_expr T_DIV_ASSIGN assign_expr   { $$ = mknode(Binary, @2, Operator::DIV_ASSIGN, $1, $3); }
	| unary_expr T_MOD_ASSIGN assign_expr   { $$ = mknode(Binary, @2, Operator::MOD_ASSIGN, $1, $3); }
	| unary_expr T_LEFT_ASSIGN assign_expr  { $$ = mknode(Binary, @2, Operator::LSHIFT_ASSIGN, $1, $3); }
	| unary_expr T_RIGHT_ASSIGN assign_expr { $$ = mknode(Binary, @2, Operator::RSHIFT_ASSIGN, $1, $3); }
	| unary_expr T_AND_ASSIGN assign_expr   { $$ = mknode(Binary, @2, Operator::AND_ASSIGN, $1, $3); }
	| unary_expr T_XOR_ASSIGN assign_expr   { $$ = mknode(Binary, @2, Operator::XOR_ASSIGN, $1, $3); }
	| unary_expr T_OR_ASSIGN assign_expr    { $$ = mknode(Binary, @2, Operator::OR_ASSIGN, $1, $3); }
	;

expr
	: assign_expr { $$ = $1; }
	;

stmts
	: stmt       { $$ = mknode(NodeList, @1, $1); }
	| stmts stmt { $$ = $1; list_append($1, $2); }
	;

stmt
	: expr_stmt  { $$ = $1; }
	| block_stmt { $$ = $1; }
	| func_decl  { $$ = $1; }
	| var_decl   { $$ = $1; }
	| jump_stmt  { $$ = $1; }
	| iter_stmt  { $$ = $1; }
	| sel_stmt   { $$ = $1; }
	| class_decl { $$ = $1; }
	| ';'        { $$ = mknode(EmptyStmt, @1); }
	;

expr_stmt
	: expr ';' { $$ = mknode(ExprStmt, @1, $1); }
	;

block_stmt
	: '{' '}'
		{
			Node *s = mknode(NodeList, @1);
			$$ = mknode(Block, @1, s);
		}
	| '{' stmts '}' { $$ = mknode(Block, @1, $2); }
	;

case_stmt
	: T_CASE expr ':'       { $$ = mknode(Case, @1, $2, nullptr); }
	| T_CASE expr ':' stmts { $$ = mknode(Case, @1, $2, $4); }
	| T_DEFAULT ':'         { $$ = mknode(Case, @1, nullptr, nullptr); }
	| T_DEFAULT ':' stmts   { $$ = mknode(Case, @1, nullptr, $3); }
	;

case_list
	: case_stmt           { $$ = mknode(NodeList, @1, $1); }
	| case_list case_stmt { $$ = $1; list_append($1, $2); }
	;

sel_stmt
	: T_IF '(' expr ')' stmt %prec NO_ELSE    { $$ = mknode(IfStmt, @1, $3, $5, nullptr); }
	| T_IF '(' expr ')' stmt T_ELSE stmt      { $$ = mknode(IfStmt, @1, $3, $5, $7); }
	| T_SWITCH '(' expr ')' '{' case_list '}' { $$ = mknode(Switch, @1, $3, $6); }
	| T_SWITCH '(' expr ')' '{' '}'           { $$ = mknode(Switch, @1, $3, nullptr); }
	;

iter_stmt
	: T_WHILE '(' expr ')' stmt      { $$ = mknode(While, @1, $3, $5); }
	| T_DO stmt T_WHILE '(' expr ')' { $$ = mknode(Do, @1, $2, $5); }
	; /* for stmts */

jump_stmt
	: T_CONTINUE ';'    { $$ = mknode(Continue, @1); }
	| T_BREAK ';'       { $$ = mknode(Break, @1); }
	| T_RETURN ';'      { $$ = mknode(Return, @1, nullptr); }
	| T_RETURN expr ';' { $$ = mknode(Return, @1, $2); }
	;

class_field
	: var_decl  { $$ = $1; }
	| func_decl { $$ = $1; }
	;

class_fields
	: class_field              { $$ = mknode(NodeList, @1, $1);}
	| class_fields class_field { $$ = $1; list_append($$, $2); }
	;

class_decl
	: T_CLASS T_IDENTIFIER '{' '}'
		{
			Node *m = mknode(NodeList, @3);
			$$ = mknode(Class, @1, $2, m);
			free($2);
		}
	| T_CLASS T_IDENTIFIER '{' class_fields '}'
		{
			$$ = mknode(Class, @1, $2, $4);
			free($2);
		}
	;

func_decl
	: T_FUNCTION T_IDENTIFIER '(' param_list ')' '{' '}'
		{
			Node *body = mknode(NodeList, @6);
			Node *fnc = mknode(Function, @1, $4, body);
			$$ = mknode(Variable, @1, $2, fnc);
			free($2);
		}
	| T_FUNCTION T_IDENTIFIER '(' ')' '{' stmts '}'
		{
			Node *params = mknode(NodeList, @3);
			Node *fnc = mknode(Function, @1, params, $6);
			$$ = mknode(Variable, @1, $2, fnc);
			free($2);
		}
	| T_FUNCTION T_IDENTIFIER '(' param_list ')' '{' stmts '}'
		{
			Node *fnc = mknode(Function, @1, $4, $7);
			$$ = mknode(Variable, @1, $2, fnc);
			free($2);
		}
	| T_FUNCTION T_IDENTIFIER '(' ')' '{' '}'
		{
			Node *params = mknode(NodeList, @3);
			Node *body = mknode(NodeList, @5);
			Node *fnc = mknode(Function, @1, params, body);
			$$ = mknode(Variable, @1, $2, fnc);
			free($2);
		}
	;

var_decl
	: T_LET T_IDENTIFIER              { $$ = mknode(Variable, @1, $2, nullptr); free($2); }
	| T_LET T_IDENTIFIER '=' expr ';' { $$ = mknode(Variable, @1, $2, $4); free($2); }
	;
