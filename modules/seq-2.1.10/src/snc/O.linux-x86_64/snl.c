/*************************************************************************\
Copyright (c) 2010-2012 Helmholtz-Zentrum Berlin f. Materialien
                        und Energie GmbH, Germany (HZB)
This file is distributed subject to a Software License Agreement found
in the file LICENSE that is included with this distribution.
\*************************************************************************/
/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>
#include <assert.h>
#line 10 "../snl.lem"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "expr.h"
#include "main.h"
#include "parser.h"
#line 24 "./snl.c"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    snlParserTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is snlParserTOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    snlParserARG_SDECL     A static variable declaration for the %extra_argument
**    snlParserARG_PDECL     A parameter declaration for the %extra_argument
**    snlParserARG_STORE     Code to store %extra_argument into yypParser
**    snlParserARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 141
#define YYACTIONTYPE unsigned short int
#define snlParserTOKENTYPE  Token 
typedef union {
  int yyinit;
  snlParserTOKENTYPE yy0;
  ExprPair yy44;
  Token yy98;
  int yy172;
  Expr* yy202;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 0
#endif
#define snlParserARG_SDECL  Expr **presult ;
#define snlParserARG_PDECL , Expr **presult 
#define snlParserARG_FETCH  Expr **presult  = yypParser->presult 
#define snlParserARG_STORE yypParser->presult  = presult 
#define YYNSTATE 317
#define YYNRULE 179
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

/* The yyzerominor constant is used to initialize instances of
** YYMINORTYPE objects to zero. */
static const YYMINORTYPE yyzerominor = { 0 };

/* Define the yytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define yytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the yytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef yytestcase
# define yytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
#define YY_ACTTAB_COUNT (927)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    44,   43,   42,   41,   40,   39,   38,   37,   36,   35,
 /*    10 */    34,   46,  102,   54,   53,   50,   49,   48,   58,   57,
 /*    20 */    60,   59,   56,   55,   52,   51,   63,   64,   62,   61,
 /*    30 */    47,   74,  283,  282,  227,   67,  286,   65,   66,   44,
 /*    40 */    43,   42,   41,   40,   39,   38,   37,   36,   35,   34,
 /*    50 */    46,   45,   54,   53,   50,   49,   48,   58,   57,   60,
 /*    60 */    59,   56,   55,   52,   51,   63,   64,   62,   61,   47,
 /*    70 */   199,  283,  282,  300,   67,  193,   65,   66,   44,   43,
 /*    80 */    42,   41,   40,   39,   38,   37,   36,   35,   34,   46,
 /*    90 */   106,   54,   53,   50,   49,   48,   58,   57,   60,   59,
 /*   100 */    56,   55,   52,   51,   63,   64,   62,   61,   47,  313,
 /*   110 */   283,  282,  107,   67,  197,   65,   66,   46,  100,   54,
 /*   120 */    53,   50,   49,   48,   58,   57,   60,   59,   56,   55,
 /*   130 */    52,   51,   63,   64,   62,   61,   47,  347,  283,  282,
 /*   140 */   314,   67,  307,   65,   66,  303,  302,  296,  279,   97,
 /*   150 */    96,   93,   18,  271,  270,  269,  268,  154,  263,  262,
 /*   160 */   261,  260,  259,  258,  257,  256,  255,  254,  253,   82,
 /*   170 */   252,  290,   87,   62,   61,   47,   30,  283,  282,  290,
 /*   180 */    67,  289,   65,   66,  315,   33,   32,   31,  312,  289,
 /*   190 */    29,   27,   26,  283,  282,  113,   67,  185,   65,   66,
 /*   200 */   188,   23,  274,  126,  103,  245,  267,  266,  265,  264,
 /*   210 */   162,  272,  189,  292,   90,  271,  270,  269,  268,  154,
 /*   220 */   263,  262,  261,  260,  259,  258,  257,  256,  255,  254,
 /*   230 */   253,  308,  178,  294,  187,  317,  180,  179,  176,   25,
 /*   240 */   174,  172,  291,   28,  310,  315,  315,  290,  290,  288,
 /*   250 */   195,   30,  165,  290,  228,  194,   69,  289,  289,  306,
 /*   260 */    33,   32,   31,  289,  307,   29,   27,   26,  277,  181,
 /*   270 */   158,  111,  112,  274,  280,  188,   23,  111,  305,  103,
 /*   280 */   236,  301,  293,  189,  171,   90,   80,  299,  292,  168,
 /*   290 */   309,   52,   51,   63,   64,   62,   61,   47,  274,  283,
 /*   300 */   282,  297,   67,  163,   65,   66,  230,  178,  276,  187,
 /*   310 */    90,  180,  179,  176,  295,  174,  172,  291,   28,  310,
 /*   320 */   315,   75,  315,   19,  303,  302,  310,  184,   97,   96,
 /*   330 */    93,   24,  271,  270,  269,  268,  154,  263,  262,  261,
 /*   340 */   260,  259,  258,  257,  256,  255,  254,  253,   82,   22,
 /*   350 */   211,   87,   53,   50,   49,   48,   58,   57,   60,   59,
 /*   360 */    56,   55,   52,   51,   63,   64,   62,   61,   47,  273,
 /*   370 */   283,  282,   30,   67,  290,   65,   66,  105,  287,  290,
 /*   380 */   290,   33,   32,   31,  289,   68,   29,   27,   26,  289,
 /*   390 */   289,  238,  281,  237,   71,  278,  188,   23,  111,   68,
 /*   400 */   103,   92,   17,  114,  112,   81,  190,  304,   70,  292,
 /*   410 */   210,  209,  208,  207,  206,  205,  204,  203,  101,  182,
 /*   420 */     9,  161,  159,    5,  239,  250,   17,   69,  178,  300,
 /*   430 */   187,   95,  180,  179,  176,    7,  174,  172,  291,   28,
 /*   440 */   310,  315,   69,  249,  248,  303,  302,   89,  167,   97,
 /*   450 */    96,   93,  247,  271,  270,  269,  268,  154,  263,  262,
 /*   460 */   261,  260,  259,  258,  257,  256,  255,  254,  253,   84,
 /*   470 */    99,  185,   50,   49,   48,   58,   57,   60,   59,   56,
 /*   480 */    55,   52,   51,   63,   64,   62,   61,   47,  243,  283,
 /*   490 */   282,  300,   67,   72,   65,   66,   49,   48,   58,   57,
 /*   500 */    60,   59,   56,   55,   52,   51,   63,   64,   62,   61,
 /*   510 */    47,  200,  283,  282,   89,   67,  242,   65,   66,   48,
 /*   520 */    58,   57,   60,   59,   56,   55,   52,   51,   63,   64,
 /*   530 */    62,   61,   47,  177,  283,  282,    8,   67,   21,   65,
 /*   540 */    66,   58,   57,   60,   59,   56,   55,   52,   51,   63,
 /*   550 */    64,   62,   61,   47,  241,  283,  282,   20,   67,   16,
 /*   560 */    65,   66,   60,   59,   56,   55,   52,   51,   63,   64,
 /*   570 */    62,   61,   47,  274,  283,  282,  290,   67,  290,   65,
 /*   580 */    66,   30,  232,  186,  290,   90,  289,   15,  289,  290,
 /*   590 */    33,   32,   31,  290,  289,   29,   27,   26,   14,  289,
 /*   600 */   110,  240,  112,  289,    6,  188,   23,   69,  285,   12,
 /*   610 */   238,   13,  237,  284,  170,   88,   30,  112,  292,  168,
 /*   620 */   229,   17,    1,  202,   85,   33,   32,   31,  290,  173,
 /*   630 */    29,   27,   26,  175,  168,  233,  240,    2,  289,  187,
 /*   640 */   188,   23,    4,  239,    3,   11,   10,  291,   28,  310,
 /*   650 */    73,  108,  112,  292,   63,   64,   62,   61,   47,   86,
 /*   660 */   283,  282,  290,   67,  173,   65,   66,  304,  235,  168,
 /*   670 */   233,  290,  289,  311,  187,  310,   98,  290,  290,  307,
 /*   680 */   196,  289,  291,   28,  310,  192,  112,  289,  289,  217,
 /*   690 */   216,  215,  214,  213,   79,  142,  101,   94,  169,   76,
 /*   700 */    78,  141,  112,  168,   17,  225,  224,  223,  222,  221,
 /*   710 */   220,  298,  101,  290,  166,   83,  218,  212,  290,  168,
 /*   720 */    17,  240,  290,  289,  290,   77,   91,  246,  289,  296,
 /*   730 */   240,  275,  289,  290,  289,  290,  226,  112,  195,  104,
 /*   740 */   155,  240,  114,  289,  191,  289,  112,  164,  112,  173,
 /*   750 */   219,  316,  198,  234,  168,  233,  251,  112,  173,  112,
 /*   760 */   290,  160,  231,  168,  233,  157,  183,  290,  290,  173,
 /*   770 */   289,  290,  200,  244,  168,  233,  156,  289,  289,  290,
 /*   780 */   290,  289,  167,  290,  153,  497,  290,  290,  290,  289,
 /*   790 */   289,  152,  138,  289,  201,  137,  289,  289,  289,  290,
 /*   800 */   498,  498,  498,  134,  133,  290,  290,  136,  498,  289,
 /*   810 */   135,  128,  129,  498,  290,  289,  289,  290,  290,  498,
 /*   820 */   498,  290,  498,  140,  289,  290,  498,  289,  289,  139,
 /*   830 */   130,  289,  498,  290,  290,  289,  498,  498,  131,  498,
 /*   840 */   290,  132,  151,  289,  289,  109,  290,  498,  498,  127,
 /*   850 */   289,  290,  290,  498,  498,  290,  289,  125,  124,  290,
 /*   860 */   498,  289,  289,  498,  123,  289,  498,  290,  290,  289,
 /*   870 */   122,  290,  290,  498,  290,  121,  120,  289,  289,  119,
 /*   880 */   290,  289,  289,  118,  289,  498,  498,  290,  498,  290,
 /*   890 */   289,  117,  116,  290,  498,  115,  150,  289,  149,  289,
 /*   900 */   290,  498,  290,  289,  148,  498,  498,  498,  498,  498,
 /*   910 */   289,  147,  289,  146,  498,  498,  498,  145,  498,  498,
 /*   920 */   498,  498,  498,  498,  144,  498,  143,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   42,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
 /*    30 */    31,  128,   33,   34,  131,   36,   37,   38,   39,    1,
 /*    40 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*    50 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*    60 */    22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
 /*    70 */    42,   33,   34,  108,   36,  110,   38,   39,    1,    2,
 /*    80 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*    90 */    46,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   100 */    23,   24,   25,   26,   27,   28,   29,   30,   31,   45,
 /*   110 */    33,   34,   94,   36,   47,   38,   39,   12,   51,   14,
 /*   120 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   130 */    25,   26,   27,   28,   29,   30,   31,   45,   33,   34,
 /*   140 */   122,   36,   50,   38,   39,   48,   49,   55,   47,   52,
 /*   150 */    53,   54,   51,   56,   57,   58,   59,   60,   61,   62,
 /*   160 */    63,   64,   65,   66,   67,   68,   69,   70,   71,   72,
 /*   170 */    47,   96,   75,   29,   30,   31,   18,   33,   34,   96,
 /*   180 */    36,  106,   38,   39,   87,   27,   28,   29,   45,  106,
 /*   190 */    32,   33,   34,   33,   34,  120,   36,   74,   38,   39,
 /*   200 */    42,   43,  106,  120,   46,   47,   56,   57,   58,   59,
 /*   210 */   114,  115,  116,   55,  118,   56,   57,   58,   59,   60,
 /*   220 */    61,   62,   63,   64,   65,   66,   67,   68,   69,   70,
 /*   230 */    71,   45,   74,   45,   76,    0,   78,   79,   80,   51,
 /*   240 */    82,   83,   84,   85,   86,   87,   87,   96,   96,   44,
 /*   250 */    36,   18,   74,   96,   76,   55,   51,  106,  106,   45,
 /*   260 */    27,   28,   29,  106,   50,   32,   33,   34,  117,   94,
 /*   270 */   119,  120,  120,  106,  117,   42,   43,  120,   37,   46,
 /*   280 */    47,   45,  115,  116,  132,  118,   46,   45,   55,  137,
 /*   290 */    96,   25,   26,   27,   28,   29,   30,   31,  106,   33,
 /*   300 */    34,   45,   36,  109,   38,   39,  131,   74,  116,   76,
 /*   310 */   118,   78,   79,   80,   45,   82,   83,   84,   85,   86,
 /*   320 */    87,   93,   87,    1,   48,   49,   86,   42,   52,   53,
 /*   330 */    54,   43,   56,   57,   58,   59,   60,   61,   62,   63,
 /*   340 */    64,   65,   66,   67,   68,   69,   70,   71,   72,   43,
 /*   350 */   122,   75,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   360 */    23,   24,   25,   26,   27,   28,   29,   30,   31,   44,
 /*   370 */    33,   34,   18,   36,   96,   38,   39,   46,   44,   96,
 /*   380 */    96,   27,   28,   29,  106,   51,   32,   33,   34,  106,
 /*   390 */   106,  102,   44,  104,   29,  117,   42,   43,  120,   51,
 /*   400 */    46,  107,  113,  120,  120,   92,  112,   42,   43,   55,
 /*   410 */    97,   98,   99,  100,  101,  102,  103,  104,  105,   42,
 /*   420 */    44,  137,  139,  134,  135,   45,  113,   51,   74,  108,
 /*   430 */    76,  110,   78,   79,   80,   44,   82,   83,   84,   85,
 /*   440 */    86,   87,   51,   27,   28,   48,   49,   76,   77,   52,
 /*   450 */    53,   54,   47,   56,   57,   58,   59,   60,   61,   62,
 /*   460 */    63,   64,   65,   66,   67,   68,   69,   70,   71,  107,
 /*   470 */   108,   74,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   480 */    24,   25,   26,   27,   28,   29,   30,   31,   45,   33,
 /*   490 */    34,  108,   36,  110,   38,   39,   17,   18,   19,   20,
 /*   500 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
 /*   510 */    31,   73,   33,   34,   76,   36,   45,   38,   39,   18,
 /*   520 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   530 */    29,   30,   31,   42,   33,   34,   81,   36,   43,   38,
 /*   540 */    39,   19,   20,   21,   22,   23,   24,   25,   26,   27,
 /*   550 */    28,   29,   30,   31,   45,   33,   34,   43,   36,   43,
 /*   560 */    38,   39,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   570 */    29,   30,   31,  106,   33,   34,   96,   36,   96,   38,
 /*   580 */    39,   18,   45,  116,   96,  118,  106,   45,  106,   96,
 /*   590 */    27,   28,   29,   96,  106,   32,   33,   34,   45,  106,
 /*   600 */   120,  104,  120,  106,   44,   42,   43,   51,  120,   46,
 /*   610 */   102,   43,  104,  120,  132,   44,   18,  120,   55,  137,
 /*   620 */    42,  113,   91,   44,   95,   27,   28,   29,   96,  132,
 /*   630 */    32,   33,   34,  136,  137,  138,  104,  127,  106,   76,
 /*   640 */    42,   43,  134,  135,  123,  133,  133,   84,   85,   86,
 /*   650 */   106,   90,  120,   55,   27,   28,   29,   30,   31,   43,
 /*   660 */    33,   34,   96,   36,  132,   38,   39,   42,  136,  137,
 /*   670 */   138,   96,  106,   96,   76,   86,  107,   96,   96,   50,
 /*   680 */    96,  106,   84,   85,   86,  111,  120,  106,  106,   98,
 /*   690 */    99,  100,  101,  102,  106,  120,  105,  107,  132,   92,
 /*   700 */   106,  120,  120,  137,  113,   98,   99,  100,  101,  102,
 /*   710 */   103,   42,  105,   96,  132,  124,  125,  126,   96,  137,
 /*   720 */   113,  104,   96,  106,   96,  106,  111,  130,  106,   55,
 /*   730 */   104,  108,  106,   96,  106,   96,  129,  120,   36,   46,
 /*   740 */   130,  104,  120,  106,  112,  106,  120,   96,  120,  132,
 /*   750 */   130,  104,   96,  136,  137,  138,  126,  120,  132,  120,
 /*   760 */    96,  139,  136,  137,  138,  137,  121,   96,   96,  132,
 /*   770 */   106,   96,   73,  136,  137,  138,  137,  106,  106,   96,
 /*   780 */    96,  106,   77,   96,  120,   89,   96,   96,   96,  106,
 /*   790 */   106,  120,  120,  106,   41,  120,  106,  106,  106,   96,
 /*   800 */   140,  140,  140,  120,  120,   96,   96,  120,  140,  106,
 /*   810 */   120,  120,  120,  140,   96,  106,  106,   96,   96,  140,
 /*   820 */   140,   96,  140,  120,  106,   96,  140,  106,  106,  120,
 /*   830 */   120,  106,  140,   96,   96,  106,  140,  140,  120,  140,
 /*   840 */    96,  120,  120,  106,  106,  120,   96,  140,  140,  120,
 /*   850 */   106,   96,   96,  140,  140,   96,  106,  120,  120,   96,
 /*   860 */   140,  106,  106,  140,  120,  106,  140,   96,   96,  106,
 /*   870 */   120,   96,   96,  140,   96,  120,  120,  106,  106,  120,
 /*   880 */    96,  106,  106,  120,  106,  140,  140,   96,  140,   96,
 /*   890 */   106,  120,  120,   96,  140,  120,  120,  106,  120,  106,
 /*   900 */    96,  140,   96,  106,  120,  140,  140,  140,  140,  140,
 /*   910 */   106,  120,  106,  120,  140,  140,  140,  120,  140,  140,
 /*   920 */   140,  140,  140,  140,  120,  140,  120,
};
#define YY_SHIFT_USE_DFLT (-31)
#define YY_SHIFT_COUNT (201)
#define YY_SHIFT_MIN   (-30)
#define YY_SHIFT_MAX   (753)
static const short yy_shift_ofst[] = {
 /*     0 */   753,   97,  276,  397,  233,  158,  354,  354,  354,  354,
 /*    10 */   159,  159,  563,  598,  598,  598,  598,  365,  563,  563,
 /*    20 */   598,  598,  598,  598,  598,  365,  598,  598,  598,  598,
 /*    30 */   598,  598,  598,  598,  598,  598,  598,  598,  598,  598,
 /*    40 */   598,  598,  598,  598,  598,  598,  598,  598,  598,  598,
 /*    50 */   598,  598,  598,  598,  598,  598,  598,  598,  598,  598,
 /*    60 */   598,  598,  598,  598,  598,  598,  598,  598,  598,  598,
 /*    70 */   365,  365,   92,  214,  371,  438,  705,  702,  702,  702,
 /*    80 */   589,  699,  416,  123,  240,  235,  589,  693,  693,  693,
 /*    90 */   702,  674,  669,  625,  669,  629,  625,  625,  589,  629,
 /*   100 */   589,  625,  616,  -31,  -31,  -31,  -31,  -31,  -31,   38,
 /*   110 */    -1,   77,   77,   77,   77,   77,   77,   77,   77,   77,
 /*   120 */    77,   77,   77,   77,   77,   77,   77,  105,  337,  456,
 /*   130 */   479,  501,  522,  541,  541,  266,  266,  266,  266,  627,
 /*   140 */   627,  144,  144,  160,  160,  160,  160,  160,  160,  160,
 /*   150 */   160,  160,  160,  160,  150,  178,  391,  376,  101,  348,
 /*   160 */   334,  205,  188,   67,  579,  578,  571,  568,  556,  560,
 /*   170 */   553,  542,  516,  537,  514,  455,  495,  509,  491,  471,
 /*   180 */   443,  405,  380,  377,  331,  285,  325,  306,  288,  322,
 /*   190 */   269,  256,  242,  236,  241,  200,  186,  143,   64,   44,
 /*   200 */    28,  -30,
};
#define YY_REDUCE_USE_DFLT (-98)
#define YY_REDUCE_COUNT (108)
#define YY_REDUCE_MIN   (-97)
#define YY_REDUCE_MAX   (806)
static const short yy_reduce_ofst[] = {
 /*     0 */   696,  313,  607,  591,  637,  637,  626,  617,  532,  497,
 /*    10 */   508,  289,  151,  582,  566,  482,  152,   96,  278,  157,
 /*    20 */   639,  628,  622,  284,  283,  167,  806,  804,  797,  793,
 /*    30 */   791,  784,  778,  776,  775,  772,  771,  763,  759,  756,
 /*    40 */   755,  750,  744,  738,  737,  729,  725,  722,  721,  718,
 /*    50 */   710,  709,  703,  692,  691,  690,  687,  684,  683,  675,
 /*    60 */   672,  671,  664,  581,  575,  493,  488,  480,   83,   75,
 /*    70 */   467,  192,  294,  362,  175,   18,  -97,  383,  321,  -35,
 /*    80 */   194,  228,  645,  630,  656,  647,  651,  620,  610,  597,
 /*    90 */   623,  632,  615,  619,  574,  590,  594,  588,  584,  569,
 /*   100 */   577,  544,  561,  513,  512,  510,  521,  529,  531,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   496,  410,  410,  496,  488,  488,  488,  488,  488,  488,
 /*    10 */   423,  423,  365,  488,  488,  488,  488,  496,  496,  496,
 /*    20 */   496,  496,  491,  496,  491,  496,  496,  496,  496,  496,
 /*    30 */   496,  496,  496,  496,  496,  496,  496,  496,  496,  496,
 /*    40 */   496,  496,  496,  496,  496,  496,  496,  496,  496,  496,
 /*    50 */   496,  496,  496,  496,  496,  496,  496,  496,  496,  496,
 /*    60 */   496,  496,  496,  496,  496,  496,  496,  496,  496,  496,
 /*    70 */   496,  496,  336,  336,  412,  412,  496,  349,  349,  349,
 /*    80 */   339,  496,  496,  496,  496,  496,  496,  496,  496,  496,
 /*    90 */   357,  347,  496,  496,  496,  336,  496,  496,  496,  336,
 /*   100 */   496,  496,  319,  419,  419,  402,  392,  494,  321,  496,
 /*   110 */   496,  362,  486,  485,  490,  484,  483,  482,  481,  480,
 /*   120 */   479,  478,  477,  476,  475,  474,  489,  473,  465,  466,
 /*   130 */   469,  470,  471,  462,  461,  464,  463,  460,  459,  468,
 /*   140 */   467,  456,  455,  454,  453,  452,  451,  450,  449,  448,
 /*   150 */   447,  472,  458,  457,  496,  496,  496,  496,  496,  496,
 /*   160 */   496,  496,  496,  496,  496,  496,  496,  496,  487,  496,
 /*   170 */   496,  496,  496,  496,  496,  429,  496,  496,  496,  496,
 /*   180 */   496,  496,  496,  496,  496,  496,  496,  496,  345,  354,
 /*   190 */   496,  496,  496,  496,  496,  496,  496,  496,  496,  496,
 /*   200 */   496,  496,  318,  328,  327,  326,  325,  324,  323,  322,
 /*   210 */   320,  389,  399,  397,  396,  395,  394,  393,  391,  409,
 /*   220 */   408,  407,  406,  405,  404,  403,  401,  414,  416,  415,
 /*   230 */   413,  434,  433,  432,  431,  430,  428,  421,  420,  418,
 /*   240 */   427,  426,  425,  424,  422,  417,  411,  400,  387,  386,
 /*   250 */   385,  398,  390,  384,  383,  382,  381,  380,  379,  378,
 /*   260 */   377,  376,  375,  374,  373,  372,  371,  370,  369,  368,
 /*   270 */   367,  366,  352,  359,  358,  360,  356,  364,  363,  361,
 /*   280 */   355,  440,  446,  445,  444,  443,  442,  441,  439,  438,
 /*   290 */   437,  436,  435,  353,  351,  343,  346,  342,  344,  341,
 /*   300 */   348,  340,  334,  333,  345,  350,  332,  335,  330,  338,
 /*   310 */   492,  337,  331,  329,  388,  495,  493,
};

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammar, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  YYACTIONTYPE stateno;  /* The state-number */
  YYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  YYMINORTYPE minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
