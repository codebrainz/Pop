/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "Grammar.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Grammar.hpp".  */
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
#line 66 "Grammar.y" /* yacc.c:355  */

#include <Pop/AST.hpp>
#include <Pop/ParseState.hpp>

#define YY_EXTRA_TYPE Pop::ParseState*

using namespace Pop;

#line 106 "Grammar.cpp" /* yacc.c:355  */

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
#line 7 "Grammar.y" /* yacc.c:355  */

	int ival;
	char *sval;
	Pop::Node *nval;

#line 222 "Grammar.cpp" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */
#line 75 "Grammar.y" /* yacc.c:358  */

#include <Pop/Compiler.hpp>
#include <Pop/Lexer.hpp>
#include <Pop/Operators.hpp>
#include <Pop/Utils.hpp>

using namespace Pop;

void yyerror(YYLTYPE *locp, ParseState *state, const char *err) {
  state->cmp.log.error(state->file, locp->first_line, locp->first_column, err);
}

#define scanner state->scanner

#define mknode(T, loc, ...) \
	Pop::make_node<T>(state->file, loc.first_line, loc.first_column, ##__VA_ARGS__)

#define list_append(lst, elem) \
	dynamic_cast<NodeList*>(lst)->append_take(elem)


#line 273 "Grammar.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  78
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   921

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  229

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,     2,     2,    65,    68,     2,
      52,    53,    63,    59,    51,    60,    58,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    72,    73,
      66,    50,    67,    71,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,    69,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,    70,    55,    62,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   104,   105,   109,   110,   114,   115,   116,
     117,   121,   122,   123,   124,   136,   148,   149,   153,   154,
     155,   159,   160,   164,   165,   166,   167,   168,   174,   175,
     179,   180,   181,   182,   183,   184,   185,   189,   190,   191,
     192,   196,   197,   198,   202,   203,   204,   208,   209,   210,
     211,   212,   216,   217,   218,   222,   223,   227,   228,   232,
     233,   237,   238,   242,   243,   247,   248,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   267,
     271,   272,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   288,   292,   297,   301,   302,   303,   304,   308,   309,
     313,   314,   315,   316,   320,   321,   325,   326,   327,   328,
     332,   333,   337,   338,   342,   348,   356,   363,   370,   376,
     387,   388
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_BREAK", "T_CASE", "T_CLASS",
  "T_CONTINUE", "T_DEFAULT", "T_DO", "T_ELSE", "T_ENUM", "T_FOR",
  "T_FUNCTION", "T_GOTO", "T_IF", "T_LET", "T_NAMESPACE", "T_RETURN",
  "T_SWITCH", "T_WHILE", "T_ELLIPSIS", "T_RIGHT_ASSIGN", "T_LEFT_ASSIGN",
  "T_ADD_ASSIGN", "T_SUB_ASSIGN", "T_MUL_ASSIGN", "T_DIV_ASSIGN",
  "T_MOD_ASSIGN", "T_AND_ASSIGN", "T_XOR_ASSIGN", "T_OR_ASSIGN",
  "T_RIGHT_OP", "T_LEFT_OP", "T_INC_OP", "T_DEC_OP", "T_PTR_OP",
  "T_AND_OP", "T_OR_OP", "T_LE_OP", "T_GE_OP", "T_EQ_OP", "T_NE_OP",
  "T_NULL", "T_TRUE", "T_FALSE", "T_IDENTIFIER", "T_INT", "T_FLOAT",
  "T_STRING", "NO_ELSE", "'='", "','", "'('", "')'", "'{'", "'}'", "'['",
  "']'", "'.'", "'+'", "'-'", "'!'", "'~'", "'*'", "'/'", "'%'", "'<'",
  "'>'", "'&'", "'^'", "'|'", "'?'", "':'", "';'", "$accept", "start",
  "param_decl", "param_list", "func_expr", "constant", "prim_expr",
  "arg_list", "post_expr", "unary_expr", "mul_expr", "add_expr",
  "shift_expr", "rel_expr", "eq_expr", "and_expr", "xor_expr", "or_expr",
  "log_and_expr", "log_or_expr", "cond_expr", "assign_expr", "expr",
  "stmts", "stmt", "expr_stmt", "block_stmt", "case_stmt", "case_list",
  "sel_stmt", "iter_stmt", "jump_stmt", "class_field", "class_fields",
  "class_decl", "func_decl", "var_decl", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      61,    44,    40,    41,   123,   125,    91,    93,    46,    43,
      45,    33,   126,    42,    47,    37,    60,    62,    38,    94,
     124,    63,    58,    59
};
# endif

