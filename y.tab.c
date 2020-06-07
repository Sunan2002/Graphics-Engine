/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     COMMENT = 258,
     DOUBLE = 259,
     LIGHT = 260,
     AMBIENT = 261,
     CONSTANTS = 262,
     SAVE_COORDS = 263,
     CAMERA = 264,
     SPHERE = 265,
     TORUS = 266,
     BOX = 267,
     LINE = 268,
     CS = 269,
     MESH = 270,
     TEXTURE = 271,
     CYLINDER = 272,
     STRING = 273,
     SET = 274,
     MOVE = 275,
     SCALE = 276,
     ROTATE = 277,
     BASENAME = 278,
     SAVE_KNOBS = 279,
     TWEEN = 280,
     FRAMES = 281,
     VARY = 282,
     PUSH = 283,
     POP = 284,
     SAVE = 285,
     GENERATE_RAYFILES = 286,
     SHADING = 287,
     SHADING_TYPE = 288,
     SETKNOBS = 289,
     FOCAL = 290,
     DISPLAY = 291,
     WEB = 292,
     CO = 293
   };
#endif
/* Tokens.  */
#define COMMENT 258
#define DOUBLE 259
#define LIGHT 260
#define AMBIENT 261
#define CONSTANTS 262
#define SAVE_COORDS 263
#define CAMERA 264
#define SPHERE 265
#define TORUS 266
#define BOX 267
#define LINE 268
#define CS 269
#define MESH 270
#define TEXTURE 271
#define CYLINDER 272
#define STRING 273
#define SET 274
#define MOVE 275
#define SCALE 276
#define ROTATE 277
#define BASENAME 278
#define SAVE_KNOBS 279
#define TWEEN 280
#define FRAMES 281
#define VARY 282
#define PUSH 283
#define POP 284
#define SAVE 285
#define GENERATE_RAYFILES 286
#define SHADING 287
#define SHADING_TYPE 288
#define SETKNOBS 289
#define FOCAL 290
#define DISPLAY 291
#define WEB 292
#define CO 293