#ifdef YYTRACKMAXSTACKDEPTH
  int yyidxMax;                 /* Maximum value of yyidx */
#endif
  int yyerrcnt;                 /* Shifts left before out of the error */
  snlParserARG_SDECL                /* A place to hold %extra_argument */
#if YYSTACKDEPTH<=0
  int yystksz;                  /* Current side of the stack */
  yyStackEntry *yystack;        /* The parser's stack */
#else
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
#endif
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void snlParserTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const yyTokenName[] = { 
  "$",             "EQUAL",         "ADDEQ",         "SUBEQ",       
  "ANDEQ",         "OREQ",          "DIVEQ",         "MULEQ",       
  "MODEQ",         "LSHEQ",         "RSHEQ",         "XOREQ",       
  "QUESTION",      "COLON",         "OROR",          "ANDAND",      
  "VBAR",          "CARET",         "AMPERSAND",     "EQ",          
  "NE",            "GT",            "GE",            "LE",          
  "LT",            "LSHIFT",        "RSHIFT",        "ADD",         
  "SUB",           "ASTERISK",      "SLASH",         "MOD",         
  "NOT",           "INCR",          "DECR",          "PRE",         
  "LBRACKET",      "RBRACKET",      "POINTER",       "PERIOD",      
  "POST",          "PROGRAM",       "NAME",          "LPAREN",      
  "RPAREN",        "SEMICOLON",     "LBRACE",        "RBRACE",      
  "ASSIGN",        "CONNECT",       "TO",            "COMMA",       
  "MONITOR",       "SYNC",          "SYNCQ",         "INTCON",      
  "CHAR",          "SHORT",         "INT",           "LONG",        
  "UNSIGNED",      "INT8T",         "UINT8T",        "INT16T",      
  "UINT16T",       "INT32T",        "UINT32T",       "FLOAT",       
  "DOUBLE",        "STRING",        "EVFLAG",        "FOREIGN",     
  "OPTION",        "SS",            "STATE",         "ENTRY",       
  "EXIT",          "WHEN",          "BREAK",         "CONTINUE",    
  "IF",            "ELSE",          "WHILE",         "FOR",         
  "FPCON",         "TILDE",         "STRCON",        "CCODE",       
  "error",         "program",       "program_param",  "global_defns",
  "entry",         "state_sets",    "exit",          "c_codes",     
  "string",        "global_defn",   "assign",        "monitor",     
  "sync",          "syncq",         "declaration",   "option",      
  "c_code",        "connect",       "variable",      "to",          
  "subscript",     "strings",       "opt_subscript",  "event_flag",  
  "syncq_size",    "type",          "init_declarators",  "init_declarator",
  "declarator",    "init_expr",     "direct_declarator",  "init_exprs",  
  "expr",          "option_value",  "state_set",     "ss_defns",    
  "states",        "ss_defn",       "state",         "state_defns", 
  "whens",         "state_defn",    "block",         "when",        
  "opt_expr",      "block_defns",   "statements",    "block_defn",  
  "statement",     "comma_expr",    "for_statement",  "args",        
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "program ::= PROGRAM NAME program_param global_defns entry state_sets exit c_codes",
 /*   1 */ "program_param ::= LPAREN string RPAREN",
 /*   2 */ "program_param ::=",
 /*   3 */ "global_defns ::= global_defns global_defn",
 /*   4 */ "global_defns ::=",
 /*   5 */ "global_defn ::= assign",
 /*   6 */ "global_defn ::= monitor",
 /*   7 */ "global_defn ::= sync",
 /*   8 */ "global_defn ::= syncq",
 /*   9 */ "global_defn ::= declaration",
 /*  10 */ "global_defn ::= option",
 /*  11 */ "global_defn ::= c_code",
 /*  12 */ "assign ::= connect variable to string SEMICOLON",
 /*  13 */ "assign ::= connect variable subscript to string SEMICOLON",
 /*  14 */ "assign ::= connect variable to LBRACE strings RBRACE SEMICOLON",
 /*  15 */ "assign ::= connect variable SEMICOLON",
 /*  16 */ "connect ::= ASSIGN",
 /*  17 */ "connect ::= CONNECT",
 /*  18 */ "to ::= TO",
 /*  19 */ "to ::=",
 /*  20 */ "strings ::= strings COMMA string",
 /*  21 */ "strings ::= string",
 /*  22 */ "strings ::=",
 /*  23 */ "monitor ::= MONITOR variable opt_subscript SEMICOLON",
 /*  24 */ "sync ::= SYNC variable opt_subscript to event_flag SEMICOLON",
 /*  25 */ "syncq ::= SYNCQ variable opt_subscript to event_flag syncq_size SEMICOLON",
 /*  26 */ "syncq ::= SYNCQ variable opt_subscript syncq_size SEMICOLON",
 /*  27 */ "event_flag ::= NAME",
 /*  28 */ "variable ::= NAME",
 /*  29 */ "syncq_size ::= INTCON",
 /*  30 */ "syncq_size ::=",
 /*  31 */ "opt_subscript ::= subscript",
 /*  32 */ "opt_subscript ::=",
 /*  33 */ "subscript ::= LBRACKET INTCON RBRACKET",
 /*  34 */ "declaration ::= type init_declarators SEMICOLON",
 /*  35 */ "init_declarators ::= init_declarator",
 /*  36 */ "init_declarators ::= init_declarators COMMA init_declarator",
 /*  37 */ "init_declarator ::= declarator",
 /*  38 */ "init_declarator ::= declarator EQUAL init_expr",
 /*  39 */ "declarator ::= ASTERISK declarator",
 /*  40 */ "declarator ::= direct_declarator",
 /*  41 */ "direct_declarator ::= variable",
 /*  42 */ "direct_declarator ::= LPAREN declarator RPAREN",
 /*  43 */ "direct_declarator ::= direct_declarator subscript",
 /*  44 */ "init_expr ::= LBRACE init_exprs RBRACE",
 /*  45 */ "init_expr ::= expr",
 /*  46 */ "init_exprs ::= init_exprs COMMA init_expr",
 /*  47 */ "init_exprs ::= init_expr",
 /*  48 */ "init_exprs ::=",
 /*  49 */ "type ::= CHAR",
 /*  50 */ "type ::= SHORT",
 /*  51 */ "type ::= INT",
 /*  52 */ "type ::= LONG",
 /*  53 */ "type ::= UNSIGNED CHAR",
 /*  54 */ "type ::= UNSIGNED SHORT",
 /*  55 */ "type ::= UNSIGNED INT",
 /*  56 */ "type ::= UNSIGNED LONG",
 /*  57 */ "type ::= INT8T",
 /*  58 */ "type ::= UINT8T",
 /*  59 */ "type ::= INT16T",
 /*  60 */ "type ::= UINT16T",
 /*  61 */ "type ::= INT32T",
 /*  62 */ "type ::= UINT32T",
 /*  63 */ "type ::= FLOAT",
 /*  64 */ "type ::= DOUBLE",
 /*  65 */ "type ::= STRING",
 /*  66 */ "type ::= EVFLAG",
 /*  67 */ "type ::= FOREIGN",
 /*  68 */ "option ::= OPTION option_value NAME SEMICOLON",
 /*  69 */ "option_value ::= ADD",
 /*  70 */ "option_value ::= SUB",
 /*  71 */ "state_sets ::= state_sets state_set",
 /*  72 */ "state_sets ::= state_set",
 /*  73 */ "state_set ::= SS NAME LBRACE ss_defns states RBRACE",
 /*  74 */ "ss_defns ::= ss_defns ss_defn",
 /*  75 */ "ss_defns ::=",
 /*  76 */ "ss_defn ::= assign",
 /*  77 */ "ss_defn ::= monitor",
 /*  78 */ "ss_defn ::= sync",
 /*  79 */ "ss_defn ::= syncq",
 /*  80 */ "ss_defn ::= declaration",
 /*  81 */ "states ::= states state",
 /*  82 */ "states ::= state",
 /*  83 */ "state ::= STATE NAME LBRACE state_defns entry whens exit RBRACE",
 /*  84 */ "state_defns ::= state_defns state_defn",
 /*  85 */ "state_defns ::=",
 /*  86 */ "state_defn ::= assign",
 /*  87 */ "state_defn ::= monitor",
 /*  88 */ "state_defn ::= sync",
 /*  89 */ "state_defn ::= syncq",
 /*  90 */ "state_defn ::= declaration",
 /*  91 */ "state_defn ::= option",
 /*  92 */ "entry ::= ENTRY block",
 /*  93 */ "entry ::=",
 /*  94 */ "exit ::= EXIT block",
 /*  95 */ "exit ::=",
 /*  96 */ "whens ::= whens when",
 /*  97 */ "whens ::= when",
 /*  98 */ "when ::= WHEN LPAREN opt_expr RPAREN block STATE NAME",
 /*  99 */ "when ::= WHEN LPAREN opt_expr RPAREN block EXIT",
 /* 100 */ "block ::= LBRACE block_defns statements RBRACE",
 /* 101 */ "block_defns ::= block_defns block_defn",
 /* 102 */ "block_defns ::=",
 /* 103 */ "block_defn ::= declaration",
 /* 104 */ "block_defn ::= c_code",
 /* 105 */ "statements ::= statements statement",
 /* 106 */ "statements ::=",
 /* 107 */ "statement ::= BREAK SEMICOLON",
 /* 108 */ "statement ::= CONTINUE SEMICOLON",
 /* 109 */ "statement ::= STATE NAME SEMICOLON",
 /* 110 */ "statement ::= c_code",
 /* 111 */ "statement ::= LBRACE block_defns statements RBRACE",
 /* 112 */ "statement ::= IF LPAREN comma_expr RPAREN statement",
 /* 113 */ "statement ::= IF LPAREN comma_expr RPAREN statement ELSE statement",
 /* 114 */ "statement ::= WHILE LPAREN comma_expr RPAREN statement",
 /* 115 */ "statement ::= for_statement",
 /* 116 */ "statement ::= opt_expr SEMICOLON",
 /* 117 */ "for_statement ::= FOR LPAREN opt_expr SEMICOLON opt_expr SEMICOLON opt_expr RPAREN statement",
 /* 118 */ "expr ::= INTCON",
 /* 119 */ "expr ::= FPCON",
 /* 120 */ "expr ::= string",
 /* 121 */ "expr ::= variable",
 /* 122 */ "expr ::= LPAREN comma_expr RPAREN",
 /* 123 */ "expr ::= NAME LPAREN args RPAREN",
 /* 124 */ "expr ::= EXIT LPAREN args RPAREN",
 /* 125 */ "expr ::= expr LBRACKET expr RBRACKET",
 /* 126 */ "expr ::= expr PERIOD expr",
 /* 127 */ "expr ::= expr POINTER expr",
 /* 128 */ "expr ::= expr INCR",
 /* 129 */ "expr ::= expr DECR",
 /* 130 */ "expr ::= ADD expr",
 /* 131 */ "expr ::= SUB expr",
 /* 132 */ "expr ::= ASTERISK expr",
 /* 133 */ "expr ::= AMPERSAND expr",
 /* 134 */ "expr ::= NOT expr",
 /* 135 */ "expr ::= TILDE expr",
 /* 136 */ "expr ::= INCR expr",
 /* 137 */ "expr ::= DECR expr",
 /* 138 */ "expr ::= expr SUB expr",
 /* 139 */ "expr ::= expr ADD expr",
 /* 140 */ "expr ::= expr ASTERISK expr",
 /* 141 */ "expr ::= expr SLASH expr",
 /* 142 */ "expr ::= expr GT expr",
 /* 143 */ "expr ::= expr GE expr",
 /* 144 */ "expr ::= expr EQ expr",
 /* 145 */ "expr ::= expr NE expr",
 /* 146 */ "expr ::= expr LE expr",
 /* 147 */ "expr ::= expr LT expr",
 /* 148 */ "expr ::= expr OROR expr",
 /* 149 */ "expr ::= expr ANDAND expr",
 /* 150 */ "expr ::= expr LSHIFT expr",
 /* 151 */ "expr ::= expr RSHIFT expr",
 /* 152 */ "expr ::= expr VBAR expr",
 /* 153 */ "expr ::= expr CARET expr",
 /* 154 */ "expr ::= expr AMPERSAND expr",
 /* 155 */ "expr ::= expr MOD expr",
 /* 156 */ "expr ::= expr QUESTION expr COLON expr",
 /* 157 */ "expr ::= expr EQUAL expr",
 /* 158 */ "expr ::= expr ADDEQ expr",
 /* 159 */ "expr ::= expr SUBEQ expr",
 /* 160 */ "expr ::= expr ANDEQ expr",
 /* 161 */ "expr ::= expr OREQ expr",
 /* 162 */ "expr ::= expr DIVEQ expr",
 /* 163 */ "expr ::= expr MULEQ expr",
 /* 164 */ "expr ::= expr MODEQ expr",
 /* 165 */ "expr ::= expr LSHEQ expr",
 /* 166 */ "expr ::= expr RSHEQ expr",
 /* 167 */ "expr ::= expr XOREQ expr",
 /* 168 */ "comma_expr ::= comma_expr COMMA expr",
 /* 169 */ "comma_expr ::= expr",
 /* 170 */ "opt_expr ::= comma_expr",
 /* 171 */ "opt_expr ::=",
 /* 172 */ "args ::= args COMMA expr",
 /* 173 */ "args ::= expr",
 /* 174 */ "args ::=",
 /* 175 */ "string ::= STRCON",
 /* 176 */ "c_codes ::= c_codes c_code",
 /* 177 */ "c_codes ::=",
 /* 178 */ "c_code ::= CCODE",
};
#endif /* NDEBUG */