#define YYPACT_NINF -114

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-114)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     813,   -48,   -12,   -21,   813,   -28,    19,    28,    20,    26,
      42,   859,   859,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
     859,   213,   859,   859,   859,   859,  -114,    98,  -114,  -114,
    -114,    43,    62,   -27,   -41,     9,   -23,    10,    32,    40,
      41,    74,   -32,  -114,  -114,    75,   813,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,    59,  -114,    97,
      95,   -33,   859,    99,   100,  -114,    77,   859,   859,  -114,
    -114,   101,  -114,   273,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,   836,   859,   106,   859,   859,   859,   859,   859,   859,
     859,   859,   859,   859,   859,   859,   859,   859,   859,   859,
     859,   859,   859,   859,   859,   859,   859,   859,   859,   859,
     859,   859,   859,   859,  -114,  -114,    -6,   103,   -31,   108,
     102,  -114,   -30,   107,   859,  -114,   109,   110,  -114,  -114,
    -114,   -25,  -114,    96,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
     -27,   -27,   -41,   -41,     9,     9,     9,     9,   -23,   -23,
      10,    32,    40,    41,    74,    87,   116,  -114,  -114,    15,
    -114,  -114,   859,   112,   -22,   859,   333,   119,   113,   813,
     111,   115,   813,   859,  -114,  -114,   859,  -114,  -114,   117,
     393,   118,  -114,  -114,   453,  -114,   513,   164,  -114,     3,
    -114,  -114,  -114,  -114,  -114,   573,   633,  -114,  -114,   693,
     813,   859,   114,  -114,  -114,     4,  -114,  -114,   753,  -114,
    -114,   120,   813,  -114,  -114,  -114,   813,   813,   813
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,    13,    17,    14,    15,    16,
       0,     0,     0,     0,     0,     0,    90,     0,    20,    18,
      23,    30,    37,    41,    44,    47,    52,    55,    57,    59,
      61,    63,    65,    67,    79,     0,     2,    80,    82,    83,
      88,    87,    86,    89,    84,    85,   107,     0,   106,     0,
       0,     0,     0,   120,     0,   108,     0,     0,     0,    31,
      32,     0,    92,     0,    33,    34,    35,    36,     1,    28,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    81,     0,     0,     0,     3,
       0,     5,     0,     0,     0,   109,     0,     0,    19,    93,
      25,     0,    21,     0,    27,    75,    74,    69,    70,    71,
      72,    73,    76,    77,    78,    68,    38,    39,    40,    37,
      42,    43,    46,    45,    50,    51,    48,    49,    53,    54,
      56,    58,    60,    62,    64,     0,     0,   114,   112,     0,
     111,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,    24,     0,   115,   113,     0,
       0,     0,     4,    10,     0,     6,     0,   100,   121,     0,
     104,    22,    66,   105,   119,     0,     0,     9,     7,     0,
       0,     0,     0,   103,    98,     0,   117,   116,     0,     8,
     101,     0,    96,   102,    99,   118,    94,    97,    95
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -114,  -114,    -3,    61,  -114,  -114,  -114,  -114,  -114,    23,
      -2,     7,     0,     8,    72,    73,    71,    78,    76,  -114,
      -1,    52,    -7,   -19,    -4,  -114,  -114,   -24,  -114,  -114,
    -114,  -114,    14,  -114,  -114,  -113,  -112
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    27,   121,   122,    28,    29,    30,   131,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,   214,   215,    50,
      51,    52,   168,   169,    53,    54,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      59,    66,    73,   170,   171,   112,   166,   211,   211,     7,
     212,   212,   119,    71,   119,   102,   103,    60,    98,    99,
     120,   177,   173,   178,    61,    56,   183,   166,   184,   177,
       7,   191,    64,    57,    69,    70,    95,    96,    97,   113,
     100,   101,   115,   104,   105,    74,    75,    76,    77,   167,
     106,   107,    58,    11,    12,   123,   170,   171,   213,   223,
     126,   127,    13,    14,    15,    16,    17,    18,    19,   115,
     187,    62,    20,    63,   132,   133,    79,    80,    67,    22,
      23,    24,    25,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    65,    68,    81,   150,   151,    78,    82,
     108,    83,   154,   155,   156,   157,   165,   152,   153,   109,
     111,   110,    94,   116,   158,   159,   117,   180,   146,   147,
     148,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   118,   114,   124,
     125,   134,    61,   185,   128,   172,   176,   194,   175,   186,
     179,    60,   181,   182,   119,   189,   190,   196,   192,   199,
     203,   205,   206,   210,   195,   197,   201,   209,   200,   174,
     160,   162,   161,   188,   198,   202,   222,   218,   164,   163,
     115,   224,   226,     0,     0,     0,     0,     0,     0,     0,
       0,   115,     0,   227,   221,   115,   220,   228,     0,   149,
       0,     0,     0,     0,   115,     0,     1,     0,     2,     3,
       0,     4,     0,   115,   115,     5,     0,     6,     7,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,    20,     0,    21,    72,     0,
       0,     0,    22,    23,    24,    25,     1,     0,     2,     3,
       0,     4,     0,     0,     0,     5,    26,     6,     7,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,    20,     0,    21,   129,     0,
       0,     0,    22,    23,    24,    25,     1,     0,     2,     3,
       0,     4,     0,     0,     0,     5,    26,     6,     7,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,    20,     0,    21,   193,     0,
       0,     0,    22,    23,    24,    25,     1,     0,     2,     3,
       0,     4,     0,     0,     0,     5,    26,     6,     7,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,    20,     0,    21,   204,     0,
       0,     0,    22,    23,    24,    25,     1,     0,     2,     3,
       0,     4,     0,     0,     0,     5,    26,     6,     7,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,    20,     0,    21,   207,     0,
       0,     0,    22,    23,    24,    25,     1,     0,     2,     3,
       0,     4,     0,     0,     0,     5,    26,     6,     7,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,    20,     0,    21,   208,     0,
       0,     0,    22,    23,    24,    25,     1,     0,     2,     3,
       0,     4,     0,     0,     0,     5,    26,     6,     7,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,    20,     0,    21,   216,     0,
       0,     0,    22,    23,    24,    25,     1,     0,     2,     3,
       0,     4,     0,     0,     0,     5,    26,     6,     7,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,    20,     0,    21,   217,     0,
       0,     0,    22,    23,    24,    25,     1,     0,     2,     3,
       0,     4,     0,     0,     0,     5,    26,     6,     7,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,    20,     0,    21,   219,     0,
       0,     0,    22,    23,    24,    25,     1,     0,     2,     3,
       0,     4,     0,     0,     0,     5,    26,     6,     7,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,    20,     0,    21,   225,     0,
       0,     0,    22,    23,    24,    25,     1,     0,     2,     3,
       0,     4,     0,     0,     0,     5,    26,     6,     7,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,    64,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,    20,     0,    21,     0,    11,
      12,    64,    22,    23,    24,    25,     0,     0,    13,    14,
      15,    16,    17,    18,    19,     0,    26,     0,    20,   130,
       0,     0,    11,    12,     0,    22,    23,    24,    25,     0,
       0,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,    20,     0,     0,     0,     0,     0,     0,    22,    23,
      24,    25
};