/* Copy the first part of user declarations.  */
#line 1 "mdl.y"

  /* C declarations */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "parser.h"
  #include "matrix.h"

  #define YYERROR_VERBOSE 1

  SYMTAB *s;
  struct light *l;
  struct constants *c;
  struct command op[MAX_COMMANDS];
  struct matrix *m;
  int lastop=0;
  int lineno=0;

  

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 24 "mdl.y"
{
  double val;
  char string[255];
}
/* Line 193 of yacc.c.  */
#line 197 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 210 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  3
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNRULES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    15,    22,    29,    37,
      44,    52,    60,    69,    76,    84,    92,   101,   109,   118,
     127,   137,   145,   154,   163,   173,   182,   192,   202,   213,
     217,   222,   228,   234,   239,   245,   250,   255,   259,   261,
     263,   265,   268,   277,   289,   304,   307,   315,   330,   334,
     337,   340,   346,   349,   356,   359,   362,   365,   367,   372
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    -1,    40,    41,    -1,     3,    -1,    10,
       4,     4,     4,     4,    -1,    10,     4,     4,     4,     4,
      18,    -1,    10,    18,     4,     4,     4,     4,    -1,    10,
      18,     4,     4,     4,     4,    18,    -1,    11,     4,     4,
       4,     4,     4,    -1,    11,     4,     4,     4,     4,     4,
      18,    -1,    11,    18,     4,     4,     4,     4,     4,    -1,
      11,    18,     4,     4,     4,     4,     4,    18,    -1,    17,
       4,     4,     4,     4,     4,    -1,    17,     4,     4,     4,
       4,     4,    18,    -1,    17,    18,     4,     4,     4,     4,
       4,    -1,    17,    18,     4,     4,     4,     4,     4,    18,
      -1,    12,     4,     4,     4,     4,     4,     4,    -1,    12,
       4,     4,     4,     4,     4,     4,    18,    -1,    12,    18,
       4,     4,     4,     4,     4,     4,    -1,    12,    18,     4,
       4,     4,     4,     4,     4,    18,    -1,    13,     4,     4,
       4,     4,     4,     4,    -1,    13,     4,     4,     4,    18,
       4,     4,     4,    -1,    13,     4,     4,     4,     4,     4,
       4,    18,    -1,    13,     4,     4,     4,    18,     4,     4,
       4,    18,    -1,    13,    18,     4,     4,     4,     4,     4,
       4,    -1,    13,    18,     4,     4,     4,    18,     4,     4,
       4,    -1,    13,    18,     4,     4,     4,     4,     4,     4,
      18,    -1,    13,    18,     4,     4,     4,    18,     4,     4,
       4,    18,    -1,    15,    38,    18,    -1,    15,    18,    38,
      18,    -1,    15,    18,    38,    18,    18,    -1,    20,     4,
       4,     4,    18,    -1,    20,     4,     4,     4,    -1,    21,
       4,     4,     4,    18,    -1,    21,     4,     4,     4,    -1,
      22,    18,     4,    18,    -1,    22,    18,     4,    -1,    28,
      -1,    29,    -1,    36,    -1,    30,    18,    -1,     5,    18,
       4,     4,     4,     4,     4,     4,    -1,     7,    18,     4,
       4,     4,     4,     4,     4,     4,     4,     4,    -1,     7,
      18,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,    -1,     8,    18,    -1,     9,     4,     4,
       4,     4,     4,     4,    -1,    16,    18,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,    -1,
      19,    18,     4,    -1,    23,    18,    -1,    24,    18,    -1,
      25,     4,     4,    18,    18,    -1,    26,     4,    -1,    27,
      18,     4,     4,     4,     4,    -1,    32,    33,    -1,    34,
       4,    -1,    35,     4,    -1,    37,    -1,     6,     4,     4,
       4,    -1,    31,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    42,    42,    43,    48,    50,    63,    77,    91,   108,
     123,   138,   154,   172,   187,   202,   218,   236,   253,   271,
     288,   308,   326,   344,   362,   382,   400,   419,   439,   460,
     469,   479,   491,   502,   514,   525,   536,   560,   584,   591,
     598,   605,   613,   633,   661,   688,   697,   712,   735,   745,
     752,   760,   771,   779,   791,   798,   805,   813,   819,   829
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMENT", "DOUBLE", "LIGHT", "AMBIENT",
  "CONSTANTS", "SAVE_COORDS", "CAMERA", "SPHERE", "TORUS", "BOX", "LINE",
  "CS", "MESH", "TEXTURE", "CYLINDER", "STRING", "SET", "MOVE", "SCALE",
  "ROTATE", "BASENAME", "SAVE_KNOBS", "TWEEN", "FRAMES", "VARY", "PUSH",
  "POP", "SAVE", "GENERATE_RAYFILES", "SHADING", "SHADING_TYPE",
  "SETKNOBS", "FOCAL", "DISPLAY", "WEB", "CO", "$accept", "input",
  "command", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     5,     6,     6,     7,     6,
       7,     7,     8,     6,     7,     7,     8,     7,     8,     8,
       9,     7,     8,     8,     9,     8,     9,     9,    10,     3,
       4,     5,     5,     4,     5,     4,     4,     3,     1,     1,
       1,     2,     8,    11,    14,     2,     7,    14,     3,     2,
       2,     5,     2,     6,     2,     2,     2,     1,     4,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    39,     0,    59,     0,
       0,     0,    40,    57,     3,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,    50,     0,
      52,     0,    41,    54,    55,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    48,     0,     0,    37,     0,     0,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     0,     0,     0,    33,    35,    36,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,    32,    34,    51,     0,
       0,     0,     0,     6,     7,     9,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,    53,     0,     0,    46,
       8,    10,    11,    17,     0,    21,     0,     0,     0,     0,
      14,    15,    42,     0,    12,    18,    19,    23,    22,    25,
       0,     0,    16,     0,    20,    24,    27,    26,     0,     0,
      28,     0,    43,     0,     0,     0,     0,     0,    44,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    34
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -18
static const yytype_int16 yypact[] =
{
     -18,     0,   -18,   -18,   -17,    -2,   -14,    -4,    14,    34,
      36,    37,    38,    15,    21,    39,    28,    43,    44,    31,
      32,    33,    56,    57,    45,   -18,   -18,    46,   -18,    29,
      61,    62,   -18,   -18,   -18,    63,    64,    65,   -18,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    42,    75,
      77,    78,    79,    80,    81,    82,    83,   -18,   -18,    84,
     -18,    85,   -18,   -18,   -18,   -18,    86,    87,    88,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    89,   -18,
      99,   100,   101,   -18,   102,   104,   103,   105,   106,   107,
     -18,   108,   109,   110,   111,   112,   113,   114,   115,    40,
     116,   117,   118,   120,   121,   119,   122,   -18,   123,   124,
     125,   126,   127,   128,   129,   130,   132,   134,   135,   138,
     139,    41,   -18,   140,   141,   143,   -18,   -18,   -18,   144,
     145,   146,   147,   -18,   136,   137,   148,   149,   152,   153,
     154,   155,   156,   157,   150,   158,   -18,   159,   160,   -18,
     -18,   -18,   151,   161,   162,   163,   166,   167,   168,   169,
     -18,   164,   -18,   170,   -18,   -18,   165,   -18,   171,   172,
     173,   174,   -18,   176,   -18,   -18,   -18,   175,   180,   181,
     -18,   182,   183,   184,   187,   188,   190,   191,   -18,   -18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -18,   -18,   -18
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       2,    35,    36,     3,    37,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    38,    13,    14,    15,    39,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    48,    30,    31,    32,    33,    40,    50,
      42,    44,    46,    51,   119,   141,    53,    54,    55,    56,
      57,    58,    41,    49,    43,    45,    47,    52,   120,   142,
      59,    60,    63,    61,    62,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
      78,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    79,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   102,   103,   104,   105,   101,   106,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     121,   107,   123,   108,   124,   125,     0,     0,   129,   130,
     131,   132,     0,   134,   135,   122,   136,   126,   137,   138,
     127,   128,   139,   140,   143,   144,   133,   145,   146,   147,
     148,   149,   152,   153,   150,   151,   154,   155,   156,   157,
     158,   159,   161,   162,   163,     0,   166,     0,   160,   164,
     168,   169,   170,   171,   173,     0,     0,   177,   178,   165,
     179,   167,   172,   174,   181,   182,   183,   184,   185,   175,
     176,   186,   187,   180,   188,   189
};

