/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "smarthome.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
int yyerror(const char *s);

/* ─── DEVICE STATE TABLE ─── */
int light_state    = 0;   /* 0 = OFF, 1 = ON  */
int fan_state      = 0;
int ac_state       = 0;
int heater_state   = 0;
int alarm_state    = 0;
int camera_state   = 0;
int sprinkler_state= 0;
int door_state     = 0;   /* 0 = locked, 1 = unlocked */

/* ─── SENSOR STATE ─── */
int temp_val       = 25;  /* degrees Celsius (default) */
int humidity_val   = 50;  /* percent (default)         */
int motion_val     = 0;   /* 0=clear, 1=detected       */
int smoke_val      = 0;   /* 0=clear, 1=detected       */
int door_sensor    = 0;   /* 0=closed, 1=open          */
int time_period    = 0;   /* 0=day, 1=morning, 2=night */

/* ─── EMERGENCY OVERRIDE ─── */
int emergency_mode = 0;

/* ─── LOG ─── */
int log_count = 0;
char log_entries[50][128];

/* ─── HELPERS ─── */
void log_event(const char *msg) {
    if (log_count < 50) {
        strncpy(log_entries[log_count++], msg, 127);
    }
    printf("  [LOG] %s\n", msg);
}

void ast(const char *parent, const char *child) {
    printf("  AST: (%s -> %s)\n", parent, child);
}

const char* onoff(int state) { return state ? "ON" : "OFF"; }

void print_status() {
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║        DEVICE STATUS DASHBOARD       ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  💡 Light     : %-20s║\n", onoff(light_state));
    printf("║  🌀 Fan       : %-20s║\n", onoff(fan_state));
    printf("║  ❄️  AC        : %-20s║\n", onoff(ac_state));
    printf("║  🔥 Heater    : %-20s║\n", onoff(heater_state));
    printf("║  🔔 Alarm     : %-20s║\n", onoff(alarm_state));
    printf("║  📷 Camera    : %-20s║\n", onoff(camera_state));
    printf("║  💧 Sprinkler : %-20s║\n", onoff(sprinkler_state));
    printf("║  🚪 Door      : %-20s║\n", door_state ? "UNLOCKED" : "LOCKED");
    printf("╠══════════════════════════════════════╣\n");
    printf("║         SENSOR READINGS              ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  🌡️  Temp      : %-3d°C               ║\n", temp_val);
    printf("║  💧 Humidity  : %-3d%%                ║\n", humidity_val);
    printf("║  👁️  Motion    : %-20s║\n", motion_val ? "DETECTED" : "CLEAR");
    printf("║  🔥 Smoke     : %-20s║\n", smoke_val ? "DETECTED" : "CLEAR");
    printf("║  🚪 Door Snsr : %-20s║\n", door_sensor ? "OPEN" : "CLOSED");
    printf("╚══════════════════════════════════════╝\n\n");
}