static const yytype_int16 yycheck[] =
{
       4,     8,    21,   116,   116,    37,    12,     4,     4,    15,
       7,     7,    45,    20,    45,    38,    39,    45,    59,    60,
      53,    51,    53,    53,    52,    73,    51,    12,    53,    51,
      15,    53,    12,    45,    11,    12,    63,    64,    65,    71,
      31,    32,    46,    66,    67,    22,    23,    24,    25,    55,
      40,    41,    73,    33,    34,    62,   169,   169,    55,    55,
      67,    68,    42,    43,    44,    45,    46,    47,    48,    73,
      55,    52,    52,    45,    81,    82,    33,    34,    52,    59,
      60,    61,    62,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    73,    52,    52,    98,    99,     0,    56,
      68,    58,   102,   103,   104,   105,   113,   100,   101,    69,
      36,    70,    50,    54,   106,   107,    19,   124,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    52,    73,    50,
      73,    45,    52,    57,    53,    52,    54,   176,    50,    72,
      53,    45,    53,    53,    45,   172,    54,    54,   175,    54,
      53,   190,    54,     9,   177,   179,   183,   196,   182,   118,
     108,   110,   109,   169,    73,   186,    72,   206,   112,   111,
     194,   215,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,    -1,   222,   211,   209,   210,   226,    -1,   186,
      -1,    -1,    -1,    -1,   218,    -1,     3,    -1,     5,     6,
      -1,     8,    -1,   227,   228,    12,    -1,    14,    15,    -1,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    62,     3,    -1,     5,     6,
      -1,     8,    -1,    -1,    -1,    12,    73,    14,    15,    -1,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    62,     3,    -1,     5,     6,
      -1,     8,    -1,    -1,    -1,    12,    73,    14,    15,    -1,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    62,     3,    -1,     5,     6,
      -1,     8,    -1,    -1,    -1,    12,    73,    14,    15,    -1,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    62,     3,    -1,     5,     6,
      -1,     8,    -1,    -1,    -1,    12,    73,    14,    15,    -1,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    62,     3,    -1,     5,     6,
      -1,     8,    -1,    -1,    -1,    12,    73,    14,    15,    -1,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    62,     3,    -1,     5,     6,
      -1,     8,    -1,    -1,    -1,    12,    73,    14,    15,    -1,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    62,     3,    -1,     5,     6,
      -1,     8,    -1,    -1,    -1,    12,    73,    14,    15,    -1,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    62,     3,    -1,     5,     6,
      -1,     8,    -1,    -1,    -1,    12,    73,    14,    15,    -1,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    62,     3,    -1,     5,     6,
      -1,     8,    -1,    -1,    -1,    12,    73,    14,    15,    -1,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    62,     3,    -1,     5,     6,
      -1,     8,    -1,    -1,    -1,    12,    73,    14,    15,    -1,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    -1,    54,    -1,    33,
      34,    12,    59,    60,    61,    62,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    -1,    73,    -1,    52,    53,
      -1,    -1,    33,    34,    -1,    59,    60,    61,    62,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     8,    12,    14,    15,    17,    18,
      19,    33,    34,    42,    43,    44,    45,    46,    47,    48,
      52,    54,    59,    60,    61,    62,    73,    75,    78,    79,
      80,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     103,   104,   105,   108,   109,   110,    73,    45,    73,    98,
      45,    52,    52,    45,    12,    73,    96,    52,    52,    83,
      83,    96,    55,    97,    83,    83,    83,    83,     0,    33,
      34,    52,    56,    58,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    50,    63,    64,    65,    59,    60,
      31,    32,    38,    39,    66,    67,    40,    41,    68,    69,
      70,    36,    37,    71,    73,    98,    54,    19,    52,    45,
      53,    76,    77,    96,    50,    73,    96,    96,    53,    55,
      53,    81,    96,    96,    45,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    83,    83,    83,    83,
      84,    84,    85,    85,    86,    86,    86,    86,    87,    87,
      88,    89,    90,    91,    92,    96,    12,    55,   106,   107,
     109,   110,    52,    53,    77,    50,    54,    51,    53,    53,
      96,    53,    53,    51,    53,    57,    72,    55,   106,    96,
      54,    53,    96,    55,    97,    76,    54,    98,    73,    54,
      98,    96,    94,    53,    55,    97,    54,    55,    55,    97,
       9,     4,     7,    55,   101,   102,    55,    55,    97,    55,
      98,    96,    72,    55,   101,    55,    72,    97,    97
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    77,    77,    78,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    80,    80,
      80,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      83,    83,    83,    83,    83,    83,    83,    84,    84,    84,
      84,    85,    85,    85,    86,    86,    86,    87,    87,    87,
      87,    87,    88,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    96,
      97,    97,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,   100,   100,   101,   101,   101,   101,   102,   102,
     103,   103,   103,   103,   104,   104,   105,   105,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   109,   109,
     110,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     3,     6,     7,     6,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     3,     1,     4,     3,     4,     3,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     3,     4,     2,     3,     1,     2,
       5,     7,     7,     6,     5,     6,     2,     2,     2,     3,
       1,     1,     1,     2,     4,     5,     7,     7,     8,     6,
       2,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, state, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, state); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, Pop::ParseState *state)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (state);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, Pop::ParseState *state)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, state);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, Pop::ParseState *state)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , state);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, state); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, Pop::ParseState *state)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (state);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 45: /* T_IDENTIFIER  */