#if YYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.
*/
static void yyGrowStack(yyParser *p){
  int newSize;
  yyStackEntry *pNew;

  newSize = p->yystksz*2 + 100;
  assert(newSize > 0);
  pNew = realloc(p->yystack, (unsigned)newSize*sizeof(pNew[0]));
  if( pNew ){
    p->yystack = pNew;
    p->yystksz = newSize;
#ifndef NDEBUG
    if( yyTraceFILE ){
      fprintf(yyTraceFILE,"%sStack grows to %d entries!\n",
              yyTracePrompt, p->yystksz);
    }
#endif
  }
}
#endif

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to snlParser and snlParserFree.
*/
void *snlParserAlloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
#ifdef YYTRACKMAXSTACKDEPTH
    pParser->yyidxMax = 0;
#endif
#if YYSTACKDEPTH<=0
    pParser->yystack = NULL;
    pParser->yystksz = 0;
    yyGrowStack(pParser);
#endif
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(
  yyParser *yypParser,    /* The parser */
  YYCODETYPE yymajor,     /* Type code for object to destroy */
  YYMINORTYPE *yypminor   /* The object to be destroyed */
){
  snlParserARG_FETCH;
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    default:  break;   /* If no destructor action specified: do nothing */
  }
  snlParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor(pParser, yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from snlParserAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void snlParserFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
  free(pParser->yystack);
#endif
  (*freeProc)((void*)pParser);
}

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef YYTRACKMAXSTACKDEPTH
int snlParserStackPeak(void *p){
  yyParser *pParser = (yyParser*)p;
  return pParser->yyidxMax;
}
#endif

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;
 
  if( stateno>YY_SHIFT_COUNT
   || (i = yy_shift_ofst[stateno])==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    if( iLookAhead>0 ){
#ifdef YYFALLBACK
      YYCODETYPE iFallback;            /* Fallback token */
      if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
             && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
             yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
        }
#endif
        return yy_find_shift_action(pParser, iFallback);
      }