#line 142 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    THEN = 259,                    /* THEN  */
    ELSE = 260,                    /* ELSE  */
    END = 261,                     /* END  */
    AND = 262,                     /* AND  */
    OR = 263,                      /* OR  */
    SET = 264,                     /* SET  */
    STATUS = 265,                  /* STATUS  */
    LOG = 266,                     /* LOG  */
    SCENE = 267,                   /* SCENE  */
    ON = 268,                      /* ON  */
    OFF = 269,                     /* OFF  */
    LOCK = 270,                    /* LOCK  */
    UNLOCK = 271,                  /* UNLOCK  */
    EQ = 272,                      /* EQ  */
    NEQ = 273,                     /* NEQ  */
    GT = 274,                      /* GT  */
    LT = 275,                      /* LT  */
    GTE = 276,                     /* GTE  */
    LTE = 277,                     /* LTE  */
    ASSIGN = 278,                  /* ASSIGN  */
    TIME = 279,                    /* TIME  */
    TEMP = 280,                    /* TEMP  */
    MOTION = 281,                  /* MOTION  */
    HUMIDITY = 282,                /* HUMIDITY  */
    SMOKE = 283,                   /* SMOKE  */
    DOOR = 284,                    /* DOOR  */
    LIGHT = 285,                   /* LIGHT  */
    FAN = 286,                     /* FAN  */
    AC = 287,                      /* AC  */
    HEATER = 288,                  /* HEATER  */
    ALARM = 289,                   /* ALARM  */
    CAMERA = 290,                  /* CAMERA  */
    SPRINKLER = 291,               /* SPRINKLER  */
    MORNING = 292,                 /* MORNING  */
    NIGHT = 293,                   /* NIGHT  */
    DAY = 294,                     /* DAY  */
    DETECTED = 295,                /* DETECTED  */
    CLEAR = 296,                   /* CLEAR  */
    OPEN = 297,                    /* OPEN  */
    CLOSED = 298,                  /* CLOSED  */
    EMERGENCY = 299,               /* EMERGENCY  */
    HIGH = 300,                    /* HIGH  */
    LOW = 301,                     /* LOW  */
    NORMAL = 302,                  /* NORMAL  */
    NUM = 303,                     /* NUM  */
    INVALID = 304                  /* INVALID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_THEN = 4,                       /* THEN  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_END = 6,                        /* END  */
  YYSYMBOL_AND = 7,                        /* AND  */
  YYSYMBOL_OR = 8,                         /* OR  */
  YYSYMBOL_SET = 9,                        /* SET  */
  YYSYMBOL_STATUS = 10,                    /* STATUS  */
  YYSYMBOL_LOG = 11,                       /* LOG  */
  YYSYMBOL_SCENE = 12,                     /* SCENE  */
  YYSYMBOL_ON = 13,                        /* ON  */
  YYSYMBOL_OFF = 14,                       /* OFF  */
  YYSYMBOL_LOCK = 15,                      /* LOCK  */
  YYSYMBOL_UNLOCK = 16,                    /* UNLOCK  */
  YYSYMBOL_EQ = 17,                        /* EQ  */
  YYSYMBOL_NEQ = 18,                       /* NEQ  */
  YYSYMBOL_GT = 19,                        /* GT  */
  YYSYMBOL_LT = 20,                        /* LT  */
  YYSYMBOL_GTE = 21,                       /* GTE  */
  YYSYMBOL_LTE = 22,                       /* LTE  */
  YYSYMBOL_ASSIGN = 23,                    /* ASSIGN  */
  YYSYMBOL_TIME = 24,                      /* TIME  */
  YYSYMBOL_TEMP = 25,                      /* TEMP  */
  YYSYMBOL_MOTION = 26,                    /* MOTION  */
  YYSYMBOL_HUMIDITY = 27,                  /* HUMIDITY  */
  YYSYMBOL_SMOKE = 28,                     /* SMOKE  */
  YYSYMBOL_DOOR = 29,                      /* DOOR  */
  YYSYMBOL_LIGHT = 30,                     /* LIGHT  */
  YYSYMBOL_FAN = 31,                       /* FAN  */
  YYSYMBOL_AC = 32,                        /* AC  */
  YYSYMBOL_HEATER = 33,                    /* HEATER  */
  YYSYMBOL_ALARM = 34,                     /* ALARM  */
  YYSYMBOL_CAMERA = 35,                    /* CAMERA  */
  YYSYMBOL_SPRINKLER = 36,                 /* SPRINKLER  */
  YYSYMBOL_MORNING = 37,                   /* MORNING  */
  YYSYMBOL_NIGHT = 38,                     /* NIGHT  */
  YYSYMBOL_DAY = 39,                       /* DAY  */
  YYSYMBOL_DETECTED = 40,                  /* DETECTED  */
  YYSYMBOL_CLEAR = 41,                     /* CLEAR  */
  YYSYMBOL_OPEN = 42,                      /* OPEN  */
  YYSYMBOL_CLOSED = 43,                    /* CLOSED  */
  YYSYMBOL_EMERGENCY = 44,                 /* EMERGENCY  */
  YYSYMBOL_HIGH = 45,                      /* HIGH  */
  YYSYMBOL_LOW = 46,                       /* LOW  */
  YYSYMBOL_NORMAL = 47,                    /* NORMAL  */
  YYSYMBOL_NUM = 48,                       /* NUM  */
  YYSYMBOL_INVALID = 49,                   /* INVALID  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_statement = 52,                 /* statement  */
  YYSYMBOL_if_statement = 53,              /* if_statement  */
  YYSYMBOL_condition = 54,                 /* condition  */
  YYSYMBOL_simple_condition = 55,          /* simple_condition  */
  YYSYMBOL_action_list = 56,               /* action_list  */
  YYSYMBOL_action = 57,                    /* action  */
  YYSYMBOL_device_action = 58,             /* device_action  */
  YYSYMBOL_set_statement = 59,             /* set_statement  */
  YYSYMBOL_sensor_assignment = 60,         /* sensor_assignment  */
  YYSYMBOL_emergency_statement = 61,       /* emergency_statement  */
  YYSYMBOL_scene_statement = 62,           /* scene_statement  */
  YYSYMBOL_status_statement = 63,          /* status_statement  */
  YYSYMBOL_log_statement = 64              /* log_statement  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   122

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,    88,    92,    93,    94,    95,    96,    97,
      98,   103,   106,   113,   114,   117,   123,   131,   139,   144,
     149,   154,   159,   164,   169,   174,   179,   184,   189,   198,
     199,   203,   204,   208,   214,   220,   226,   232,   238,   244,
     250,   256,   262,   268,   274,   280,   286,   292,   298,   308,
     314,   320,   325,   330,   335,   340,   345,   350,   359,   364,
     369,   374,   379,   384,   389,   394,   399,   404,   409,   418,
     433,   444,   454,   467,   475
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "THEN", "ELSE",
  "END", "AND", "OR", "SET", "STATUS", "LOG", "SCENE", "ON", "OFF", "LOCK",
  "UNLOCK", "EQ", "NEQ", "GT", "LT", "GTE", "LTE", "ASSIGN", "TIME",
  "TEMP", "MOTION", "HUMIDITY", "SMOKE", "DOOR", "LIGHT", "FAN", "AC",
  "HEATER", "ALARM", "CAMERA", "SPRINKLER", "MORNING", "NIGHT", "DAY",
  "DETECTED", "CLEAR", "OPEN", "CLOSED", "EMERGENCY", "HIGH", "LOW",
  "NORMAL", "NUM", "INVALID", "$accept", "program", "statement",
  "if_statement", "condition", "simple_condition", "action_list", "action",
  "device_action", "set_statement", "sensor_assignment",
  "emergency_statement", "scene_statement", "status_statement",
  "log_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -94,     0,   -94,    32,    33,   -94,   -94,   -33,   -27,   -16,
       9,    16,    20,    23,    26,    30,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,    45,    18,    67,    46,    72,
      92,   102,    62,    61,    63,    65,    97,   -94,   -94,   -94,
     -94,   -94,   -31,    64,    40,    66,    42,    43,    34,    68,
      69,    70,    47,    71,    73,    75,    48,    39,    32,    32,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -13,    82,    84,    25,   -94,   -94,   -94,   -94,   -94,
      79,    81,    83,    85,    87,    89,    91,   -94,   -94,    39,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,    36,   -94
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,    73,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     3,     4,     5,
       9,    10,     8,     6,     7,     0,     0,     0,     0,     0,
       0,     0,    13,     0,     0,     0,     0,    70,    71,    72,
      56,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,    50,    51,    52,    53,    54,    55,    66,    67,    68,
      58,    60,    61,    59,    62,    63,    64,    65,    27,    26,
      28,    18,    16,    17,    21,    22,    19,    20,    23,    24,
      25,     0,     0,     0,     0,    29,    31,    32,    14,    15,
       0,     0,     0,     0,     0,     0,     0,    47,    48,     0,
      11,    30,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     0,    12
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -94,   -94,   -94,    49,    11,   -93,   -94,   -94,
     -94,   -94,   -94,   -94,   121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    17,    18,    31,    32,    94,    95,    96,    19,
      20,    21,    22,    23,    97
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       2,   111,    40,     3,    37,    38,    67,    68,    69,     4,
       5,     6,     7,    41,    39,     8,     9,   100,   101,   102,
     103,   104,   105,   106,    10,    11,    12,    13,    14,    15,
     109,   110,    42,   111,    91,    49,     6,    50,    51,    43,
      92,    93,   127,    44,    16,    91,    45,     6,    91,    46,
       6,    92,    93,    47,    92,    93,    25,    26,    27,    28,
      29,    30,    48,    33,    34,    53,    54,    35,    36,    58,
      59,    78,    79,    80,    60,    61,    62,    63,    64,    65,
      71,    72,    74,    75,    52,    76,    77,    84,    85,    55,
      89,    90,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    57,    98,    99,    56,
      66,   107,    70,   108,    73,    88,    81,    82,    83,    86,
     126,    87,    24
};

static const yytype_int8 yycheck[] =
{
       0,    94,    29,     3,    37,    38,    37,    38,    39,     9,
      10,    11,    12,    29,    47,    15,    16,    30,    31,    32,
      33,    34,    35,    36,    24,    25,    26,    27,    28,    29,
       5,     6,    23,   126,     9,    17,    11,    19,    20,    23,
      15,    16,     6,    23,    44,     9,    23,    11,     9,    23,
      11,    15,    16,    23,    15,    16,    24,    25,    26,    27,
      28,    29,    17,    30,    31,    19,    20,    34,    35,     7,
       8,    37,    38,    39,    13,    14,    13,    14,    13,    14,
      40,    41,    40,    41,    17,    42,    43,    40,    41,    17,
      42,    43,    13,    14,    13,    14,    13,    14,    13,    14,
      13,    14,    13,    14,    13,    14,     4,    58,    59,    17,
      13,    29,    48,    29,    48,    40,    48,    48,    48,    48,
     109,    48,     1
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,     0,     3,     9,    10,    11,    12,    15,    16,
      24,    25,    26,    27,    28,    29,    44,    52,    53,    59,
      60,    61,    62,    63,    64,    24,    25,    26,    27,    28,
      29,    54,    55,    30,    31,    34,    35,    37,    38,    47,
      29,    29,    23,    23,    23,    23,    23,    23,    17,    17,
      19,    20,    17,    19,    20,    17,    17,     4,     7,     8,
      13,    14,    13,    14,    13,    14,    13,    37,    38,    39,
      48,    40,    41,    48,    40,    41,    42,    43,    37,    38,
      39,    48,    48,    48,    40,    41,    48,    48,    40,    42,
      43,     9,    15,    16,    56,    57,    58,    64,    55,    55,
      30,    31,    32,    33,    34,    35,    36,    29,    29,     5,
       6,    57,    13,    14,    13,    14,    13,    14,    13,    14,
      13,    14,    13,    14,    13,    14,    56,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    53,    53,    54,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      56,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      62,    62,    62,    63,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     5,     7,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     2,     2,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 11: /* if_statement: IF condition THEN action_list END  */