#line 60 "Grammar.y" /* yacc.c:1257  */
      { free(((*yyvaluep).sval)); }
#line 1479 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 46: /* T_INT  */
#line 60 "Grammar.y" /* yacc.c:1257  */
      { free(((*yyvaluep).sval)); }
#line 1485 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 47: /* T_FLOAT  */
#line 60 "Grammar.y" /* yacc.c:1257  */
      { free(((*yyvaluep).sval)); }
#line 1491 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 48: /* T_STRING  */
#line 60 "Grammar.y" /* yacc.c:1257  */
      { free(((*yyvaluep).sval)); }
#line 1497 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 76: /* param_decl  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1503 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 77: /* param_list  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1509 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 78: /* func_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1515 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 79: /* constant  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1521 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 80: /* prim_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1527 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 81: /* arg_list  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1533 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 82: /* post_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1539 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 83: /* unary_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1545 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 84: /* mul_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1551 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 85: /* add_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1557 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 86: /* shift_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1563 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 87: /* rel_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1569 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 88: /* eq_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1575 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 89: /* and_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1581 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 90: /* xor_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1587 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 91: /* or_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1593 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 92: /* log_and_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1599 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 93: /* log_or_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1605 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 94: /* cond_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1611 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 95: /* assign_expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1617 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 96: /* expr  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1623 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 97: /* stmts  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1629 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 98: /* stmt  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1635 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 99: /* expr_stmt  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1641 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 100: /* block_stmt  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1647 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 101: /* case_stmt  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1653 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 102: /* case_list  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1659 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 103: /* sel_stmt  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1665 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 104: /* iter_stmt  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1671 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 105: /* jump_stmt  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1677 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 106: /* class_field  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1683 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 107: /* class_fields  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1689 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 108: /* class_decl  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1695 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 109: /* func_decl  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1701 "Grammar.cpp" /* yacc.c:1257  */
        break;

    case 110: /* var_decl  */
