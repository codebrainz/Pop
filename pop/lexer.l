%option reentrant
%option bison-bridge
%option bison-locations
%option noyywrap
%option nounistd
%option noinput
%option nounput
%option yylineno

O   [0-7]
D   [0-9]
B   [0-1]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
BP  (0[bB])
OP  (0[oO])
DP  (0[dD])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]

%{
#ifdef HAVE_CONFIG_H
# include <pop/config.h>
#endif

#include <pop/parse-state.hpp>
#include <pop/grammar.hpp>
#include <pop/utils.hpp>

#define YY_USER_ACTION                           \
  {                                              \
    yylloc->first_line = yylineno;               \
    yylloc->first_column = yylloc->last_column;  \
    count_linecol(yytext, yyleng,                \
      &yylloc->last_line, &yylloc->last_column); \
  }

#define YY_INPUT(buf, result, max_size) \
  {                                     \
    int c = yyextra->is.get();          \
    if (c == EOF) {                     \
      result = YY_NULL;                 \
    } else {                            \
      buf[0] = c;                       \
      result = 1;                       \
    }                                   \
  }


#define SAVE_STR() \
  do { yylval->sval = Pop::strndup(yytext, yyleng); } while (0)

#include <cstdio>
#include <cstring>

extern "C" int isatty(int);

static void count_linecol(const char *s, int len, int *ln, int *col)
{
  for (int i = 0; i < len; i++) {
    if (s[i] == '\n') {
      (*ln)++;
      (*col) = 0;
    } else {
      (*col)++;
    }
  }
}

%}

%x MCOMMENT

%%

"/*"           { BEGIN(MCOMMENT); }
<MCOMMENT>"*/" { BEGIN(INITIAL); }
<MCOMMENT>\n   { }
<MCOMMENT>.    { }

"//".* { }

"break"     { return T_BREAK; }
"case"      { return T_CASE; }
"class"     { return T_CLASS; }
"continue"  { return T_CONTINUE; }
"default"   { return T_DEFAULT; }
"do"        { return T_DO; }
"else"      { return T_ELSE; }
"enum"      { return T_ENUM; }
"false"     { return T_FALSE; }
"for"       { return T_FOR; }
"function"  { return T_FUNCTION; }
"goto"      { return T_GOTO; }
"if"        { return T_IF; }
"let"       { return T_LET; }
"namespace" { return T_NAMESPACE; }
"null"      { return T_NULL; }
"return"    { return T_RETURN; }
"switch"    { return T_SWITCH; }
"true"      { return T_TRUE; }
"while"     { return T_WHILE; }

{L}{A}* { SAVE_STR(); return T_IDENTIFIER; }

{HP}{H}+{IS}? { SAVE_STR(); return T_INT; }
{BP}{B}+{IS}? { SAVE_STR(); return T_INT; }
{OP}{O}+{IS}? { SAVE_STR(); return T_INT; }
{DP}{D}+{IS}? { SAVE_STR(); return T_INT; }
{NZ}{D}*{IS}? { SAVE_STR(); return T_INT; }
"0"{O}*{IS}?  { SAVE_STR(); return T_INT; }

{D}+{E}{FS}?            { SAVE_STR(); return T_FLOAT; }
{D}*"."{D}+{E}?{FS}?    { SAVE_STR(); return T_FLOAT; }
{D}+"."{E}?{FS}?        { SAVE_STR(); return T_FLOAT; }
{HP}{H}+{P}{FS}?        { SAVE_STR(); return T_FLOAT; }
{HP}{H}*"."{H}+{P}{FS}? { SAVE_STR(); return T_FLOAT; }
{HP}{H}+"."{P}{FS}?     { SAVE_STR(); return T_FLOAT; }

({SP}?"'"([^'\\\n]|{ES})*"'"{WS}*)+ { SAVE_STR(); return T_STRING; }
({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+   { SAVE_STR(); return T_STRING; }

"..." { return T_ELLIPSIS; }
">>=" { return T_RIGHT_ASSIGN; }
"<<=" { return T_LEFT_ASSIGN; }
"+="  { return T_ADD_ASSIGN; }
"-="  { return T_SUB_ASSIGN; }
"*="  { return T_MUL_ASSIGN; }
"/="  { return T_DIV_ASSIGN; }
"%="  { return T_MOD_ASSIGN; }
"&="  { return T_AND_ASSIGN; }
"^="  { return T_XOR_ASSIGN; }
"|="  { return T_OR_ASSIGN; }
">>"  { return T_RIGHT_OP; }
"<<"  { return T_LEFT_OP; }
"++"  { return T_INC_OP; }
"--"  { return T_DEC_OP; }
"->"  { return T_PTR_OP; }
"&&"  { return T_AND_OP; }
"||"  { return T_OR_OP; }
"<="  { return T_LE_OP; }
">="  { return T_GE_OP; }
"=="  { return T_EQ_OP; }
"!="  { return T_NE_OP; }
";"   { return ';'; }
"{"   { return '{'; }
"}"   { return '}'; }
","   { return ','; }
":"   { return ':'; }
"="   { return '='; }
"("   { return '('; }
")"   { return ')'; }
"["   { return '['; }
"]"   { return ']'; }
"."   { return '.'; }
"&"   { return '&'; }
"!"   { return '!'; }
"~"   { return '~'; }
"-"   { return '-'; }
"+"   { return '+'; }
"*"   { return '*'; }
"/"   { return '/'; }
"%"   { return '%'; }
"<"   { return '<'; }
">"   { return '>'; }
"^"   { return '^'; }
"|"   { return '|'; }
"?"   { return '?'; }

{WS}+ { /* whitespace separates tokens */ }
.     { /* discard bad characters */ }

%%