#line 103 "smarthome.y"
                                      {
        ast("if_stmt", "condition+actions");
    }
#line 1364 "y.tab.c"
    break;

  case 12: /* if_statement: IF condition THEN action_list ELSE action_list END  */
#line 106 "smarthome.y"
                                                       {
        ast("if_stmt", "condition+then+else");
    }
#line 1372 "y.tab.c"
    break;

  case 14: /* condition: simple_condition AND simple_condition  */
#line 114 "smarthome.y"
                                          {
        ast("condition", "AND");
    }
#line 1380 "y.tab.c"
    break;

  case 15: /* condition: simple_condition OR simple_condition  */
#line 117 "smarthome.y"
                                         {
        ast("condition", "OR");
    }
#line 1388 "y.tab.c"
    break;

  case 16: /* simple_condition: TEMP GT NUM  */
#line 123 "smarthome.y"
                {
        ast("cond", "temp>");
        if (temp_val > yyvsp[0])
            printf("  ✔ Condition TRUE: temp(%d) > %d\n", temp_val, yyvsp[0]);
        else
            printf("  ✘ Condition FALSE: temp(%d) > %d\n", temp_val, yyvsp[0]);
        yyval = (temp_val > yyvsp[0]) ? 1 : 0;
    }
#line 1401 "y.tab.c"
    break;

  case 17: /* simple_condition: TEMP LT NUM  */