#endif
#ifdef YYWILDCARD
      {
        int j = i - iLookAhead + YYWILDCARD;
        if( 
#if YY_SHIFT_MIN+YYWILDCARD<0
          j>=0 &&
#endif
#if YY_SHIFT_MAX+YYWILDCARD>=YY_ACTTAB_COUNT
          j<YY_ACTTAB_COUNT &&
#endif
          yy_lookahead[j]==YYWILDCARD
        ){
#ifndef NDEBUG
          if( yyTraceFILE ){
            fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
               yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[YYWILDCARD]);
          }
#endif /* NDEBUG */
          return yy_action[j];
        }
      }
#endif /* YYWILDCARD */
    }
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  int stateno,              /* Current state number */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef YYERRORSYMBOL
  if( stateno>YY_REDUCE_COUNT ){
    return yy_default[stateno];
  }
#else
  assert( stateno<=YY_REDUCE_COUNT );
#endif
  i = yy_reduce_ofst[stateno];
  assert( i!=YY_REDUCE_USE_DFLT );
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
#ifdef YYERRORSYMBOL
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }
#else
  assert( i>=0 && i<YY_ACTTAB_COUNT );
  assert( yy_lookahead[i]==iLookAhead );
#endif
  return yy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void yyStackOverflow(yyParser *yypParser, YYMINORTYPE *yypMinor){
   snlParserARG_FETCH;
   yypParser->yyidx--;
#ifndef NDEBUG
   if( yyTraceFILE ){
     fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
   }
#endif
   while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
   snlParserARG_STORE; /* Suppress warning about unused %extra_argument var */
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer to the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
#ifdef YYTRACKMAXSTACKDEPTH
  if( yypParser->yyidx>yypParser->yyidxMax ){
    yypParser->yyidxMax = yypParser->yyidx;
  }
#endif
#if YYSTACKDEPTH>0 
  if( yypParser->yyidx>=YYSTACKDEPTH ){
    yyStackOverflow(yypParser, yypMinor);
    return;
  }
#else
  if( yypParser->yyidx>=yypParser->yystksz ){
    yyGrowStack(yypParser);
    if( yypParser->yyidx>=yypParser->yystksz ){
      yyStackOverflow(yypParser, yypMinor);
      return;
    }
  }
#endif
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = (YYACTIONTYPE)yyNewState;
  yytos->major = (YYCODETYPE)yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static const struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 89, 8 },
  { 90, 3 },
  { 90, 0 },
  { 91, 2 },
  { 91, 0 },
  { 97, 1 },
  { 97, 1 },
  { 97, 1 },
  { 97, 1 },
  { 97, 1 },
  { 97, 1 },
  { 97, 1 },
  { 98, 5 },
  { 98, 6 },
  { 98, 7 },
  { 98, 3 },
  { 105, 1 },
  { 105, 1 },
  { 107, 1 },
  { 107, 0 },
  { 109, 3 },
  { 109, 1 },
  { 109, 0 },
  { 99, 4 },
  { 100, 6 },
  { 101, 7 },
  { 101, 5 },
  { 111, 1 },
  { 106, 1 },
  { 112, 1 },
  { 112, 0 },
  { 110, 1 },
  { 110, 0 },
  { 108, 3 },
  { 102, 3 },
  { 114, 1 },
  { 114, 3 },
  { 115, 1 },
  { 115, 3 },
  { 116, 2 },
  { 116, 1 },
  { 118, 1 },
  { 118, 3 },
  { 118, 2 },
  { 117, 3 },
  { 117, 1 },
  { 119, 3 },
  { 119, 1 },
  { 119, 0 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 113, 2 },
  { 113, 2 },
  { 113, 2 },
  { 113, 2 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 113, 1 },
  { 103, 4 },
  { 121, 1 },
  { 121, 1 },
  { 93, 2 },
  { 93, 1 },
  { 122, 6 },
  { 123, 2 },
  { 123, 0 },
  { 125, 1 },
  { 125, 1 },
  { 125, 1 },
  { 125, 1 },
  { 125, 1 },
  { 124, 2 },
  { 124, 1 },
  { 126, 8 },
  { 127, 2 },
  { 127, 0 },
  { 129, 1 },
  { 129, 1 },
  { 129, 1 },
  { 129, 1 },
  { 129, 1 },
  { 129, 1 },
  { 92, 2 },
  { 92, 0 },
  { 94, 2 },
  { 94, 0 },
  { 128, 2 },
  { 128, 1 },
  { 131, 7 },
  { 131, 6 },
  { 130, 4 },
  { 133, 2 },
  { 133, 0 },
  { 135, 1 },
  { 135, 1 },
  { 134, 2 },
  { 134, 0 },
  { 136, 2 },
  { 136, 2 },
  { 136, 3 },
  { 136, 1 },
  { 136, 4 },
  { 136, 5 },
  { 136, 7 },
  { 136, 5 },
  { 136, 1 },
  { 136, 2 },
  { 138, 9 },
  { 120, 1 },
  { 120, 1 },
  { 120, 1 },
  { 120, 1 },
  { 120, 3 },
  { 120, 4 },
  { 120, 4 },
  { 120, 4 },
  { 120, 3 },
  { 120, 3 },
  { 120, 2 },
  { 120, 2 },
  { 120, 2 },
  { 120, 2 },
  { 120, 2 },
  { 120, 2 },
  { 120, 2 },
  { 120, 2 },
  { 120, 2 },
  { 120, 2 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 5 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 120, 3 },
  { 137, 3 },
  { 137, 1 },
  { 132, 1 },
  { 132, 0 },
  { 139, 3 },
  { 139, 1 },
  { 139, 0 },
  { 96, 1 },
  { 95, 2 },
  { 95, 0 },
  { 104, 1 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  snlParserARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0 
        && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  /* Silence complaints from purify about yygotominor being uninitialized
  ** in some cases when it is copied into the stack after the following
  ** switch.  yygotominor is uninitialized when a rule reduces that does
  ** not set the value of its left-hand side nonterminal.  Leaving the
  ** value of the nonterminal uninitialized is utterly harmless as long
  ** as the value is never used.  So really the only thing this code
  ** accomplishes is to quieten purify.  
  **
  ** 2007-01-16:  The wireshark project (www.wireshark.org) reports that
  ** without this code, their parser segfaults.  I'm not sure what there
  ** parser is doing to make this happen.  This is the second bug report
  ** from wireshark this week.  Clearly they are stressing Lemon in ways
  ** that it has not been previously stressed...  (SQLite ticket #2172)
  */
  /*memset(&yygotominor, 0, sizeof(yygotominor));*/
  yygotominor = yyzerominor;


  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0: /* program ::= PROGRAM NAME program_param global_defns entry state_sets exit c_codes */
#line 94 "../snl.lem"
{
	*presult =  expr(D_PROG, yymsp[-6].minor.yy0, yymsp[-5].minor.yy202, yymsp[-4].minor.yy202, yymsp[-3].minor.yy202, yymsp[-2].minor.yy202, yymsp[-1].minor.yy202, yymsp[0].minor.yy202);
}
#line 1297 "./snl.c"
        break;
      case 1: /* program_param ::= LPAREN string RPAREN */
      case 42: /* direct_declarator ::= LPAREN declarator RPAREN */ yytestcase(yyruleno==42);
#line 98 "../snl.lem"
{ yygotominor.yy202 = yymsp[-1].minor.yy202; }
#line 1303 "./snl.c"
        break;
      case 2: /* program_param ::= */
      case 4: /* global_defns ::= */ yytestcase(yyruleno==4);
      case 22: /* strings ::= */ yytestcase(yyruleno==22);
      case 30: /* syncq_size ::= */ yytestcase(yyruleno==30);
      case 32: /* opt_subscript ::= */ yytestcase(yyruleno==32);
      case 48: /* init_exprs ::= */ yytestcase(yyruleno==48);
      case 75: /* ss_defns ::= */ yytestcase(yyruleno==75);
      case 85: /* state_defns ::= */ yytestcase(yyruleno==85);
      case 93: /* entry ::= */ yytestcase(yyruleno==93);
      case 95: /* exit ::= */ yytestcase(yyruleno==95);
      case 102: /* block_defns ::= */ yytestcase(yyruleno==102);
      case 106: /* statements ::= */ yytestcase(yyruleno==106);
      case 171: /* opt_expr ::= */ yytestcase(yyruleno==171);
      case 174: /* args ::= */ yytestcase(yyruleno==174);
      case 177: /* c_codes ::= */ yytestcase(yyruleno==177);
#line 99 "../snl.lem"
{ yygotominor.yy202 = 0; }
#line 1322 "./snl.c"
        break;
      case 3: /* global_defns ::= global_defns global_defn */
      case 84: /* state_defns ::= state_defns state_defn */ yytestcase(yyruleno==84);
      case 101: /* block_defns ::= block_defns block_defn */ yytestcase(yyruleno==101);
#line 103 "../snl.lem"
{
	yygotominor.yy202 = link_expr(yymsp[-1].minor.yy202, yymsp[0].minor.yy202);
}
#line 1331 "./snl.c"
        break;
      case 5: /* global_defn ::= assign */
      case 6: /* global_defn ::= monitor */ yytestcase(yyruleno==6);
      case 7: /* global_defn ::= sync */ yytestcase(yyruleno==7);
      case 8: /* global_defn ::= syncq */ yytestcase(yyruleno==8);
      case 9: /* global_defn ::= declaration */ yytestcase(yyruleno==9);
      case 10: /* global_defn ::= option */ yytestcase(yyruleno==10);
      case 11: /* global_defn ::= c_code */ yytestcase(yyruleno==11);
      case 21: /* strings ::= string */ yytestcase(yyruleno==21);
      case 35: /* init_declarators ::= init_declarator */ yytestcase(yyruleno==35);
      case 37: /* init_declarator ::= declarator */ yytestcase(yyruleno==37);
      case 40: /* declarator ::= direct_declarator */ yytestcase(yyruleno==40);
      case 45: /* init_expr ::= expr */ yytestcase(yyruleno==45);
      case 47: /* init_exprs ::= init_expr */ yytestcase(yyruleno==47);
      case 72: /* state_sets ::= state_set */ yytestcase(yyruleno==72);
      case 76: /* ss_defn ::= assign */ yytestcase(yyruleno==76);
      case 77: /* ss_defn ::= monitor */ yytestcase(yyruleno==77);
      case 78: /* ss_defn ::= sync */ yytestcase(yyruleno==78);
      case 79: /* ss_defn ::= syncq */ yytestcase(yyruleno==79);
      case 80: /* ss_defn ::= declaration */ yytestcase(yyruleno==80);
      case 82: /* states ::= state */ yytestcase(yyruleno==82);
      case 86: /* state_defn ::= assign */ yytestcase(yyruleno==86);
      case 87: /* state_defn ::= monitor */ yytestcase(yyruleno==87);
      case 88: /* state_defn ::= sync */ yytestcase(yyruleno==88);
      case 89: /* state_defn ::= syncq */ yytestcase(yyruleno==89);
      case 90: /* state_defn ::= declaration */ yytestcase(yyruleno==90);
      case 91: /* state_defn ::= option */ yytestcase(yyruleno==91);
      case 97: /* whens ::= when */ yytestcase(yyruleno==97);
      case 103: /* block_defn ::= declaration */ yytestcase(yyruleno==103);
      case 104: /* block_defn ::= c_code */ yytestcase(yyruleno==104);
      case 110: /* statement ::= c_code */ yytestcase(yyruleno==110);
      case 115: /* statement ::= for_statement */ yytestcase(yyruleno==115);
      case 120: /* expr ::= string */ yytestcase(yyruleno==120);
      case 169: /* comma_expr ::= expr */ yytestcase(yyruleno==169);
      case 170: /* opt_expr ::= comma_expr */ yytestcase(yyruleno==170);
      case 173: /* args ::= expr */ yytestcase(yyruleno==173);
#line 108 "../snl.lem"
{ yygotominor.yy202 = yymsp[0].minor.yy202; }
#line 1370 "./snl.c"
        break;
      case 12: /* assign ::= connect variable to string SEMICOLON */
#line 116 "../snl.lem"
{
	yygotominor.yy202 = expr(D_ASSIGN, yymsp[-3].minor.yy98, 0, yymsp[-1].minor.yy202);
}
#line 1377 "./snl.c"
        break;
      case 13: /* assign ::= connect variable subscript to string SEMICOLON */
#line 119 "../snl.lem"
{
	yygotominor.yy202 = expr(D_ASSIGN, yymsp[-4].minor.yy98, expr(E_CONST, yymsp[-3].minor.yy98), yymsp[-1].minor.yy202);
}
#line 1384 "./snl.c"
        break;
      case 14: /* assign ::= connect variable to LBRACE strings RBRACE SEMICOLON */
#line 122 "../snl.lem"
{
	yygotominor.yy202 = expr(D_ASSIGN, yymsp[-5].minor.yy98, 0, expr(E_INIT, yymsp[-3].minor.yy0, yymsp[-2].minor.yy202));
}
#line 1391 "./snl.c"
        break;
      case 15: /* assign ::= connect variable SEMICOLON */
#line 125 "../snl.lem"
{
	yygotominor.yy202 = expr(D_ASSIGN, yymsp[-1].minor.yy98, 0, 0);
}
#line 1398 "./snl.c"
        break;
      case 20: /* strings ::= strings COMMA string */
      case 36: /* init_declarators ::= init_declarators COMMA init_declarator */ yytestcase(yyruleno==36);
      case 46: /* init_exprs ::= init_exprs COMMA init_expr */ yytestcase(yyruleno==46);
      case 172: /* args ::= args COMMA expr */ yytestcase(yyruleno==172);
#line 135 "../snl.lem"
{ yygotominor.yy202 = link_expr(yymsp[-2].minor.yy202, yymsp[0].minor.yy202); }
#line 1406 "./snl.c"
        break;
      case 23: /* monitor ::= MONITOR variable opt_subscript SEMICOLON */
#line 139 "../snl.lem"
{
	yygotominor.yy202 = expr(D_MONITOR, yymsp[-2].minor.yy98, yymsp[-1].minor.yy202);
}
#line 1413 "./snl.c"
        break;
      case 24: /* sync ::= SYNC variable opt_subscript to event_flag SEMICOLON */
#line 143 "../snl.lem"
{
	yygotominor.yy202 = expr(D_SYNC, yymsp[-4].minor.yy98, yymsp[-3].minor.yy202, expr(E_VAR, yymsp[-1].minor.yy98), 0);
}
#line 1420 "./snl.c"
        break;
      case 25: /* syncq ::= SYNCQ variable opt_subscript to event_flag syncq_size SEMICOLON */
#line 147 "../snl.lem"
{
	yygotominor.yy202 = expr(D_SYNCQ, yymsp[-5].minor.yy98, yymsp[-4].minor.yy202, expr(E_VAR, yymsp[-2].minor.yy98), yymsp[-1].minor.yy202);
}
#line 1427 "./snl.c"
        break;
      case 26: /* syncq ::= SYNCQ variable opt_subscript syncq_size SEMICOLON */
#line 151 "../snl.lem"
{
	yygotominor.yy202 = expr(D_SYNCQ, yymsp[-3].minor.yy98, yymsp[-2].minor.yy202, 0, yymsp[-1].minor.yy202);
}
#line 1434 "./snl.c"
        break;
      case 27: /* event_flag ::= NAME */
      case 28: /* variable ::= NAME */ yytestcase(yyruleno==28);
      case 69: /* option_value ::= ADD */ yytestcase(yyruleno==69);
      case 70: /* option_value ::= SUB */ yytestcase(yyruleno==70);
#line 156 "../snl.lem"
{ yygotominor.yy98 = yymsp[0].minor.yy0; }
#line 1442 "./snl.c"
        break;
      case 29: /* syncq_size ::= INTCON */
      case 118: /* expr ::= INTCON */ yytestcase(yyruleno==118);
      case 119: /* expr ::= FPCON */ yytestcase(yyruleno==119);
#line 160 "../snl.lem"
{ yygotominor.yy202 = expr(E_CONST, yymsp[0].minor.yy0); }
#line 1449 "./snl.c"
        break;
      case 31: /* opt_subscript ::= subscript */
#line 163 "../snl.lem"
{ yygotominor.yy202 = expr(E_CONST, yymsp[0].minor.yy98); }
#line 1454 "./snl.c"
        break;
      case 33: /* subscript ::= LBRACKET INTCON RBRACKET */
#line 167 "../snl.lem"
{ yygotominor.yy98 = yymsp[-1].minor.yy0; }
#line 1459 "./snl.c"
        break;
      case 34: /* declaration ::= type init_declarators SEMICOLON */
#line 172 "../snl.lem"
{ yygotominor.yy202 = decl_add_base_type(yymsp[-1].minor.yy202, yymsp[-2].minor.yy172); }
#line 1464 "./snl.c"
        break;
      case 38: /* init_declarator ::= declarator EQUAL init_expr */
#line 180 "../snl.lem"
{ yygotominor.yy202 = decl_add_init(yymsp[-2].minor.yy202, yymsp[0].minor.yy202); }
#line 1469 "./snl.c"
        break;
      case 39: /* declarator ::= ASTERISK declarator */
#line 182 "../snl.lem"
{ yygotominor.yy202 = decl_prefix_pointer(yymsp[0].minor.yy202); }
#line 1474 "./snl.c"
        break;
      case 41: /* direct_declarator ::= variable */
#line 185 "../snl.lem"
{ yygotominor.yy202 = decl_create(yymsp[0].minor.yy98); }
#line 1479 "./snl.c"
        break;
      case 43: /* direct_declarator ::= direct_declarator subscript */
#line 189 "../snl.lem"
{ yygotominor.yy202 = decl_postfix_array(yymsp[-1].minor.yy202, yymsp[0].minor.yy98.str); }
#line 1484 "./snl.c"
        break;
      case 44: /* init_expr ::= LBRACE init_exprs RBRACE */
#line 193 "../snl.lem"
{ yygotominor.yy202 = expr(E_INIT, yymsp[-2].minor.yy0, yymsp[-1].minor.yy202); }
#line 1489 "./snl.c"
        break;
      case 49: /* type ::= CHAR */
#line 201 "../snl.lem"
{ yygotominor.yy172 = V_CHAR;	}
#line 1494 "./snl.c"
        break;
      case 50: /* type ::= SHORT */
#line 202 "../snl.lem"
{ yygotominor.yy172 = V_SHORT;	}
#line 1499 "./snl.c"
        break;
      case 51: /* type ::= INT */
#line 203 "../snl.lem"
{ yygotominor.yy172 = V_INT;	}
#line 1504 "./snl.c"
        break;
      case 52: /* type ::= LONG */
#line 204 "../snl.lem"
{ yygotominor.yy172 = V_LONG;	}
#line 1509 "./snl.c"
        break;
      case 53: /* type ::= UNSIGNED CHAR */
#line 205 "../snl.lem"
{ yygotominor.yy172 = V_UCHAR;	}
#line 1514 "./snl.c"
        break;
      case 54: /* type ::= UNSIGNED SHORT */
#line 206 "../snl.lem"
{ yygotominor.yy172 = V_USHORT;	}
#line 1519 "./snl.c"
        break;
      case 55: /* type ::= UNSIGNED INT */
#line 207 "../snl.lem"
{ yygotominor.yy172 = V_UINT;	}
#line 1524 "./snl.c"
        break;
      case 56: /* type ::= UNSIGNED LONG */
#line 208 "../snl.lem"
{ yygotominor.yy172 = V_ULONG;	}
#line 1529 "./snl.c"
        break;
      case 57: /* type ::= INT8T */
#line 210 "../snl.lem"
{ yygotominor.yy172 = V_INT8T;	}
#line 1534 "./snl.c"
        break;
      case 58: /* type ::= UINT8T */
#line 211 "../snl.lem"
{ yygotominor.yy172 = V_UINT8T;	}
#line 1539 "./snl.c"
        break;
      case 59: /* type ::= INT16T */
#line 212 "../snl.lem"
{ yygotominor.yy172 = V_INT16T;	}
#line 1544 "./snl.c"
        break;
      case 60: /* type ::= UINT16T */
#line 213 "../snl.lem"
{ yygotominor.yy172 = V_UINT16T;}
#line 1549 "./snl.c"
        break;
      case 61: /* type ::= INT32T */
#line 214 "../snl.lem"
{ yygotominor.yy172 = V_INT32T;	}
#line 1554 "./snl.c"
        break;
      case 62: /* type ::= UINT32T */
#line 215 "../snl.lem"
{ yygotominor.yy172 = V_UINT32T;}
#line 1559 "./snl.c"
        break;
      case 63: /* type ::= FLOAT */
#line 217 "../snl.lem"
{ yygotominor.yy172 = V_FLOAT;	}
#line 1564 "./snl.c"
        break;
      case 64: /* type ::= DOUBLE */
#line 218 "../snl.lem"
{ yygotominor.yy172 = V_DOUBLE;	}
#line 1569 "./snl.c"
        break;
      case 65: /* type ::= STRING */
#line 219 "../snl.lem"
{ yygotominor.yy172 = V_STRING;	}
#line 1574 "./snl.c"
        break;
      case 66: /* type ::= EVFLAG */
#line 220 "../snl.lem"
{ yygotominor.yy172 = V_EVFLAG;	}
#line 1579 "./snl.c"
        break;
      case 67: /* type ::= FOREIGN */
#line 221 "../snl.lem"
{ yygotominor.yy172 = V_NONE;	}
#line 1584 "./snl.c"
        break;
      case 68: /* option ::= OPTION option_value NAME SEMICOLON */
#line 226 "../snl.lem"
{ yygotominor.yy202 = opt_defn(yymsp[-1].minor.yy0, yymsp[-2].minor.yy98); }
#line 1589 "./snl.c"
        break;
      case 71: /* state_sets ::= state_sets state_set */
      case 74: /* ss_defns ::= ss_defns ss_defn */ yytestcase(yyruleno==74);
      case 81: /* states ::= states state */ yytestcase(yyruleno==81);
      case 96: /* whens ::= whens when */ yytestcase(yyruleno==96);
      case 105: /* statements ::= statements statement */ yytestcase(yyruleno==105);
      case 176: /* c_codes ::= c_codes c_code */ yytestcase(yyruleno==176);
#line 234 "../snl.lem"
{ yygotominor.yy202 = link_expr(yymsp[-1].minor.yy202, yymsp[0].minor.yy202); }
#line 1599 "./snl.c"
        break;
      case 73: /* state_set ::= SS NAME LBRACE ss_defns states RBRACE */
#line 238 "../snl.lem"
{ yygotominor.yy202 = expr(D_SS, yymsp[-4].minor.yy0, yymsp[-2].minor.yy202, yymsp[-1].minor.yy202); }
#line 1604 "./snl.c"
        break;
      case 83: /* state ::= STATE NAME LBRACE state_defns entry whens exit RBRACE */
#line 255 "../snl.lem"
{
	yygotominor.yy202 = expr(D_STATE, yymsp[-6].minor.yy0, yymsp[-4].minor.yy202, yymsp[-3].minor.yy202, yymsp[-2].minor.yy202, yymsp[-1].minor.yy202);
}
#line 1611 "./snl.c"
        break;
      case 92: /* entry ::= ENTRY block */
#line 271 "../snl.lem"
{ yygotominor.yy202 = expr(D_ENTRY, yymsp[-1].minor.yy0, yymsp[0].minor.yy44.left, yymsp[0].minor.yy44.right); }
#line 1616 "./snl.c"
        break;
      case 94: /* exit ::= EXIT block */
#line 274 "../snl.lem"
{ yygotominor.yy202 = expr(D_EXIT, yymsp[-1].minor.yy0, yymsp[0].minor.yy44.left, yymsp[0].minor.yy44.right); }
#line 1621 "./snl.c"
        break;
      case 98: /* when ::= WHEN LPAREN opt_expr RPAREN block STATE NAME */
#line 280 "../snl.lem"
{
	yymsp[-6].minor.yy0.str = yymsp[0].minor.yy0.str;
	yygotominor.yy202 = expr(D_WHEN, yymsp[-6].minor.yy0, yymsp[-4].minor.yy202, yymsp[-2].minor.yy44.left, yymsp[-2].minor.yy44.right);
}
#line 1629 "./snl.c"
        break;
      case 99: /* when ::= WHEN LPAREN opt_expr RPAREN block EXIT */
#line 285 "../snl.lem"
{
	yymsp[-5].minor.yy0.str = 0;
	yygotominor.yy202 = expr(D_WHEN, yymsp[-5].minor.yy0, yymsp[-3].minor.yy202, yymsp[-1].minor.yy44.left, yymsp[-1].minor.yy44.right);
}
#line 1637 "./snl.c"
        break;
      case 100: /* block ::= LBRACE block_defns statements RBRACE */
#line 291 "../snl.lem"
{
	yygotominor.yy44.left = yymsp[-2].minor.yy202; yygotominor.yy44.right = yymsp[-1].minor.yy202;
}
#line 1644 "./snl.c"
        break;
      case 107: /* statement ::= BREAK SEMICOLON */
      case 108: /* statement ::= CONTINUE SEMICOLON */ yytestcase(yyruleno==108);
#line 308 "../snl.lem"
{ yygotominor.yy202 = expr(S_JUMP, yymsp[-1].minor.yy0); }
#line 1650 "./snl.c"
        break;
      case 109: /* statement ::= STATE NAME SEMICOLON */
#line 310 "../snl.lem"
{ yygotominor.yy202 = expr(S_CHANGE, yymsp[-1].minor.yy0); }
#line 1655 "./snl.c"
        break;
      case 111: /* statement ::= LBRACE block_defns statements RBRACE */
#line 313 "../snl.lem"
{ yygotominor.yy202 = expr(S_CMPND, yymsp[-3].minor.yy0, yymsp[-2].minor.yy202, yymsp[-1].minor.yy202); }
#line 1660 "./snl.c"
        break;
      case 112: /* statement ::= IF LPAREN comma_expr RPAREN statement */
#line 315 "../snl.lem"
{ yygotominor.yy202 = expr(S_IF, yymsp[-4].minor.yy0, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0); }
#line 1665 "./snl.c"
        break;
      case 113: /* statement ::= IF LPAREN comma_expr RPAREN statement ELSE statement */
#line 317 "../snl.lem"
{ yygotominor.yy202 = expr(S_IF, yymsp[-6].minor.yy0, yymsp[-4].minor.yy202, yymsp[-2].minor.yy202, yymsp[0].minor.yy202); }
#line 1670 "./snl.c"
        break;
      case 114: /* statement ::= WHILE LPAREN comma_expr RPAREN statement */
#line 319 "../snl.lem"
{ yygotominor.yy202 = expr(S_WHILE, yymsp[-4].minor.yy0, yymsp[-2].minor.yy202, yymsp[0].minor.yy202); }
#line 1675 "./snl.c"
        break;
      case 116: /* statement ::= opt_expr SEMICOLON */
#line 321 "../snl.lem"
{ yygotominor.yy202 = expr(S_STMT, yymsp[0].minor.yy0, yymsp[-1].minor.yy202); }
#line 1680 "./snl.c"
        break;
      case 117: /* for_statement ::= FOR LPAREN opt_expr SEMICOLON opt_expr SEMICOLON opt_expr RPAREN statement */
#line 326 "../snl.lem"
{ yygotominor.yy202 = expr(S_FOR, yymsp[-8].minor.yy0, yymsp[-6].minor.yy202, yymsp[-4].minor.yy202, yymsp[-2].minor.yy202, yymsp[0].minor.yy202); }
#line 1685 "./snl.c"
        break;
      case 121: /* expr ::= variable */
#line 338 "../snl.lem"
{ yygotominor.yy202 = expr(E_VAR, yymsp[0].minor.yy98); }
#line 1690 "./snl.c"
        break;
      case 122: /* expr ::= LPAREN comma_expr RPAREN */
#line 341 "../snl.lem"
{ yygotominor.yy202 = expr(E_PAREN, yymsp[-2].minor.yy0, yymsp[-1].minor.yy202); }
#line 1695 "./snl.c"
        break;
      case 123: /* expr ::= NAME LPAREN args RPAREN */
      case 124: /* expr ::= EXIT LPAREN args RPAREN */ yytestcase(yyruleno==124);
#line 344 "../snl.lem"
{ yygotominor.yy202 = expr(E_FUNC,   yymsp[-3].minor.yy0, yymsp[-1].minor.yy202); }
#line 1701 "./snl.c"
        break;
      case 125: /* expr ::= expr LBRACKET expr RBRACKET */
#line 346 "../snl.lem"
{ yygotominor.yy202 = expr(E_SUBSCR, yymsp[-2].minor.yy0, yymsp[-3].minor.yy202, yymsp[-1].minor.yy202); }
#line 1706 "./snl.c"
        break;
      case 126: /* expr ::= expr PERIOD expr */
      case 127: /* expr ::= expr POINTER expr */ yytestcase(yyruleno==127);
#line 347 "../snl.lem"
{ yygotominor.yy202 = expr(E_BINOP,  yymsp[-1].minor.yy0, yymsp[-2].minor.yy202, yymsp[0].minor.yy202); }
#line 1712 "./snl.c"
        break;
      case 128: /* expr ::= expr INCR */
      case 129: /* expr ::= expr DECR */ yytestcase(yyruleno==129);
#line 349 "../snl.lem"
{ yygotominor.yy202 = expr(E_POST,   yymsp[0].minor.yy0, yymsp[-1].minor.yy202); }
#line 1718 "./snl.c"
        break;
      case 130: /* expr ::= ADD expr */
      case 131: /* expr ::= SUB expr */ yytestcase(yyruleno==131);
      case 132: /* expr ::= ASTERISK expr */ yytestcase(yyruleno==132);
      case 133: /* expr ::= AMPERSAND expr */ yytestcase(yyruleno==133);
      case 134: /* expr ::= NOT expr */ yytestcase(yyruleno==134);
      case 135: /* expr ::= TILDE expr */ yytestcase(yyruleno==135);
      case 136: /* expr ::= INCR expr */ yytestcase(yyruleno==136);
      case 137: /* expr ::= DECR expr */ yytestcase(yyruleno==137);
#line 353 "../snl.lem"
{ yygotominor.yy202 = expr(E_PRE, yymsp[-1].minor.yy0, yymsp[0].minor.yy202); }
#line 1730 "./snl.c"
        break;
      case 138: /* expr ::= expr SUB expr */
      case 139: /* expr ::= expr ADD expr */ yytestcase(yyruleno==139);
      case 140: /* expr ::= expr ASTERISK expr */ yytestcase(yyruleno==140);
      case 141: /* expr ::= expr SLASH expr */ yytestcase(yyruleno==141);
      case 142: /* expr ::= expr GT expr */ yytestcase(yyruleno==142);
      case 143: /* expr ::= expr GE expr */ yytestcase(yyruleno==143);
      case 144: /* expr ::= expr EQ expr */ yytestcase(yyruleno==144);
      case 145: /* expr ::= expr NE expr */ yytestcase(yyruleno==145);
      case 146: /* expr ::= expr LE expr */ yytestcase(yyruleno==146);
      case 147: /* expr ::= expr LT expr */ yytestcase(yyruleno==147);
      case 148: /* expr ::= expr OROR expr */ yytestcase(yyruleno==148);
      case 149: /* expr ::= expr ANDAND expr */ yytestcase(yyruleno==149);
      case 150: /* expr ::= expr LSHIFT expr */ yytestcase(yyruleno==150);
      case 151: /* expr ::= expr RSHIFT expr */ yytestcase(yyruleno==151);
      case 152: /* expr ::= expr VBAR expr */ yytestcase(yyruleno==152);
      case 153: /* expr ::= expr CARET expr */ yytestcase(yyruleno==153);
      case 154: /* expr ::= expr AMPERSAND expr */ yytestcase(yyruleno==154);
      case 155: /* expr ::= expr MOD expr */ yytestcase(yyruleno==155);
      case 157: /* expr ::= expr EQUAL expr */ yytestcase(yyruleno==157);
      case 158: /* expr ::= expr ADDEQ expr */ yytestcase(yyruleno==158);
      case 159: /* expr ::= expr SUBEQ expr */ yytestcase(yyruleno==159);
      case 160: /* expr ::= expr ANDEQ expr */ yytestcase(yyruleno==160);
      case 161: /* expr ::= expr OREQ expr */ yytestcase(yyruleno==161);
      case 162: /* expr ::= expr DIVEQ expr */ yytestcase(yyruleno==162);
      case 163: /* expr ::= expr MULEQ expr */ yytestcase(yyruleno==163);
      case 164: /* expr ::= expr MODEQ expr */ yytestcase(yyruleno==164);
      case 165: /* expr ::= expr LSHEQ expr */ yytestcase(yyruleno==165);
      case 166: /* expr ::= expr RSHEQ expr */ yytestcase(yyruleno==166);
      case 167: /* expr ::= expr XOREQ expr */ yytestcase(yyruleno==167);
      case 168: /* comma_expr ::= comma_expr COMMA expr */ yytestcase(yyruleno==168);
#line 363 "../snl.lem"
{ yygotominor.yy202 = expr(E_BINOP, yymsp[-1].minor.yy0, yymsp[-2].minor.yy202, yymsp[0].minor.yy202); }
#line 1764 "./snl.c"
        break;
      case 156: /* expr ::= expr QUESTION expr COLON expr */
#line 384 "../snl.lem"
{ yygotominor.yy202 = expr(E_TERNOP, yymsp[-3].minor.yy0, yymsp[-4].minor.yy202, yymsp[-2].minor.yy202, yymsp[0].minor.yy202); }
#line 1769 "./snl.c"
        break;
      case 175: /* string ::= STRCON */
#line 412 "../snl.lem"
{ yygotominor.yy202 = expr(E_STRING, yymsp[0].minor.yy0); }
#line 1774 "./snl.c"
        break;
      case 178: /* c_code ::= CCODE */
#line 419 "../snl.lem"
{ yygotominor.yy202 = expr(T_TEXT, yymsp[0].minor.yy0); }
#line 1779 "./snl.c"
        break;
      default:
      /* (16) connect ::= ASSIGN */ yytestcase(yyruleno==16);
      /* (17) connect ::= CONNECT */ yytestcase(yyruleno==17);
      /* (18) to ::= TO */ yytestcase(yyruleno==18);
      /* (19) to ::= */ yytestcase(yyruleno==19);
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(YYCODETYPE)yygoto);
  if( yyact < YYNSTATE ){
#ifdef NDEBUG
    /* If we are not debugging and the reduce action popped at least
    ** one element off the stack, then we can push the new element back
    ** onto the stack here, and skip the stack overflow test in yy_shift().
    ** That gives a significant speed improvement. */
    if( yysize ){
      yypParser->yyidx++;
      yymsp -= yysize-1;
      yymsp->stateno = (YYACTIONTYPE)yyact;
      yymsp->major = (YYCODETYPE)yygoto;
      yymsp->minor = yygotominor;
    }else
#endif
    {
      yy_shift(yypParser,yyact,yygoto,&yygotominor);
    }
  }else{
    assert( yyact == YYNSTATE + YYNRULE + 1 );
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
#ifndef YYNOERRORRECOVERY
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  snlParserARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
#line 24 "../snl.lem"

	report("parser giving up\n");
	exit(1);
#line 1835 "./snl.c"
  snlParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}