#line 61 "Grammar.y" /* yacc.c:1257  */
      { Pop::node_unref(((*yyvaluep).nval)); }
#line 1707 "Grammar.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (Pop::ParseState *state)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 100 "Grammar.y" /* yacc.c:1646  */
    { state->roots = (yyvsp[0].nval); }
#line 2001 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 104 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Variable, (yylsp[0]), (yyvsp[0].sval), nullptr); free((yyvsp[0].sval)); }
#line 2007 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 105 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Variable, (yylsp[-2]), (yyvsp[-2].sval), (yyvsp[0].nval)); free((yyvsp[-2].sval)); }
#line 2013 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 109 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(NodeList, (yylsp[0]), (yyvsp[0].nval)); }
#line 2019 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 110 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[-2].nval); list_append((yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2025 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 114 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Function, (yylsp[-5]), (yyvsp[-3].nval), nullptr); }
#line 2031 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 115 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Function, (yylsp[-6]), (yyvsp[-4].nval), (yyvsp[-1].nval)); }
#line 2037 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 116 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Function, (yylsp[-5]), nullptr, (yyvsp[-1].nval)); }
#line 2043 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 117 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Function, (yylsp[-4]), nullptr, nullptr); }
#line 2049 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 121 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Null, (yylsp[0])); }
#line 2055 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 122 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Bool, (yylsp[0]), true); }
#line 2061 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 123 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Bool, (yylsp[0]), false); }
#line 2067 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 125 "Grammar.y" /* yacc.c:1646  */
    {
			try {
				long long int val = Pop::parse_int((yyvsp[0].sval));
				(yyval.nval) = mknode(Int, (yylsp[0]), val);
				free((yyvsp[0].sval));
			} catch (...) {
				state->cmp.log.error(state->file, (yylsp[0]).first_line, (yylsp[0]).first_column,
					"invalid integer literal '%'", (yyvsp[0].sval));
				free((yyvsp[0].sval));
			}
		}