#line 131 "smarthome.y"
                {
        ast("cond", "temp<");
        if (temp_val < yyvsp[0])
            printf("  ✔ Condition TRUE: temp(%d) < %d\n", temp_val, yyvsp[0]);
        else
            printf("  ✘ Condition FALSE: temp(%d) < %d\n", temp_val, yyvsp[0]);
        yyval = (temp_val < yyvsp[0]) ? 1 : 0;
    }
#line 1414 "y.tab.c"
    break;

  case 18: /* simple_condition: TEMP EQ NUM  */
#line 139 "smarthome.y"
                {
        ast("cond", "temp==");
        yyval = (temp_val == yyvsp[0]) ? 1 : 0;
        printf("  %s Condition: temp(%d) == %d\n", yyval?"✔":"✘", temp_val, yyvsp[0]);
    }
#line 1424 "y.tab.c"
    break;

  case 19: /* simple_condition: HUMIDITY GT NUM  */
#line 144 "smarthome.y"
                    {
        ast("cond", "humidity>");
        yyval = (humidity_val > yyvsp[0]) ? 1 : 0;
        printf("  %s Condition: humidity(%d) > %d\n", yyval?"✔":"✘", humidity_val, yyvsp[0]);
    }
#line 1434 "y.tab.c"
    break;

  case 20: /* simple_condition: HUMIDITY LT NUM  */