#endif /* YYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  snlParserARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 29 "../snl.lem"

	error_at(TOKEN.file, TOKEN.line,
		"syntax error near token '%s'\n", TOKEN.str);
#line 1854 "./snl.c"
  snlParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  snlParserARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  snlParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "snlParserAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void snlParser(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  snlParserTOKENTYPE yyminor       /* The value for the token */
  snlParserARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
#ifdef YYERRORSYMBOL
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
#endif
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
#if YYSTACKDEPTH<=0
    if( yypParser->yystksz <=0 ){
      /*memset(&yyminorunion, 0, sizeof(yyminorunion));*/
      yyminorunion = yyzerominor;
      yyStackOverflow(yypParser, &yyminorunion);
      return;
    }
#endif
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  snlParserARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,(YYCODETYPE)yymajor);
    if( yyact<YYNSTATE ){
      assert( !yyendofinput );  /* Impossible to shift the $ token */
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      yymajor = YYNOCODE;
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
    }else{
#ifdef YYERRORSYMBOL
      int yymx;
#endif
      assert( yyact == YY_ERROR_ACTION );
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yypParser, (YYCODETYPE)yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_reduce_action(
                        yypParser->yystack[yypParser->yyidx].stateno,
                        YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#elif defined(YYNOERRORRECOVERY)
      /* If the YYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      yy_syntax_error(yypParser,yymajor,yyminorunion);
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      yymajor = YYNOCODE;
      
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}