#line 2083 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 137 "Grammar.y" /* yacc.c:1646  */
    {
			try {
				long double val = Pop::parse_float((yyvsp[0].sval));
				(yyval.nval) = mknode(Float, (yylsp[0]), val);
				free((yyvsp[0].sval));
			} catch (...) {
				state->cmp.log.error(state->file, (yylsp[0]).first_line, (yylsp[0]).first_column,
					"invalid floating-point literal '%s'", (yyvsp[0].sval));
				free((yyvsp[0].sval));
			}
		}
#line 2099 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 148 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(String, (yylsp[0]), (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 2105 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 149 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Symbol, (yylsp[0]), (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 2111 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 153 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2117 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 154 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[-1].nval); }
#line 2123 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 155 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2129 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 159 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(NodeList, (yylsp[0]), (yyvsp[0].nval)); }
#line 2135 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 160 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[-2].nval); list_append((yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2141 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 164 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2147 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 165 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-3]), Operator::INDEX, (yyvsp[-3].nval), (yyvsp[-1].nval)); }
#line 2153 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 166 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Call, (yylsp[-2]), (yyvsp[-2].nval), nullptr); }
#line 2159 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 167 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Call, (yylsp[-3]), (yyvsp[-3].nval), (yyvsp[-1].nval)); }
#line 2165 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 169 "Grammar.y" /* yacc.c:1646  */
    {
			Node *id = mknode(Symbol, (yylsp[0]), (yyvsp[0].sval));
			(yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::MEMBER, (yyvsp[-2].nval), id);
			free((yyvsp[0].sval));
		}