#line 149 "smarthome.y"
                    {
        ast("cond", "humidity<");
        yyval = (humidity_val < yyvsp[0]) ? 1 : 0;
        printf("  %s Condition: humidity(%d) < %d\n", yyval?"✔":"✘", humidity_val, yyvsp[0]);
    }
#line 1444 "y.tab.c"
    break;

  case 21: /* simple_condition: MOTION EQ DETECTED  */
#line 154 "smarthome.y"
                       {
        ast("cond", "motion==detected");
        yyval = motion_val;
        printf("  %s Condition: motion == detected\n", yyval?"✔":"✘");
    }
#line 1454 "y.tab.c"
    break;

  case 22: /* simple_condition: MOTION EQ CLEAR  */
#line 159 "smarthome.y"
                    {
        ast("cond", "motion==clear");
        yyval = !motion_val;
        printf("  %s Condition: motion == clear\n", yyval?"✔":"✘");
    }
#line 1464 "y.tab.c"
    break;

  case 23: /* simple_condition: SMOKE EQ DETECTED  */
#line 164 "smarthome.y"
                      {
        ast("cond", "smoke==detected");
        yyval = smoke_val;
        printf("  %s Condition: smoke == detected\n", yyval?"✔":"✘");
    }
#line 1474 "y.tab.c"
    break;

  case 24: /* simple_condition: DOOR EQ OPEN  */
#line 169 "smarthome.y"
                 {
        ast("cond", "door==open");
        yyval = door_sensor;
        printf("  %s Condition: door == open\n", yyval?"✔":"✘");
    }
#line 1484 "y.tab.c"
    break;

  case 25: /* simple_condition: DOOR EQ CLOSED  */
#line 174 "smarthome.y"
                   {
        ast("cond", "door==closed");
        yyval = !door_sensor;
        printf("  %s Condition: door == closed\n", yyval?"✔":"✘");
    }
#line 1494 "y.tab.c"
    break;

  case 26: /* simple_condition: TIME EQ NIGHT  */
#line 179 "smarthome.y"
                  {
        ast("cond", "time==night");
        yyval = (time_period == 2);
        printf("  %s Condition: time == night\n", yyval?"✔":"✘");
    }
#line 1504 "y.tab.c"
    break;

  case 27: /* simple_condition: TIME EQ MORNING  */
#line 184 "smarthome.y"
                    {
        ast("cond", "time==morning");
        yyval = (time_period == 1);
        printf("  %s Condition: time == morning\n", yyval?"✔":"✘");
    }
#line 1514 "y.tab.c"
    break;

  case 28: /* simple_condition: TIME EQ DAY  */
#line 189 "smarthome.y"
                {
        ast("cond", "time==day");
        yyval = (time_period == 0);
        printf("  %s Condition: time == day\n", yyval?"✔":"✘");
    }
#line 1524 "y.tab.c"
    break;

  case 33: /* device_action: SET LIGHT ON  */
#line 208 "smarthome.y"
                 {
        ast("action", "light=ON");
        light_state = 1;
        printf("  → 💡 Light turned ON\n");
        log_event("Light turned ON by rule");
    }
#line 1535 "y.tab.c"
    break;

  case 34: /* device_action: SET LIGHT OFF  */
#line 214 "smarthome.y"
                  {
        ast("action", "light=OFF");
        light_state = 0;
        printf("  → 💡 Light turned OFF\n");
        log_event("Light turned OFF by rule");
    }
#line 1546 "y.tab.c"
    break;

  case 35: /* device_action: SET FAN ON  */
#line 220 "smarthome.y"
               {
        ast("action", "fan=ON");
        fan_state = 1;
        printf("  → 🌀 Fan turned ON\n");
        log_event("Fan turned ON by rule");
    }
#line 1557 "y.tab.c"
    break;

  case 36: /* device_action: SET FAN OFF  */
#line 226 "smarthome.y"
                {
        ast("action", "fan=OFF");
        fan_state = 0;
        printf("  → 🌀 Fan turned OFF\n");
        log_event("Fan turned OFF by rule");
    }
#line 1568 "y.tab.c"
    break;

  case 37: /* device_action: SET AC ON  */
