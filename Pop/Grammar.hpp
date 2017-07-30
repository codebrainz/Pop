/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_GRAMMAR_HPP_INCLUDED
# define YY_YY_GRAMMAR_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 66 "Grammar.y" /* yacc.c:1909  */

#include <Pop/AST.hpp>
#include <Pop/ParseState.hpp>

#define YY_EXTRA_TYPE Pop::ParseState*

using namespace Pop;

#line 53 "Grammar.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_BREAK = 258,
    T_CASE = 259,
    T_CLASS = 260,
    T_CONTINUE = 261,
    T_DEFAULT = 262,
    T_DO = 263,
    T_ELSE = 264,
    T_ENUM = 265,
    T_FOR = 266,
    T_FUNCTION = 267,
    T_GOTO = 268,
    T_IF = 269,
    T_LET = 270,
    T_NAMESPACE = 271,
    T_RETURN = 272,
    T_SWITCH = 273,
    T_WHILE = 274,
    T_ELLIPSIS = 275,
    T_RIGHT_ASSIGN = 276,
    T_LEFT_ASSIGN = 277,
    T_ADD_ASSIGN = 278,
    T_SUB_ASSIGN = 279,
    T_MUL_ASSIGN = 280,
    T_DIV_ASSIGN = 281,
    T_MOD_ASSIGN = 282,
    T_AND_ASSIGN = 283,
    T_XOR_ASSIGN = 284,
    T_OR_ASSIGN = 285,
    T_RIGHT_OP = 286,
    T_LEFT_OP = 287,
    T_INC_OP = 288,
    T_DEC_OP = 289,
    T_PTR_OP = 290,
    T_AND_OP = 291,
    T_OR_OP = 292,
    T_LE_OP = 293,
    T_GE_OP = 294,
    T_EQ_OP = 295,
    T_NE_OP = 296,
    T_NULL = 297,
    T_TRUE = 298,
    T_FALSE = 299,
    T_IDENTIFIER = 300,
    T_INT = 301,
    T_FLOAT = 302,
    T_STRING = 303,
    NO_ELSE = 304
  };
#endif
/* Tokens.  */
#define T_BREAK 258
#define T_CASE 259
#define T_CLASS 260
#define T_CONTINUE 261
#define T_DEFAULT 262
#define T_DO 263
#define T_ELSE 264
#define T_ENUM 265
#define T_FOR 266
#define T_FUNCTION 267
#define T_GOTO 268
#define T_IF 269
#define T_LET 270
#define T_NAMESPACE 271
#define T_RETURN 272
#define T_SWITCH 273
#define T_WHILE 274
#define T_ELLIPSIS 275
#define T_RIGHT_ASSIGN 276
#define T_LEFT_ASSIGN 277
#define T_ADD_ASSIGN 278
#define T_SUB_ASSIGN 279
#define T_MUL_ASSIGN 280
#define T_DIV_ASSIGN 281
#define T_MOD_ASSIGN 282
#define T_AND_ASSIGN 283
#define T_XOR_ASSIGN 284
#define T_OR_ASSIGN 285
#define T_RIGHT_OP 286
#define T_LEFT_OP 287
#define T_INC_OP 288
#define T_DEC_OP 289
#define T_PTR_OP 290
#define T_AND_OP 291
#define T_OR_OP 292
#define T_LE_OP 293
#define T_GE_OP 294
#define T_EQ_OP 295
#define T_NE_OP 296
#define T_NULL 297
#define T_TRUE 298
#define T_FALSE 299
#define T_IDENTIFIER 300
#define T_INT 301
#define T_FLOAT 302
#define T_STRING 303
#define NO_ELSE 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 7 "Grammar.y" /* yacc.c:1909  */

	int ival;
	char *sval;
	Pop::Node *nval;

#line 169 "Grammar.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (Pop::ParseState *state);

#endif /* !YY_YY_GRAMMAR_HPP_INCLUDED  */