static const yytype_int8 yycheck[] =
{
       0,    18,     4,     3,    18,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    18,    15,    16,    17,     4,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    18,    34,    35,    36,    37,     4,    18,
       4,     4,     4,     4,     4,     4,    18,     4,     4,    18,
      18,    18,    18,    38,    18,    18,    18,    18,    18,    18,
       4,     4,    33,    18,    18,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,    -1,
      38,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,    18,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,    18,     4,    -1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,    18,     4,    18,     4,     4,    -1,    -1,     4,     4,
       4,     4,    -1,     4,     4,    18,     4,    18,     4,     4,
      18,    18,     4,     4,     4,     4,    18,     4,     4,     4,
       4,     4,     4,     4,    18,    18,     4,     4,     4,     4,
       4,     4,     4,     4,     4,    -1,     4,    -1,    18,    18,
       4,     4,     4,     4,     4,    -1,    -1,     4,     4,    18,
       4,    18,    18,    18,     4,     4,     4,     4,     4,    18,
      18,     4,     4,    18,     4,     4
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,     0,     3,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    15,    16,    17,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      34,    35,    36,    37,    41,    18,     4,    18,    18,     4,
       4,    18,     4,    18,     4,    18,     4,    18,    18,    38,
      18,     4,    18,    18,     4,     4,    18,    18,    18,     4,
       4,    18,    18,    33,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,    38,    18,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,    18,     4,     4,     4,     4,     4,    18,    18,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
      18,     4,    18,     4,     4,     4,    18,    18,    18,     4,
       4,     4,     4,    18,     4,     4,     4,     4,     4,     4,
       4,     4,    18,     4,     4,     4,     4,     4,     4,     4,
      18,    18,     4,     4,     4,     4,     4,     4,     4,     4,
      18,     4,     4,     4,    18,    18,     4,    18,     4,     4,
       4,     4,    18,     4,    18,    18,    18,     4,     4,     4,
      18,     4,     4,     4,     4,     4,     4,     4,     4,     4
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 48 "mdl.y"
    {}
    break;

  case 5:
#line 51 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = SPHERE;
  op[lastop].op.sphere.d[0] = (yyvsp[(2) - (5)].val);
  op[lastop].op.sphere.d[1] = (yyvsp[(3) - (5)].val);
  op[lastop].op.sphere.d[2] = (yyvsp[(4) - (5)].val);
  op[lastop].op.sphere.d[3] = 0;
  op[lastop].op.sphere.r = (yyvsp[(5) - (5)].val);
  op[lastop].op.sphere.constants = NULL;
  op[lastop].op.sphere.cs = NULL;
  lastop++;
}
    break;

  case 6:
#line 64 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = SPHERE;
  op[lastop].op.sphere.d[0] = (yyvsp[(2) - (6)].val);
  op[lastop].op.sphere.d[1] = (yyvsp[(3) - (6)].val);
  op[lastop].op.sphere.d[2] = (yyvsp[(4) - (6)].val);
  op[lastop].op.sphere.d[3] = 0;
  op[lastop].op.sphere.r = (yyvsp[(5) - (6)].val);
  op[lastop].op.sphere.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.sphere.cs = add_symbol((yyvsp[(6) - (6)].string),SYM_MATRIX,m);
  lastop++;
}
    break;

  case 7:
#line 78 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = SPHERE;
  op[lastop].op.sphere.d[0] = (yyvsp[(3) - (6)].val);
  op[lastop].op.sphere.d[1] = (yyvsp[(4) - (6)].val);
  op[lastop].op.sphere.d[2] = (yyvsp[(5) - (6)].val);
  op[lastop].op.sphere.d[3] = 0;
  op[lastop].op.sphere.r = (yyvsp[(6) - (6)].val);
  op[lastop].op.sphere.cs = NULL;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.sphere.constants = add_symbol((yyvsp[(2) - (6)].string),SYM_CONSTANTS,c);
  lastop++;
}
    break;

  case 8:
#line 92 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = SPHERE;
  op[lastop].op.sphere.d[0] = (yyvsp[(3) - (7)].val);
  op[lastop].op.sphere.d[1] = (yyvsp[(4) - (7)].val);
  op[lastop].op.sphere.d[2] = (yyvsp[(5) - (7)].val);
  op[lastop].op.sphere.d[3] = 0;
  op[lastop].op.sphere.r = (yyvsp[(6) - (7)].val);
  op[lastop].op.sphere.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.sphere.cs = add_symbol((yyvsp[(7) - (7)].string),SYM_MATRIX,m);
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.sphere.constants = add_symbol((yyvsp[(2) - (7)].string),SYM_CONSTANTS,c);
  lastop++;
}
    break;

  case 9:
#line 109 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = TORUS;
  op[lastop].op.torus.d[0] = (yyvsp[(2) - (6)].val);
  op[lastop].op.torus.d[1] = (yyvsp[(3) - (6)].val);
  op[lastop].op.torus.d[2] = (yyvsp[(4) - (6)].val);
  op[lastop].op.torus.d[3] = 0;
  op[lastop].op.torus.r0 = (yyvsp[(5) - (6)].val);
  op[lastop].op.torus.r1 = (yyvsp[(6) - (6)].val);
  op[lastop].op.torus.constants = NULL;
  op[lastop].op.torus.cs = NULL;

  lastop++;
}
    break;

  case 10:
#line 124 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = TORUS;
  op[lastop].op.torus.d[0] = (yyvsp[(2) - (7)].val);
  op[lastop].op.torus.d[1] = (yyvsp[(3) - (7)].val);
  op[lastop].op.torus.d[2] = (yyvsp[(4) - (7)].val);
  op[lastop].op.torus.d[3] = 0;
  op[lastop].op.torus.r0 = (yyvsp[(5) - (7)].val);
  op[lastop].op.torus.r1 = (yyvsp[(6) - (7)].val);
  op[lastop].op.torus.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.torus.cs = add_symbol((yyvsp[(7) - (7)].string),SYM_MATRIX,m);
  lastop++;
}
    break;

  case 11:
#line 139 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = TORUS;
  op[lastop].op.torus.d[0] = (yyvsp[(3) - (7)].val);
  op[lastop].op.torus.d[1] = (yyvsp[(4) - (7)].val);
  op[lastop].op.torus.d[2] = (yyvsp[(5) - (7)].val);
  op[lastop].op.torus.d[3] = 0;
  op[lastop].op.torus.r0 = (yyvsp[(6) - (7)].val);
  op[lastop].op.torus.r1 = (yyvsp[(7) - (7)].val);
  op[lastop].op.torus.cs = NULL;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.torus.constants = add_symbol((yyvsp[(2) - (7)].string),SYM_CONSTANTS,c);

  lastop++;
}
    break;

  case 12:
#line 155 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = TORUS;
  op[lastop].op.torus.d[0] = (yyvsp[(3) - (8)].val);
  op[lastop].op.torus.d[1] = (yyvsp[(4) - (8)].val);
  op[lastop].op.torus.d[2] = (yyvsp[(5) - (8)].val);
  op[lastop].op.torus.d[3] = 0;
  op[lastop].op.torus.r0 = (yyvsp[(6) - (8)].val);
  op[lastop].op.torus.r1 = (yyvsp[(7) - (8)].val);
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.torus.constants = add_symbol((yyvsp[(2) - (8)].string),SYM_CONSTANTS,c);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.torus.cs = add_symbol((yyvsp[(8) - (8)].string),SYM_MATRIX,m);

  lastop++;
}
    break;

  case 13:
#line 173 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = CYLINDER;
  op[lastop].op.cylinder.d[0] = (yyvsp[(2) - (6)].val);
  op[lastop].op.cylinder.d[1] = (yyvsp[(3) - (6)].val);
  op[lastop].op.cylinder.d[2] = (yyvsp[(4) - (6)].val);
  op[lastop].op.cylinder.d[3] = 0;
  op[lastop].op.cylinder.r = (yyvsp[(5) - (6)].val);
  op[lastop].op.cylinder.h = (yyvsp[(6) - (6)].val);
  op[lastop].op.cylinder.constants = NULL;
  op[lastop].op.cylinder.cs = NULL;

  lastop++;
}
    break;

  case 14:
#line 188 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = CYLINDER;
  op[lastop].op.cylinder.d[0] = (yyvsp[(2) - (7)].val);
  op[lastop].op.cylinder.d[1] = (yyvsp[(3) - (7)].val);
  op[lastop].op.cylinder.d[2] = (yyvsp[(4) - (7)].val);
  op[lastop].op.cylinder.d[3] = 0;
  op[lastop].op.cylinder.r = (yyvsp[(5) - (7)].val);
  op[lastop].op.cylinder.h = (yyvsp[(6) - (7)].val);
  op[lastop].op.cylinder.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.cylinder.cs = add_symbol((yyvsp[(7) - (7)].string),SYM_MATRIX,m);
  lastop++;
}
    break;

  case 15:
#line 203 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = CYLINDER;
  op[lastop].op.cylinder.d[0] = (yyvsp[(3) - (7)].val);
  op[lastop].op.cylinder.d[1] = (yyvsp[(4) - (7)].val);
  op[lastop].op.cylinder.d[2] = (yyvsp[(5) - (7)].val);
  op[lastop].op.cylinder.d[3] = 0;
  op[lastop].op.cylinder.r = (yyvsp[(6) - (7)].val);
  op[lastop].op.cylinder.h = (yyvsp[(7) - (7)].val);
  op[lastop].op.cylinder.cs = NULL;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.cylinder.constants = add_symbol((yyvsp[(2) - (7)].string),SYM_CONSTANTS,c);

  lastop++;
}
    break;

  case 16:
#line 219 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = CYLINDER;
  op[lastop].op.cylinder.d[0] = (yyvsp[(3) - (8)].val);
  op[lastop].op.cylinder.d[1] = (yyvsp[(4) - (8)].val);
  op[lastop].op.cylinder.d[2] = (yyvsp[(5) - (8)].val);
  op[lastop].op.cylinder.d[3] = 0;
  op[lastop].op.cylinder.r = (yyvsp[(6) - (8)].val);
  op[lastop].op.cylinder.h = (yyvsp[(7) - (8)].val);
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.cylinder.constants = add_symbol((yyvsp[(2) - (8)].string),SYM_CONSTANTS,c);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.cylinder.cs = add_symbol((yyvsp[(8) - (8)].string),SYM_MATRIX,m);

  lastop++;
}
    break;

  case 17:
#line 237 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = BOX;
  op[lastop].op.box.d0[0] = (yyvsp[(2) - (7)].val);
  op[lastop].op.box.d0[1] = (yyvsp[(3) - (7)].val);
  op[lastop].op.box.d0[2] = (yyvsp[(4) - (7)].val);
  op[lastop].op.box.d0[3] = 0;
  op[lastop].op.box.d1[0] = (yyvsp[(5) - (7)].val);
  op[lastop].op.box.d1[1] = (yyvsp[(6) - (7)].val);
  op[lastop].op.box.d1[2] = (yyvsp[(7) - (7)].val);
  op[lastop].op.box.d1[3] = 0;

  op[lastop].op.box.constants = NULL;
  op[lastop].op.box.cs = NULL;
  lastop++;
}
    break;

  case 18:
#line 254 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = BOX;
  op[lastop].op.box.d0[0] = (yyvsp[(2) - (8)].val);
  op[lastop].op.box.d0[1] = (yyvsp[(3) - (8)].val);
  op[lastop].op.box.d0[2] = (yyvsp[(4) - (8)].val);
  op[lastop].op.box.d0[3] = 0;
  op[lastop].op.box.d1[0] = (yyvsp[(5) - (8)].val);
  op[lastop].op.box.d1[1] = (yyvsp[(6) - (8)].val);
  op[lastop].op.box.d1[2] = (yyvsp[(7) - (8)].val);
  op[lastop].op.box.d1[3] = 0;

  op[lastop].op.box.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.box.cs = add_symbol((yyvsp[(8) - (8)].string),SYM_MATRIX,m);
  lastop++;
}
    break;

  case 19:
#line 272 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = BOX;
  op[lastop].op.box.d0[0] = (yyvsp[(3) - (8)].val);
  op[lastop].op.box.d0[1] = (yyvsp[(4) - (8)].val);
  op[lastop].op.box.d0[2] = (yyvsp[(5) - (8)].val);
  op[lastop].op.box.d0[3] = 0;
  op[lastop].op.box.d1[0] = (yyvsp[(6) - (8)].val);
  op[lastop].op.box.d1[1] = (yyvsp[(7) - (8)].val);
  op[lastop].op.box.d1[2] = (yyvsp[(8) - (8)].val);
  op[lastop].op.box.d1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.box.constants = add_symbol((yyvsp[(2) - (8)].string),SYM_CONSTANTS,c);
  op[lastop].op.box.cs = NULL;
  lastop++;
}
    break;

  case 20:
#line 289 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = BOX;
  op[lastop].op.box.d0[0] = (yyvsp[(3) - (9)].val);
  op[lastop].op.box.d0[1] = (yyvsp[(4) - (9)].val);
  op[lastop].op.box.d0[2] = (yyvsp[(5) - (9)].val);
  op[lastop].op.box.d0[3] = 0;
  op[lastop].op.box.d1[0] = (yyvsp[(6) - (9)].val);
  op[lastop].op.box.d1[1] = (yyvsp[(7) - (9)].val);
  op[lastop].op.box.d1[2] = (yyvsp[(8) - (9)].val);
  op[lastop].op.box.d1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.box.constants = add_symbol((yyvsp[(2) - (9)].string),SYM_CONSTANTS,c);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.box.cs = add_symbol((yyvsp[(9) - (9)].string),SYM_MATRIX,m);

  lastop++;
}
    break;

  case 21:
#line 309 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = (yyvsp[(2) - (7)].val);
  op[lastop].op.line.p0[1] = (yyvsp[(3) - (7)].val);
  op[lastop].op.line.p0[2] = (yyvsp[(4) - (7)].val);
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = (yyvsp[(5) - (7)].val);
  op[lastop].op.line.p1[1] = (yyvsp[(6) - (7)].val);
  op[lastop].op.line.p1[2] = (yyvsp[(7) - (7)].val);
  op[lastop].op.line.p1[3] = 0;
  op[lastop].op.line.constants = NULL;
  op[lastop].op.line.cs0 = NULL;
  op[lastop].op.line.cs1 = NULL;
  lastop++;
}
    break;

  case 22:
#line 327 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = (yyvsp[(2) - (8)].val);
  op[lastop].op.line.p0[1] = (yyvsp[(3) - (8)].val);
  op[lastop].op.line.p0[2] = (yyvsp[(4) - (8)].val);
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = (yyvsp[(6) - (8)].val);
  op[lastop].op.line.p1[1] = (yyvsp[(7) - (8)].val);
  op[lastop].op.line.p1[2] = (yyvsp[(8) - (8)].val);
  op[lastop].op.line.p1[3] = 0;
  op[lastop].op.line.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs0 = add_symbol((yyvsp[(5) - (8)].string),SYM_MATRIX,m);
  op[lastop].op.line.cs1 = NULL;
  lastop++;
}
    break;

  case 23:
#line 345 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = (yyvsp[(2) - (8)].val);
  op[lastop].op.line.p0[1] = (yyvsp[(3) - (8)].val);
  op[lastop].op.line.p0[2] = (yyvsp[(4) - (8)].val);
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = (yyvsp[(5) - (8)].val);
  op[lastop].op.line.p1[1] = (yyvsp[(6) - (8)].val);
  op[lastop].op.line.p1[2] = (yyvsp[(7) - (8)].val);
  op[lastop].op.line.p1[3] = 0;
  op[lastop].op.line.constants = NULL;
  op[lastop].op.line.cs0 = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs1 = add_symbol((yyvsp[(8) - (8)].string),SYM_MATRIX,m);
  lastop++;
}
    break;

  case 24:
#line 363 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = (yyvsp[(2) - (9)].val);
  op[lastop].op.line.p0[1] = (yyvsp[(3) - (9)].val);
  op[lastop].op.line.p0[2] = (yyvsp[(4) - (9)].val);
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = (yyvsp[(6) - (9)].val);
  op[lastop].op.line.p1[1] = (yyvsp[(7) - (9)].val);
  op[lastop].op.line.p1[2] = (yyvsp[(8) - (9)].val);
  op[lastop].op.line.p1[3] = 0;
  op[lastop].op.line.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs0 = add_symbol((yyvsp[(5) - (9)].string),SYM_MATRIX,m);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs1 = add_symbol((yyvsp[(9) - (9)].string),SYM_MATRIX,m);
  lastop++;
}
    break;

  case 25:
#line 383 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = (yyvsp[(3) - (8)].val);
  op[lastop].op.line.p0[1] = (yyvsp[(4) - (8)].val);
  op[lastop].op.line.p0[2] = (yyvsp[(5) - (8)].val);
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = (yyvsp[(6) - (8)].val);
  op[lastop].op.line.p1[1] = (yyvsp[(7) - (8)].val);
  op[lastop].op.line.p1[2] = (yyvsp[(8) - (8)].val);
  op[lastop].op.line.p1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.line.constants = add_symbol((yyvsp[(2) - (8)].string),SYM_CONSTANTS,c);
  op[lastop].op.line.cs0 = NULL;
  op[lastop].op.line.cs1 = NULL;
  lastop++;
}
    break;

  case 26:
#line 401 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = (yyvsp[(3) - (9)].val);
  op[lastop].op.line.p0[1] = (yyvsp[(4) - (9)].val);
  op[lastop].op.line.p0[2] = (yyvsp[(5) - (9)].val);
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = (yyvsp[(7) - (9)].val);
  op[lastop].op.line.p1[1] = (yyvsp[(8) - (9)].val);
  op[lastop].op.line.p1[2] = (yyvsp[(9) - (9)].val);
  op[lastop].op.line.p1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.line.constants = add_symbol((yyvsp[(2) - (9)].string),SYM_CONSTANTS,c);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs0 = add_symbol((yyvsp[(6) - (9)].string),SYM_MATRIX,m);
  op[lastop].op.line.cs1 = NULL;
  lastop++;
}
    break;

  case 27:
#line 420 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = (yyvsp[(3) - (9)].val);
  op[lastop].op.line.p0[1] = (yyvsp[(4) - (9)].val);
  op[lastop].op.line.p0[2] = (yyvsp[(5) - (9)].val);
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = (yyvsp[(6) - (9)].val);
  op[lastop].op.line.p1[1] = (yyvsp[(7) - (9)].val);
  op[lastop].op.line.p1[2] = (yyvsp[(8) - (9)].val);
  op[lastop].op.line.p1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.line.constants = add_symbol((yyvsp[(2) - (9)].string),SYM_CONSTANTS,c);
  op[lastop].op.line.cs0 = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs1 = add_symbol((yyvsp[(9) - (9)].string),SYM_MATRIX,m);
  op[lastop].op.line.cs0 = NULL;
  lastop++;
}
    break;

  case 28:
#line 440 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = (yyvsp[(3) - (10)].val);
  op[lastop].op.line.p0[1] = (yyvsp[(4) - (10)].val);
  op[lastop].op.line.p0[2] = (yyvsp[(5) - (10)].val);
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = (yyvsp[(7) - (10)].val);
  op[lastop].op.line.p1[1] = (yyvsp[(8) - (10)].val);
  op[lastop].op.line.p1[2] = (yyvsp[(9) - (10)].val);
  op[lastop].op.line.p1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.line.constants = add_symbol((yyvsp[(2) - (10)].string),SYM_CONSTANTS,c);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs0 = add_symbol((yyvsp[(6) - (10)].string),SYM_MATRIX,m);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs1 = add_symbol((yyvsp[(10) - (10)].string),SYM_MATRIX,m);
  lastop++;
}
    break;

  case 29:
#line 461 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = MESH;
  strcpy(op[lastop].op.mesh.name,(yyvsp[(3) - (3)].string));
  op[lastop].op.mesh.constants = NULL;
  op[lastop].op.mesh.cs = NULL;
  lastop++;
}
    break;

  case 30:
#line 470 "mdl.y"
    { /* name and constants */
  lineno++;
  op[lastop].opcode = MESH;
  strcpy(op[lastop].op.mesh.name,(yyvsp[(4) - (4)].string));
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.mesh.constants = add_symbol((yyvsp[(2) - (4)].string),SYM_CONSTANTS,c);
  op[lastop].op.mesh.cs = NULL;
  lastop++;
}
    break;

  case 31:
#line 480 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = MESH;
  strcpy(op[lastop].op.mesh.name,(yyvsp[(4) - (5)].string));
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.mesh.constants = add_symbol((yyvsp[(2) - (5)].string),SYM_CONSTANTS,c);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.mesh.cs = add_symbol((yyvsp[(5) - (5)].string),SYM_MATRIX,m);
  lastop++;
}
    break;

  case 32:
#line 492 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = MOVE;
  op[lastop].op.move.d[0] = (yyvsp[(2) - (5)].val);
  op[lastop].op.move.d[1] = (yyvsp[(3) - (5)].val);
  op[lastop].op.move.d[2] = (yyvsp[(4) - (5)].val);
  op[lastop].op.move.d[3] = 0;
  op[lastop].op.move.p = add_symbol((yyvsp[(5) - (5)].string),SYM_VALUE,0);
  lastop++;
}
    break;

  case 33:
#line 503 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = MOVE;
  op[lastop].op.move.d[0] = (yyvsp[(2) - (4)].val);
  op[lastop].op.move.d[1] = (yyvsp[(3) - (4)].val);
  op[lastop].op.move.d[2] = (yyvsp[(4) - (4)].val);
  op[lastop].op.move.d[3] = 0;
  op[lastop].op.move.p = NULL;
  lastop++;
}
    break;

  case 34:
#line 515 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = SCALE;
  op[lastop].op.scale.d[0] = (yyvsp[(2) - (5)].val);
  op[lastop].op.scale.d[1] = (yyvsp[(3) - (5)].val);
  op[lastop].op.scale.d[2] = (yyvsp[(4) - (5)].val);
  op[lastop].op.scale.d[3] = 0;
  op[lastop].op.scale.p = add_symbol((yyvsp[(5) - (5)].string),SYM_VALUE,0);
  lastop++;
}
    break;

  case 35:
#line 526 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = SCALE;
  op[lastop].op.scale.d[0] = (yyvsp[(2) - (4)].val);
  op[lastop].op.scale.d[1] = (yyvsp[(3) - (4)].val);
  op[lastop].op.scale.d[2] = (yyvsp[(4) - (4)].val);
  op[lastop].op.scale.d[3] = 0;
  op[lastop].op.scale.p = NULL;
  lastop++;
}
    break;

  case 36:
#line 537 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = ROTATE;
  switch (*(yyvsp[(2) - (4)].string))
    {
    case 'x':
    case 'X':
      op[lastop].op.rotate.axis = 0;
      break;
    case 'y':
    case 'Y':
      op[lastop].op.rotate.axis = 1;
      break;
    case 'z':
    case 'Z':
      op[lastop].op.rotate.axis = 2;
      break;
    }

  op[lastop].op.rotate.degrees = (yyvsp[(3) - (4)].val);
  op[lastop].op.rotate.p = add_symbol((yyvsp[(4) - (4)].string),SYM_VALUE,0);
  lastop++;
}
    break;

  case 37:
#line 561 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = ROTATE;
  switch (*(yyvsp[(2) - (3)].string))
    {
    case 'x':
    case 'X':
      op[lastop].op.rotate.axis = 0;
      break;
    case 'y':
    case 'Y':
      op[lastop].op.rotate.axis = 1;
      break;
    case 'z':
    case 'Z':
      op[lastop].op.rotate.axis = 2;
      break;
    }
  op[lastop].op.rotate.degrees = (yyvsp[(3) - (3)].val);
  op[lastop].op.rotate.p = NULL;
  lastop++;
}
    break;

  case 38:
#line 585 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = PUSH;
  lastop++;
}
    break;

  case 39:
#line 592 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = POP;
  lastop++;
}
    break;

  case 40:
#line 599 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = DISPLAY;
  lastop++;
}
    break;

  case 41:
#line 606 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = SAVE;
  op[lastop].op.save.p = add_symbol((yyvsp[(2) - (2)].string),SYM_FILE,0);
  lastop++;
}
    break;

  case 42:
#line 614 "mdl.y"
    {
  lineno++;
  l = (struct light *)malloc(sizeof(struct light));
  l->l[0]= (yyvsp[(3) - (8)].val);
  l->l[1]= (yyvsp[(4) - (8)].val);
  l->l[2]= (yyvsp[(5) - (8)].val);
  l->l[3]= 0;
  l->c[0]= (yyvsp[(6) - (8)].val);
  l->c[1]= (yyvsp[(7) - (8)].val);
  l->c[2]= (yyvsp[(8) - (8)].val);
  op[lastop].opcode=LIGHT;
  op[lastop].op.light.c[0] = (yyvsp[(6) - (8)].val);
  op[lastop].op.light.c[1] = (yyvsp[(7) - (8)].val);
  op[lastop].op.light.c[2] = (yyvsp[(8) - (8)].val);
  op[lastop].op.light.c[3] = 0;
  op[lastop].op.light.p = add_symbol((yyvsp[(2) - (8)].string),SYM_LIGHT,l);
  lastop++;
}
    break;

  case 43:
#line 634 "mdl.y"
    {
  lineno++;
  c = (struct constants *)malloc(sizeof(struct constants));
  c->r[0]=(yyvsp[(3) - (11)].val);
  c->r[1]=(yyvsp[(4) - (11)].val);
  c->r[2]=(yyvsp[(5) - (11)].val);
  c->r[3]=0;

  c->g[0]=(yyvsp[(6) - (11)].val);
  c->g[1]=(yyvsp[(7) - (11)].val);
  c->g[2]=(yyvsp[(8) - (11)].val);
  c->g[3]=0;

  c->b[0]=(yyvsp[(9) - (11)].val);
  c->b[1]=(yyvsp[(10) - (11)].val);
  c->b[2]=(yyvsp[(11) - (11)].val);
  c->b[3]=0;

  c->red = 0;
  c->green = 0;
  c->blue = 0;

  op[lastop].op.constants.p =  add_symbol((yyvsp[(2) - (11)].string),SYM_CONSTANTS,c);
  op[lastop].opcode=CONSTANTS;
  lastop++;
}
    break;

  case 44:
#line 662 "mdl.y"
    {
  lineno++;
  c = (struct constants *)malloc(sizeof(struct constants));
  c->r[0]=(yyvsp[(3) - (14)].val);
  c->r[1]=(yyvsp[(4) - (14)].val);
  c->r[2]=(yyvsp[(5) - (14)].val);
  c->r[3]=0;

  c->g[0]=(yyvsp[(6) - (14)].val);
  c->g[1]=(yyvsp[(7) - (14)].val);
  c->g[2]=(yyvsp[(8) - (14)].val);
  c->g[3]=0;

  c->b[0]=(yyvsp[(9) - (14)].val);
  c->b[1]=(yyvsp[(10) - (14)].val);
  c->b[2]=(yyvsp[(11) - (14)].val);
  c->b[3]=0;

  c->red = (yyvsp[(12) - (14)].val);
  c->green = (yyvsp[(13) - (14)].val);
  c->blue = (yyvsp[(14) - (14)].val);
  op[lastop].op.constants.p =  add_symbol((yyvsp[(2) - (14)].string),SYM_CONSTANTS,c);
  op[lastop].opcode=CONSTANTS;
  lastop++;
}
    break;

  case 45:
#line 689 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = SAVE_COORDS;
  m = new_matrix(4,4);
  op[lastop].op.save_coordinate_system.p = add_symbol((yyvsp[(2) - (2)].string),SYM_MATRIX,m);
  lastop++;
}
    break;

  case 46:
#line 698 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = CAMERA;
  op[lastop].op.camera.eye[0] = (yyvsp[(2) - (7)].val);
  op[lastop].op.camera.eye[1] = (yyvsp[(3) - (7)].val);
  op[lastop].op.camera.eye[2] = (yyvsp[(4) - (7)].val);
  op[lastop].op.camera.eye[3] = 0;
  op[lastop].op.camera.aim[0] = (yyvsp[(5) - (7)].val);
  op[lastop].op.camera.aim[1] = (yyvsp[(6) - (7)].val);
  op[lastop].op.camera.aim[2] = (yyvsp[(7) - (7)].val);
  op[lastop].op.camera.aim[3] = 0;
  lastop++;
}
    break;

  case 47:
#line 713 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = TEXTURE;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.texture.d0[0] = (yyvsp[(3) - (14)].val);
  op[lastop].op.texture.d0[1] = (yyvsp[(4) - (14)].val);
  op[lastop].op.texture.d0[2] = (yyvsp[(5) - (14)].val);
  op[lastop].op.texture.d1[0] = (yyvsp[(6) - (14)].val);
  op[lastop].op.texture.d1[1] = (yyvsp[(7) - (14)].val);
  op[lastop].op.texture.d1[2] = (yyvsp[(8) - (14)].val);
  op[lastop].op.texture.d2[0] = (yyvsp[(9) - (14)].val);
  op[lastop].op.texture.d2[1] = (yyvsp[(10) - (14)].val);
  op[lastop].op.texture.d2[2] = (yyvsp[(11) - (14)].val);
  op[lastop].op.texture.d3[0] = (yyvsp[(12) - (14)].val);
  op[lastop].op.texture.d3[1] = (yyvsp[(13) - (14)].val);
  op[lastop].op.texture.d3[2] = (yyvsp[(14) - (14)].val);
  op[lastop].op.texture.cs = NULL;
  op[lastop].op.texture.constants =  add_symbol("",SYM_CONSTANTS,c);
  op[lastop].op.texture.p = add_symbol((yyvsp[(2) - (14)].string),SYM_FILE,0);
  lastop++;
}
    break;

  case 48:
#line 736 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = SET;
  op[lastop].op.set.p = add_symbol((yyvsp[(2) - (3)].string),SYM_VALUE,0);
  set_value(op[lastop].op.set.p,(yyvsp[(3) - (3)].val));
  op[lastop].op.set.val = (yyvsp[(3) - (3)].val);
  lastop++;
}
    break;

  case 49:
#line 746 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = BASENAME;
  op[lastop].op.basename.p = add_symbol((yyvsp[(2) - (2)].string),SYM_STRING,0);
  lastop++;
}
    break;

  case 50:
#line 753 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = SAVE_KNOBS;
  op[lastop].op.save_knobs.p = add_symbol((yyvsp[(2) - (2)].string),SYM_STRING,0);
  lastop++;
}
    break;

  case 51:
#line 761 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = TWEEN;
  op[lastop].op.tween.start_frame = (yyvsp[(2) - (5)].val);
  op[lastop].op.tween.end_frame = (yyvsp[(3) - (5)].val);
  op[lastop].op.tween.knob_list0 = add_symbol((yyvsp[(4) - (5)].string),SYM_STRING,0);
  op[lastop].op.tween.knob_list1 = add_symbol((yyvsp[(5) - (5)].string),SYM_STRING,0);
  lastop++;
}
    break;

  case 52:
#line 772 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = FRAMES;
  op[lastop].op.frames.num_frames = (yyvsp[(2) - (2)].val);
  lastop++;
}
    break;

  case 53:
#line 780 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = VARY;
  op[lastop].op.vary.p = add_symbol((yyvsp[(2) - (6)].string),SYM_STRING,0);
  op[lastop].op.vary.start_frame = (yyvsp[(3) - (6)].val);
  op[lastop].op.vary.end_frame = (yyvsp[(4) - (6)].val);
  op[lastop].op.vary.start_val = (yyvsp[(5) - (6)].val);
  op[lastop].op.vary.end_val = (yyvsp[(6) - (6)].val);
  lastop++;
}
    break;

  case 54:
#line 792 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = SHADING;
  op[lastop].op.shading.p = add_symbol((yyvsp[(2) - (2)].string),SYM_STRING,0);
  lastop++;
}
    break;

  case 55:
#line 799 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = SETKNOBS;
  op[lastop].op.setknobs.value = (yyvsp[(2) - (2)].val);
  lastop++;
}
    break;

  case 56:
#line 806 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = FOCAL;
  op[lastop].op.focal.value = (yyvsp[(2) - (2)].val);
  lastop++;
}
    break;

  case 57:
#line 814 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = WEB;
  lastop++;
}
    break;

  case 58:
#line 820 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = AMBIENT;
  op[lastop].op.ambient.c[0] = (yyvsp[(2) - (4)].val);
  op[lastop].op.ambient.c[1] = (yyvsp[(3) - (4)].val);
  op[lastop].op.ambient.c[2] = (yyvsp[(4) - (4)].val);
  lastop++;
}
    break;

  case 59:
#line 830 "mdl.y"
    {
  lineno++;
  op[lastop].opcode = GENERATE_RAYFILES;
  lastop++;
}
    break;


/* Line 1267 of yacc.c.  */
#line 2478 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 835 "mdl.y"



/* Other C stuff */
int yyerror(char *s)
{
  printf("Error in line %d:%s\n",lineno,s);
  return 0;
}

int yywrap()
{
  return 1;
}

extern FILE *yyin;


int main(int argc, char **argv) {

  yyin = fopen(argv[1],"r");

  yyparse();
  //COMMENT OUT PRINT_PCODE AND UNCOMMENT
  //MY_MAIN IN ORDER TO RUN YOUR CODE

  //print_pcode();
  my_main();

  return 0;
}