#line 232 "smarthome.y"
              {
        ast("action", "ac=ON");
        ac_state = 1;
        printf("  → ❄️  AC turned ON\n");
        log_event("AC turned ON by rule");
    }
#line 1579 "y.tab.c"
    break;

  case 38: /* device_action: SET AC OFF  */
#line 238 "smarthome.y"
               {
        ast("action", "ac=OFF");
        ac_state = 0;
        printf("  → ❄️  AC turned OFF\n");
        log_event("AC turned OFF by rule");
    }
#line 1590 "y.tab.c"
    break;

  case 39: /* device_action: SET HEATER ON  */
#line 244 "smarthome.y"
                  {
        ast("action", "heater=ON");
        heater_state = 1;
        printf("  → 🔥 Heater turned ON\n");
        log_event("Heater turned ON by rule");
    }
#line 1601 "y.tab.c"
    break;

  case 40: /* device_action: SET HEATER OFF  */
#line 250 "smarthome.y"
                   {
        ast("action", "heater=OFF");
        heater_state = 0;
        printf("  → 🔥 Heater turned OFF\n");
        log_event("Heater turned OFF by rule");
    }
#line 1612 "y.tab.c"
    break;

  case 41: /* device_action: SET ALARM ON  */
#line 256 "smarthome.y"
                 {
        ast("action", "alarm=ON");
        alarm_state = 1;
        printf("  → 🔔 ALARM ACTIVATED!\n");
        log_event("Alarm activated by rule");
    }
#line 1623 "y.tab.c"
    break;

  case 42: /* device_action: SET ALARM OFF  */
#line 262 "smarthome.y"
                  {
        ast("action", "alarm=OFF");
        alarm_state = 0;
        printf("  → 🔔 Alarm deactivated\n");
        log_event("Alarm deactivated by rule");
    }
#line 1634 "y.tab.c"
    break;

  case 43: /* device_action: SET CAMERA ON  */
#line 268 "smarthome.y"
                  {
        ast("action", "camera=ON");
        camera_state = 1;
        printf("  → 📷 Camera activated\n");
        log_event("Camera activated by rule");
    }
#line 1645 "y.tab.c"
    break;

  case 44: /* device_action: SET CAMERA OFF  */
#line 274 "smarthome.y"
                   {
        ast("action", "camera=OFF");
        camera_state = 0;
        printf("  → 📷 Camera deactivated\n");
        log_event("Camera deactivated by rule");
    }
#line 1656 "y.tab.c"
    break;

  case 45: /* device_action: SET SPRINKLER ON  */
#line 280 "smarthome.y"
                     {
        ast("action", "sprinkler=ON");
        sprinkler_state = 1;
        printf("  → 💧 Sprinkler activated!\n");
        log_event("Sprinkler activated by rule");
    }
#line 1667 "y.tab.c"
    break;

  case 46: /* device_action: SET SPRINKLER OFF  */
#line 286 "smarthome.y"
                      {
        ast("action", "sprinkler=OFF");
        sprinkler_state = 0;
        printf("  → 💧 Sprinkler deactivated\n");
        log_event("Sprinkler deactivated by rule");
    }
#line 1678 "y.tab.c"
    break;

  case 47: /* device_action: LOCK DOOR  */
#line 292 "smarthome.y"
              {
        ast("action", "door=LOCKED");
        door_state = 0;
        printf("  → 🚪 Door LOCKED\n");
        log_event("Door locked by rule");
    }
#line 1689 "y.tab.c"
    break;

  case 48: /* device_action: UNLOCK DOOR  */
#line 298 "smarthome.y"
                {
        ast("action", "door=UNLOCKED");
        door_state = 1;
        printf("  → 🚪 Door UNLOCKED\n");
        log_event("Door unlocked by rule");
    }
#line 1700 "y.tab.c"
    break;

  case 49: /* set_statement: SET LIGHT ON  */
#line 308 "smarthome.y"
                 {
        light_state = 1;
        ast("set_stmt", "light=ON");
        printf("  → 💡 Light turned ON\n");
        log_event("Light turned ON directly");
    }
#line 1711 "y.tab.c"
    break;

  case 50: /* set_statement: SET LIGHT OFF  */
#line 314 "smarthome.y"
                  {
        light_state = 0;
        ast("set_stmt", "light=OFF");
        printf("  → 💡 Light turned OFF\n");
        log_event("Light turned OFF directly");
    }
#line 1722 "y.tab.c"
    break;

  case 51: /* set_statement: SET FAN ON  */