#line 2175 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 174 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Unary, (yylsp[-1]), Operator::POSTINC, (yyvsp[-1].nval)); }
#line 2181 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 175 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Unary, (yylsp[-1]), Operator::POSTDEC, (yyvsp[-1].nval)); }
#line 2187 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 179 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2193 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 180 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Unary, (yylsp[-1]), Operator::PREINC, (yyvsp[0].nval)); }
#line 2199 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 181 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Unary, (yylsp[-1]), Operator::PREDEC, (yyvsp[0].nval)); }
#line 2205 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 182 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Unary, (yylsp[-1]), Operator::POS, (yyvsp[0].nval)); }
#line 2211 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 183 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Unary, (yylsp[-1]), Operator::NEG, (yyvsp[0].nval)); }
#line 2217 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 184 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Unary, (yylsp[-1]), Operator::NOT, (yyvsp[0].nval)); }
#line 2223 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 185 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Unary, (yylsp[-1]), Operator::COMPL, (yyvsp[0].nval)); }
#line 2229 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 189 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2235 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 190 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::MUL, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2241 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 191 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::DIV, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2247 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 192 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::MOD, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2253 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 196 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2259 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 197 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::ADD, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2265 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 198 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::SUB, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2271 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 202 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2277 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 203 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::LSHIFT, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2283 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 204 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::RSHIFT, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2289 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 208 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2295 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 209 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::LT, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2301 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 210 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::GT, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2307 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 211 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::LE, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2313 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 212 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::GE, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2319 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 216 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2325 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 217 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::EQ, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2331 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 218 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::NE, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2337 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 222 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2343 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 223 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::BAND, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2349 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 227 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2355 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 228 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::BXOR, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2361 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 232 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2367 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 233 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::BOR, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2373 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 237 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2379 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 238 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::LAND, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2385 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 242 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2391 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 243 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::LOR, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2397 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 247 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2403 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 248 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(IfExpr, (yylsp[-4]), (yyvsp[-4].nval), (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2409 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 252 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2415 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 253 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::ASSIGN, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2421 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 254 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::ADD_ASSIGN, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2427 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 255 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::SUB_ASSIGN, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2433 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 256 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::MUL_ASSIGN, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2439 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 257 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::DIV_ASSIGN, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2445 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 258 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::MOD_ASSIGN, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2451 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 259 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::LSHIFT_ASSIGN, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2457 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 260 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::RSHIFT_ASSIGN, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2463 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 261 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::AND_ASSIGN, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2469 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 262 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::XOR_ASSIGN, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2475 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 263 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Binary, (yylsp[-2]), Operator::OR_ASSIGN, (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2481 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 267 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2487 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 271 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(NodeList, (yylsp[0]), (yyvsp[0].nval)); }
#line 2493 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 272 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[-1].nval); list_append((yyvsp[-1].nval), (yyvsp[0].nval)); }
#line 2499 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 276 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2505 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 277 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2511 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 278 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2517 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 279 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2523 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 280 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2529 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 281 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2535 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 282 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2541 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 283 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2547 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 284 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(EmptyStmt, (yylsp[0])); }
#line 2553 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 288 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(ExprStmt, (yylsp[-1]), (yyvsp[-1].nval)); }
#line 2559 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 293 "Grammar.y" /* yacc.c:1646  */
    {
			Node *s = mknode(NodeList, (yylsp[-1]));
			(yyval.nval) = mknode(Block, (yylsp[-1]), s);
		}