#line 320 "smarthome.y"
               {
        fan_state = 1;
        ast("set_stmt", "fan=ON");
        printf("  → 🌀 Fan turned ON\n");
    }
#line 1732 "y.tab.c"
    break;

  case 52: /* set_statement: SET FAN OFF  */
#line 325 "smarthome.y"
                {
        fan_state = 0;
        ast("set_stmt", "fan=OFF");
        printf("  → 🌀 Fan turned OFF\n");
    }
#line 1742 "y.tab.c"
    break;

  case 53: /* set_statement: SET ALARM ON  */
#line 330 "smarthome.y"
                 {
        alarm_state = 1;
        ast("set_stmt", "alarm=ON");
        printf("  → 🔔 Alarm ON\n");
    }
#line 1752 "y.tab.c"
    break;

  case 54: /* set_statement: SET ALARM OFF  */
#line 335 "smarthome.y"
                  {
        alarm_state = 0;
        ast("set_stmt", "alarm=OFF");
        printf("  → 🔔 Alarm OFF\n");
    }
#line 1762 "y.tab.c"
    break;

  case 55: /* set_statement: SET CAMERA ON  */
#line 340 "smarthome.y"
                  {
        camera_state = 1;
        ast("set_stmt", "camera=ON");
        printf("  → 📷 Camera ON\n");
    }
#line 1772 "y.tab.c"
    break;

  case 56: /* set_statement: LOCK DOOR  */
#line 345 "smarthome.y"
              {
        door_state = 0;
        ast("set_stmt", "door=LOCKED");
        printf("  → 🚪 Door LOCKED\n");
    }
#line 1782 "y.tab.c"
    break;

  case 57: /* set_statement: UNLOCK DOOR  */
#line 350 "smarthome.y"
                {
        door_state = 1;
        ast("set_stmt", "door=UNLOCKED");
        printf("  → 🚪 Door UNLOCKED\n");
    }
#line 1792 "y.tab.c"
    break;

  case 58: /* sensor_assignment: TEMP ASSIGN NUM  */
#line 359 "smarthome.y"
                    {
        ast("sensor", "temp=val");
        temp_val = yyvsp[0];
        printf("  → 🌡️  Temperature set to %d°C\n", temp_val);
    }
#line 1802 "y.tab.c"
    break;

  case 59: /* sensor_assignment: HUMIDITY ASSIGN NUM  */
#line 364 "smarthome.y"
                        {
        ast("sensor", "humidity=val");
        humidity_val = yyvsp[0];
        printf("  → 💧 Humidity set to %d%%\n", humidity_val);
    }
#line 1812 "y.tab.c"
    break;

  case 60: /* sensor_assignment: MOTION ASSIGN DETECTED  */
#line 369 "smarthome.y"
                           {
        ast("sensor", "motion=detected");
        motion_val = 1;
        printf("  → 👁️  Motion sensor: DETECTED\n");
    }
#line 1822 "y.tab.c"
    break;

  case 61: /* sensor_assignment: MOTION ASSIGN CLEAR  */
#line 374 "smarthome.y"
                        {
        ast("sensor", "motion=clear");
        motion_val = 0;
        printf("  → 👁️  Motion sensor: CLEAR\n");
    }
#line 1832 "y.tab.c"
    break;

  case 62: /* sensor_assignment: SMOKE ASSIGN DETECTED  */
#line 379 "smarthome.y"
                          {
        ast("sensor", "smoke=detected");
        smoke_val = 1;
        printf("  → 🔥 Smoke sensor: DETECTED\n");
    }
#line 1842 "y.tab.c"
    break;

  case 63: /* sensor_assignment: SMOKE ASSIGN CLEAR  */
#line 384 "smarthome.y"
                       {
        ast("sensor", "smoke=clear");
        smoke_val = 0;
        printf("  → 🔥 Smoke sensor: CLEAR\n");
    }
#line 1852 "y.tab.c"
    break;

  case 64: /* sensor_assignment: DOOR ASSIGN OPEN  */
#line 389 "smarthome.y"
                     {
        ast("sensor", "door=open");
        door_sensor = 1;
        printf("  → 🚪 Door sensor: OPEN\n");
    }
#line 1862 "y.tab.c"
    break;

  case 65: /* sensor_assignment: DOOR ASSIGN CLOSED  */
#line 394 "smarthome.y"
                       {
        ast("sensor", "door=closed");
        door_sensor = 0;
        printf("  → 🚪 Door sensor: CLOSED\n");
    }
#line 1872 "y.tab.c"
    break;

  case 66: /* sensor_assignment: TIME ASSIGN MORNING  */
#line 399 "smarthome.y"
                        {
        ast("sensor", "time=morning");
        time_period = 1;
        printf("  → 🌅 Time set to MORNING\n");
    }
#line 1882 "y.tab.c"
    break;

  case 67: /* sensor_assignment: TIME ASSIGN NIGHT  */
#line 404 "smarthome.y"
                      {
        ast("sensor", "time=night");
        time_period = 2;
        printf("  → 🌙 Time set to NIGHT\n");
    }
#line 1892 "y.tab.c"
    break;

  case 68: /* sensor_assignment: TIME ASSIGN DAY  */
#line 409 "smarthome.y"
                    {
        ast("sensor", "time=day");
        time_period = 0;
        printf("  → ☀️  Time set to DAY\n");
    }
#line 1902 "y.tab.c"
    break;

  case 69: /* emergency_statement: EMERGENCY  */
#line 418 "smarthome.y"
              {
        ast("emergency", "override");
        emergency_mode = 1;
        alarm_state    = 1;
        camera_state   = 1;
        sprinkler_state= 1;
        door_state     = 1;   /* unlock for evacuation */
        printf("  ⚠️  EMERGENCY MODE ACTIVATED!\n");
        printf("  → All alarms ON, cameras ON, sprinklers ON, doors UNLOCKED\n");
        log_event("EMERGENCY MODE ACTIVATED — all safety systems triggered");
    }
#line 1918 "y.tab.c"
    break;

  case 70: /* scene_statement: SCENE MORNING  */
#line 433 "smarthome.y"
                  {
        ast("scene", "morning");
        printf("  → 🌅 Morning Scene activated\n");
        light_state  = 1;
        fan_state    = 0;
        ac_state     = 0;
        door_state   = 1;   /* unlock */
        camera_state = 1;
        printf("     Lights ON, Door UNLOCKED, Camera ON\n");
        log_event("Morning scene activated");
    }
#line 1934 "y.tab.c"
    break;

  case 71: /* scene_statement: SCENE NIGHT  */
#line 444 "smarthome.y"
                {
        ast("scene", "night");
        printf("  → 🌙 Night Scene activated\n");
        light_state  = 0;
        fan_state    = 1;
        door_state   = 0;   /* lock */
        camera_state = 1;
        printf("     Lights OFF, Fan ON, Door LOCKED, Camera ON\n");
        log_event("Night scene activated");
    }
#line 1949 "y.tab.c"
    break;

  case 72: /* scene_statement: SCENE NORMAL  */
#line 454 "smarthome.y"
                 {
        ast("scene", "normal");
        printf("  → 🏠 Normal Scene activated — resetting all devices\n");
        light_state = fan_state = ac_state = heater_state = 0;
        alarm_state = camera_state = sprinkler_state = 0;
        door_state  = 0;
        emergency_mode = 0;
        log_event("Normal scene activated — all devices reset");
    }
#line 1963 "y.tab.c"
    break;

  case 73: /* status_statement: STATUS  */
#line 467 "smarthome.y"
           {
        ast("status", "print");
        print_status();
    }
#line 1972 "y.tab.c"
    break;

  case 74: /* log_statement: LOG  */
#line 475 "smarthome.y"
        {
        ast("log", "print");
        printf("\n  ── Event Log (%d entries) ──\n", log_count);
        int i;
        for (i = 0; i < log_count; i++)
            printf("  [%02d] %s\n", i+1, log_entries[i]);
        if (log_count == 0)
            printf("  (no events logged yet)\n");
        printf("\n");
    }
#line 1987 "y.tab.c"
    break;


#line 1991 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 487 "smarthome.y"


/* ─── MAIN ─── */
int main() {
    printf("╔══════════════════════════════════════╗\n");
    printf("║  Smart Home Automation Rule Engine   ║\n");
    printf("║  Lex + Yacc Compiler Project         ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
    printf("Parsing rules...\n\n");

    yyparse();

    printf("\n════════════ FINAL STATE ════════════\n");
    print_status();

    printf("Event Log Summary: %d event(s) recorded.\n", log_count);
    printf("\nCompilation & execution complete.\n");
    return 0;
}

int yyerror(const char *s) {
    printf("  ❌ Syntax Error: %s\n", s);
    return 0;
}