#line 2568 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 297 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Block, (yylsp[-2]), (yyvsp[-1].nval)); }
#line 2574 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 301 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Case, (yylsp[-2]), (yyvsp[-1].nval), nullptr); }
#line 2580 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 302 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Case, (yylsp[-3]), (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2586 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 303 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Case, (yylsp[-1]), nullptr, nullptr); }
#line 2592 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 304 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Case, (yylsp[-2]), nullptr, (yyvsp[0].nval)); }
#line 2598 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 308 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(NodeList, (yylsp[0]), (yyvsp[0].nval)); }
#line 2604 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 309 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[-1].nval); list_append((yyvsp[-1].nval), (yyvsp[0].nval)); }
#line 2610 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 313 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(IfStmt, (yylsp[-4]), (yyvsp[-2].nval), (yyvsp[0].nval), nullptr); }
#line 2616 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 314 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(IfStmt, (yylsp[-6]), (yyvsp[-4].nval), (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2622 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 315 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Switch, (yylsp[-6]), (yyvsp[-4].nval), (yyvsp[-1].nval)); }
#line 2628 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 316 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Switch, (yylsp[-5]), (yyvsp[-3].nval), nullptr); }
#line 2634 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 320 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(While, (yylsp[-4]), (yyvsp[-2].nval), (yyvsp[0].nval)); }
#line 2640 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 321 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Do, (yylsp[-5]), (yyvsp[-4].nval), (yyvsp[-1].nval)); }
#line 2646 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 325 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Continue, (yylsp[-1])); }
#line 2652 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 326 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Break, (yylsp[-1])); }
#line 2658 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 327 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Return, (yylsp[-1]), nullptr); }
#line 2664 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 328 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Return, (yylsp[-2]), (yyvsp[-1].nval)); }
#line 2670 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 332 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2676 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 333 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[0].nval); }
#line 2682 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 337 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(NodeList, (yylsp[0]), (yyvsp[0].nval));}
#line 2688 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 338 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = (yyvsp[-1].nval); list_append((yyval.nval), (yyvsp[0].nval)); }
#line 2694 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 343 "Grammar.y" /* yacc.c:1646  */
    {
			Node *m = mknode(NodeList, (yylsp[-1]));
			(yyval.nval) = mknode(Class, (yylsp[-3]), (yyvsp[-2].sval), m);
			free((yyvsp[-2].sval));
		}
#line 2704 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 349 "Grammar.y" /* yacc.c:1646  */
    {
			(yyval.nval) = mknode(Class, (yylsp[-4]), (yyvsp[-3].sval), (yyvsp[-1].nval));
			free((yyvsp[-3].sval));
		}
#line 2713 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 357 "Grammar.y" /* yacc.c:1646  */
    {
			Node *body = mknode(NodeList, (yylsp[-1]));
			Node *fnc = mknode(Function, (yylsp[-6]), (yyvsp[-3].nval), body);
			(yyval.nval) = mknode(Variable, (yylsp[-6]), (yyvsp[-5].sval), fnc);
			free((yyvsp[-5].sval));
		}
#line 2724 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 364 "Grammar.y" /* yacc.c:1646  */
    {
			Node *params = mknode(NodeList, (yylsp[-4]));
			Node *fnc = mknode(Function, (yylsp[-6]), params, (yyvsp[-1].nval));
			(yyval.nval) = mknode(Variable, (yylsp[-6]), (yyvsp[-5].sval), fnc);
			free((yyvsp[-5].sval));
		}
#line 2735 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 371 "Grammar.y" /* yacc.c:1646  */
    {
			Node *fnc = mknode(Function, (yylsp[-7]), (yyvsp[-4].nval), (yyvsp[-1].nval));
			(yyval.nval) = mknode(Variable, (yylsp[-7]), (yyvsp[-6].sval), fnc);
			free((yyvsp[-6].sval));
		}
#line 2745 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 377 "Grammar.y" /* yacc.c:1646  */
    {
			Node *params = mknode(NodeList, (yylsp[-3]));
			Node *body = mknode(NodeList, (yylsp[-1]));
			Node *fnc = mknode(Function, (yylsp[-5]), params, body);
			(yyval.nval) = mknode(Variable, (yylsp[-5]), (yyvsp[-4].sval), fnc);
			free((yyvsp[-4].sval));
		}
#line 2757 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 387 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Variable, (yylsp[-1]), (yyvsp[0].sval), nullptr); free((yyvsp[0].sval)); }
#line 2763 "Grammar.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 388 "Grammar.y" /* yacc.c:1646  */
    { (yyval.nval) = mknode(Variable, (yylsp[-4]), (yyvsp[-3].sval), (yyvsp[-1].nval)); free((yyvsp[-3].sval)); }
#line 2769 "Grammar.cpp" /* yacc.c:1646  */
    break;


#line 2773 "Grammar.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, state, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, state, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, state);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, state);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, state, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, state);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, state);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
