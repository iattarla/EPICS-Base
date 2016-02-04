/* A lexical scanner generated by flex */

/* scanner skeleton version:
 * Revision-Id: anj@aps.anl.gov-20101005192737-disfz3vs0f3fiixd
 */

/* modified by Jim Kowalkowski to have everything declared static */

#define FLEX_SCANNER

#include <stdio.h>
#include <stdlib.h>

/* amount of stuff to slurp up with each read */
#ifndef YY_READ_BUF_SIZE
#define YY_READ_BUF_SIZE 8192
#endif

/* returned upon end-of-file */
#define YY_END_TOK 0

/* copy whatever the last rule matched to the standard output */

/* cast to (char *) is because for 8-bit chars, yytext is (unsigned char *) */
/* this used to be an fputs(), but since the string might contain NUL's,
 * we now use fwrite()
 */
#define ECHO (void) fwrite( (char *) yytext, yyleng, 1, yyout )

/* gets input and stuffs it into "buf".  number of characters read, or YY_NULL,
 * is returned in "result".
 */
#define YY_INPUT(buf,result,max_size) \
	if ( (result = read( fileno(yyin), (char *) buf, max_size )) < 0 ) \
	    YY_FATAL_ERROR( "read() in flex scanner failed" );
#define YY_NULL 0

/* no semi-colon after return; correct usage is to write "yyterminate();" -
 * we don't want an extra ';' after the "return" because that will cause
 * some compilers to complain about unreachable statements.
 */

/* #define yyterminate() return ( YY_NULL )  replaced by jbk */
static int yyterminate_internal( void );
#define yyterminate() return yyterminate_internal()

/* report a fatal error */

/* The funky do-while is used to turn this macro definition into
 * a single C statement (which needs a semi-colon terminator).
 * This avoids problems with code like:
 *
 * 	if ( something_happens )
 *		YY_FATAL_ERROR( "oops, the something happened" );
 *	else
 *		everything_okay();
 *
 * Prior to using the do-while the compiler would get upset at the
 * "else" because it interpreted the "if" statement as being all
 * done when it reached the ';' after the YY_FATAL_ERROR() call.
 */

#define YY_FATAL_ERROR(msg) \
	do \
		{ \
		(void) fputs( msg, stderr ); \
		(void) putc( '\n', stderr ); \
		exit( 1 ); \
		} \
	while ( 0 )

/* default yywrap function - always treat EOF as an EOF */
#define yywrap() 1

/* enter a start condition.  This macro really ought to take a parameter,
 * but we do it the disgusting crufty way forced on us by the ()-less
 * definition of BEGIN
 */
#define BEGIN yy_start = 1 + 2 *

/* action number for EOF rule of a given start state */
#define YY_STATE_EOF(state) (YY_END_OF_BUFFER + state + 1)

/* special action meaning "start processing a new file" */
#define YY_NEW_FILE \
	do \
		{ \
		yy_init_buffer( yy_current_buffer, yyin ); \
		yy_load_buffer_state(); \
		} \
	while ( 0 )

/* default declaration of generated scanner - a define so the user can
 * easily add parameters - jbk added the static to YY_DECL
 */
#define YY_DECL static int yylex ( void ) 

/* code executed at the end of each rule */
#define YY_BREAK break;

#define YY_END_OF_BUFFER_CHAR 0

#ifndef YY_BUF_SIZE
#define YY_BUF_SIZE (YY_READ_BUF_SIZE * 2) /* size of default input buffer */
#endif

typedef struct yy_buffer_state *YY_BUFFER_STATE;

#define YY_CHAR unsigned char
# line 1 "../dbLex.l"
#define INITIAL 0
/*************************************************************************\
* Copyright (c) 2009 UChicago Argonne LLC, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/
# line 19 "../dbLex.l"
#undef YY_INPUT
#define YY_INPUT(b,r,ms) (r=(*db_yyinput)((char *)b,ms))

static int yyreset(void)
{
	BEGIN INITIAL;
	return(0);
}

# line 30 "../dbLex.l"

/* done after the current pattern has been matched and before the
 * corresponding action - sets up yytext
 */
#define YY_DO_BEFORE_ACTION \
	yytext = yy_bp; \
	yyleng = yy_cp - yy_bp; \
	yy_hold_char = *yy_cp; \
	*yy_cp = '\0'; \
	yy_c_buf_p = yy_cp;

#define EOB_ACT_CONTINUE_SCAN 0
#define EOB_ACT_END_OF_FILE 1
#define EOB_ACT_LAST_MATCH 2

/* return all but the first 'n' matched characters back to the input stream */
#define yyless(n) \
	do \
		{ \
		/* undo effects of setting up yytext */ \
		*yy_cp = yy_hold_char; \
		yy_c_buf_p = yy_cp = yy_bp + n; \
		YY_DO_BEFORE_ACTION; /* set up yytext again */ \
		} \
	while ( 0 )

#define unput(c) yyunput( c, yytext )


struct yy_buffer_state
    {
    FILE *yy_input_file;

    YY_CHAR *yy_ch_buf;		/* input buffer */
    YY_CHAR *yy_buf_pos;	/* current position in input buffer */

    /* size of input buffer in bytes, not including room for EOB characters */
    int yy_buf_size;	

    /* number of characters read into yy_ch_buf, not including EOB characters */
    int yy_n_chars;

    int yy_eof_status;		/* whether we've seen an EOF on this buffer */
#define EOF_NOT_SEEN 0
    /* "pending" happens when the EOF has been seen but there's still
     * some text process
     */
#define EOF_PENDING 1
#define EOF_DONE 2
    };

static YY_BUFFER_STATE yy_current_buffer;

/* we provide macros for accessing buffer states in case in the
 * future we want to put the buffer states in a more general
 * "scanner state"
 */
#define YY_CURRENT_BUFFER yy_current_buffer


/* yy_hold_char holds the character lost when yytext is formed */
static YY_CHAR yy_hold_char;

static int yy_n_chars;		/* number of characters read into yy_ch_buf */



#ifndef YY_USER_ACTION
#define YY_USER_ACTION
#endif

#ifndef YY_USER_INIT
#define YY_USER_INIT
#endif

/* jbk update
extern YY_CHAR *yytext;
extern int yyleng;
extern FILE *yyin, *yyout;
*/

static YY_CHAR *yytext; /* jbk added static */
static int yyleng; /* jbk added static */

static FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0; /* jbk added static */

#define YY_END_OF_BUFFER 31
typedef int yy_state_type;
static const short int yy_accept[123] =
    {   0,
        0,    0,   31,   29,   27,   27,   29,   26,   20,   23,
       24,   18,   25,   18,   18,   18,   18,   18,   18,   18,
       18,   18,   18,   18,   21,   22,    0,   28,   19,    0,
       26,   20,   18,   18,   18,   18,   18,   18,   18,   18,
       18,   18,   18,   18,   18,   18,   18,   18,   18,   18,
       18,   18,   18,   18,   18,   18,   18,   18,   18,   18,
       18,   18,   18,   18,   18,   18,   18,   18,   18,   18,
       18,   18,   18,   14,    4,    2,   18,   18,   18,   18,
       13,   18,   18,   18,   18,    7,   18,   18,   18,   18,
       18,   18,   18,   18,    5,    8,    9,   18,   18,   18,

       11,   18,   18,    3,   18,   18,   12,    1,   18,   18,
       18,   18,   16,   18,   18,   17,   18,   18,   15,   10,
        6,    0
    } ;

static const YY_CHAR yy_ec[256] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    2,    3,
        1,    1,    2,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    2,    1,    4,    5,    1,    6,    1,    1,    7,
        8,    1,    9,   10,    9,    9,    1,    9,    9,    9,
        9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
        1,    9,    1,    1,    9,    9,    9,    9,    9,    9,
        9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
        9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
        9,   11,    9,    1,    9,    1,   12,   13,   14,   15,

       16,   17,   18,   19,   20,    9,   21,   22,   23,   24,
       25,   26,    9,   27,   28,   29,   30,   31,    9,    9,
       32,    9,   33,    1,   34,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,

        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1
    } ;

static const YY_CHAR yy_meta[35] =
    {   0,
        1,    1,    2,    1,    1,    1,    1,    1,    3,    1,
        1,    3,    3,    3,    3,    3,    3,    3,    3,    3,
        3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
        3,    3,    1,    1
    } ;

static const short int yy_base[127] =
    {   0,
        0,    0,  138,  139,  139,  139,   32,    0,    0,  139,
      139,    0,  139,   22,  110,  117,   22,   20,  108,  110,
      117,  120,  115,  118,  139,  139,   42,  139,  139,  126,
        0,    0,    0,  113,  107,  110,  100,   93,  103,  106,
       97,  104,   25,   95,   89,   33,   90,   90,  103,  102,
       93,   92,   80,   88,   95,   94,   85,   81,   75,   85,
       78,   82,   81,   88,   71,   77,   83,   82,   79,   79,
       64,   67,   61,    0,    0,    0,   63,   61,   76,   58,
        0,   57,   69,   68,   56,    0,   62,   54,   65,   64,
       49,   64,   57,   63,    0,    0,    0,   49,   58,   56,

       42,   43,   47,    0,   55,   43,    0,    0,   34,   53,
       48,   41,    0,   35,   31,    0,   36,   32,    0,    0,
        0,  139,   53,   56,   59,   38
    } ;

static const short int yy_def[127] =
    {   0,
      122,    1,  122,  122,  122,  122,  123,  124,  125,  122,
      122,  126,  122,  126,  126,  126,  126,  126,  126,  126,
      126,  126,  126,  126,  122,  122,  123,  122,  122,  123,
      124,  125,  126,  126,  126,  126,  126,  126,  126,  126,
      126,  126,  126,  126,  126,  126,  126,  126,  126,  126,
      126,  126,  126,  126,  126,  126,  126,  126,  126,  126,
      126,  126,  126,  126,  126,  126,  126,  126,  126,  126,
      126,  126,  126,  126,  126,  126,  126,  126,  126,  126,
      126,  126,  126,  126,  126,  126,  126,  126,  126,  126,
      126,  126,  126,  126,  126,  126,  126,  126,  126,  126,

      126,  126,  126,  126,  126,  126,  126,  126,  126,  126,
      126,  126,  126,  126,  126,  126,  126,  126,  126,  126,
      126,    0,  122,  122,  122,  122
    } ;

static const short int yy_nxt[174] =
    {   0,
        4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
        4,   14,   15,   16,   17,   12,   18,   19,   12,   20,
       12,   12,   21,   12,   12,   22,   23,   12,   12,   12,
       24,   12,   25,   26,   28,   29,   34,   38,   57,   40,
       33,   58,   30,   35,   28,   29,   61,  121,   39,   41,
       62,  120,   30,   27,   27,   27,   31,  119,   31,   32,
      118,   32,  117,  116,  115,  114,  113,  112,  111,  110,
      109,  108,  107,  106,  105,  104,  103,  102,  101,  100,
       99,   98,   97,   96,   95,   94,   93,   92,   91,   90,
       89,   88,   87,   86,   85,   84,   83,   82,   81,   80,

       79,   78,   77,   76,   75,   74,   73,   72,   71,   70,
       69,   68,   67,   66,   65,   64,   63,   60,   59,   56,
       55,   54,   53,   52,   51,   50,   49,   48,  122,   47,
       46,   45,   44,   43,   42,   37,   36,  122,    3,  122,
      122,  122,  122,  122,  122,  122,  122,  122,  122,  122,
      122,  122,  122,  122,  122,  122,  122,  122,  122,  122,
      122,  122,  122,  122,  122,  122,  122,  122,  122,  122,
      122,  122,  122
    } ;

static const short int yy_chk[174] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    7,    7,   14,   17,   43,   18,
      126,   43,    7,   14,   27,   27,   46,  118,   17,   18,
       46,  117,   27,  123,  123,  123,  124,  115,  124,  125,
      114,  125,  112,  111,  110,  109,  106,  105,  103,  102,
      101,  100,   99,   98,   94,   93,   92,   91,   90,   89,
       88,   87,   85,   84,   83,   82,   80,   79,   78,   77,
       73,   72,   71,   70,   69,   68,   67,   66,   65,   64,

       63,   62,   61,   60,   59,   58,   57,   56,   55,   54,
       53,   52,   51,   50,   49,   48,   47,   45,   44,   42,
       41,   40,   39,   38,   37,   36,   35,   34,   30,   24,
       23,   22,   21,   20,   19,   16,   15,    3,  122,  122,
      122,  122,  122,  122,  122,  122,  122,  122,  122,  122,
      122,  122,  122,  122,  122,  122,  122,  122,  122,  122,
      122,  122,  122,  122,  122,  122,  122,  122,  122,  122,
      122,  122,  122
    } ;

static yy_state_type yy_last_accepting_state;
static YY_CHAR *yy_last_accepting_cpos;

/* the intent behind this definition is that it'll catch
 * any uses of REJECT which flex missed
 */
#define REJECT reject_used_but_not_detected
#define yymore() yymore_used_but_not_detected
#define YY_MORE_ADJ 0

/* these variables are all declared out here so that section 3 code can
 * manipulate them
 */
/* points to current character in buffer */
static YY_CHAR *yy_c_buf_p = (YY_CHAR *) 0;
static int yy_init = 1;		/* whether we need to initialize */
static int yy_start = 0;	/* start state number */

/* flag which is used to allow yywrap()'s to do buffer switches
 * instead of setting up a fresh yyin.  A bit of a hack ...
 */
static int yy_did_buffer_switch_on_eof;

static yy_state_type yy_get_previous_state ( void );
static yy_state_type yy_try_NUL_trans ( yy_state_type current_state );
static int yy_get_next_buffer ( void );
static void yyunput ( YY_CHAR c, YY_CHAR *buf_ptr );

/* jbk added static in front all these */
static void yyrestart ( FILE *input_file );
static void yy_switch_to_buffer ( YY_BUFFER_STATE new_buffer );
static void yy_load_buffer_state ( void );
static YY_BUFFER_STATE yy_create_buffer ( FILE *file, int size );
static void yy_delete_buffer ( YY_BUFFER_STATE b );
static void yy_init_buffer ( YY_BUFFER_STATE b, FILE *file );

#define yy_new_buffer yy_create_buffer

#ifdef __cplusplus
static int yyinput ( void );
#else
static int input ( void );
#endif

YY_DECL
    {
    register yy_state_type yy_current_state;
    register YY_CHAR *yy_cp, *yy_bp;
    register int yy_act;




    if ( yy_init )
	{
	YY_USER_INIT;

	if ( ! yy_start )
	    yy_start = 1;	/* first start state */

	if ( ! yyin )
	    yyin = stdin;

	if ( ! yyout )
	    yyout = stdout;

	if ( yy_current_buffer )
	    yy_init_buffer( yy_current_buffer, yyin );
	else
	    yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE );

	yy_load_buffer_state();

	yy_init = 0;
	}

    while ( 1 )		/* loops until end-of-file is reached */
	{
	yy_cp = yy_c_buf_p;

	/* support of yytext */
	*yy_cp = yy_hold_char;

	/* yy_bp points to the position in yy_ch_buf of the start of the
	 * current run.
	 */
	yy_bp = yy_cp;

	yy_current_state = yy_start;
yy_match:
	do
	    {
	    YY_CHAR yy_c = yy_ec[(int)*yy_cp];
	    if ( yy_accept[yy_current_state] )
		{
		yy_last_accepting_state = yy_current_state;
		yy_last_accepting_cpos = yy_cp;
		}
	    while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
		{
		yy_current_state = yy_def[yy_current_state];
		if ( yy_current_state >= 123 )
		    yy_c = yy_meta[(int)yy_c];
		}
	    yy_current_state = yy_nxt[yy_base[yy_current_state] + yy_c];
	    ++yy_cp;
	    }
	while ( yy_base[yy_current_state] != 139 );

yy_find_action:
	yy_act = yy_accept[yy_current_state];

	YY_DO_BEFORE_ACTION;
	YY_USER_ACTION;

do_action:	/* this label is used only to access EOF actions */


	switch ( yy_act )
	    {
	    case 0: /* must backtrack */
	    /* undo the effects of YY_DO_BEFORE_ACTION */
	    *yy_cp = yy_hold_char;
	    yy_cp = yy_last_accepting_cpos;
	    yy_current_state = yy_last_accepting_state;
	    goto yy_find_action;

case 1:
# line 32 "../dbLex.l"
return(tokenINCLUDE);
	YY_BREAK
case 2:
# line 33 "../dbLex.l"
return(tokenPATH);
	YY_BREAK
case 3:
# line 34 "../dbLex.l"
return(tokenADDPATH);
	YY_BREAK
case 4:
# line 35 "../dbLex.l"
return(tokenMENU);
	YY_BREAK
case 5:
# line 36 "../dbLex.l"
return(tokenCHOICE);
	YY_BREAK
case 6:
# line 37 "../dbLex.l"
return(tokenRECORDTYPE);
	YY_BREAK
case 7:
# line 38 "../dbLex.l"
return(tokenFIELD);
	YY_BREAK
case 8:
# line 39 "../dbLex.l"
return(tokenDEVICE);
	YY_BREAK
case 9:
# line 40 "../dbLex.l"
return(tokenDRIVER);
	YY_BREAK
case 10:
# line 41 "../dbLex.l"
return(tokenBREAKTABLE);
	YY_BREAK
case 11:
# line 42 "../dbLex.l"
return(tokenRECORD);
	YY_BREAK
case 12:
# line 43 "../dbLex.l"
return(tokenGRECORD);
	YY_BREAK
case 13:
# line 44 "../dbLex.l"
return(tokenALIAS);
	YY_BREAK
case 14:
# line 45 "../dbLex.l"
return(tokenINFO);
	YY_BREAK
case 15:
# line 46 "../dbLex.l"
return(tokenREGISTRAR);
	YY_BREAK
case 16:
# line 47 "../dbLex.l"
return(tokenFUNCTION);
	YY_BREAK
case 17:
# line 48 "../dbLex.l"
return(tokenVARIABLE);
	YY_BREAK
case 18:
# line 50 "../dbLex.l"
{ /* unquoted string or number */
	yylval.Str = dbmfStrdup(yytext);
	return(tokenSTRING); 
}
	YY_BREAK
case 19:
# line 55 "../dbLex.l"
{ /* quoted string */
	yylval.Str = dbmfStrdup(yytext+1);
	yylval.Str[strlen(yylval.Str)-1] = '\0';
	return(tokenSTRING);
}
	YY_BREAK
case 20:
# line 61 "../dbLex.l"
{ /*C definition in recordtype*/
	yylval.Str = dbmfStrdup(yytext+1);
	return(tokenCDEFS);
}
	YY_BREAK
case 21:
# line 66 "../dbLex.l"
return(yytext[0]);
	YY_BREAK
case 22:
# line 67 "../dbLex.l"
return(yytext[0]);
	YY_BREAK
case 23:
# line 68 "../dbLex.l"
return(yytext[0]);
	YY_BREAK
case 24:
# line 69 "../dbLex.l"
return(yytext[0]);
	YY_BREAK
case 25:
# line 70 "../dbLex.l"
return(yytext[0]);
	YY_BREAK
case 26:
# line 72 "../dbLex.l"
;
	YY_BREAK
case 27:
# line 73 "../dbLex.l"
;
	YY_BREAK
case 28:
# line 75 "../dbLex.l"
{ /* bad string */
	yyerror("Newline in string, closing quote missing");
}
	YY_BREAK
case 29:
# line 79 "../dbLex.l"
{
	char message[40];
	YY_BUFFER_STATE *dummy=0;

	sprintf(message,"Invalid character '%c'",yytext[0]);
	yyerror(message);
	/*The following suppresses compiler warning messages*/
	if(FALSE) yyunput('c',(unsigned char *) message);
	if(FALSE) yy_switch_to_buffer(*dummy);
}
	YY_BREAK
case 30:
# line 90 "../dbLex.l"
ECHO;
	YY_BREAK
case YY_STATE_EOF(INITIAL):
    yyterminate();

	    case YY_END_OF_BUFFER:
		{
		/* amount of text matched not including the EOB char */
		int yy_amount_of_matched_text = yy_cp - yytext - 1;

		/* undo the effects of YY_DO_BEFORE_ACTION */
		*yy_cp = yy_hold_char;

		/* note that here we test for yy_c_buf_p "<=" to the position
		 * of the first EOB in the buffer, since yy_c_buf_p will
		 * already have been incremented past the NUL character
		 * (since all states make transitions on EOB to the end-
		 * of-buffer state).  Contrast this with the test in yyinput().
		 */
		if ( yy_c_buf_p <= &yy_current_buffer->yy_ch_buf[yy_n_chars] )
		    /* this was really a NUL */
		    {
		    yy_state_type yy_next_state;

		    yy_c_buf_p = yytext + yy_amount_of_matched_text;

		    yy_current_state = yy_get_previous_state();

		    /* okay, we're now positioned to make the
		     * NUL transition.  We couldn't have
		     * yy_get_previous_state() go ahead and do it
		     * for us because it doesn't know how to deal
		     * with the possibility of jamming (and we
		     * don't want to build jamming into it because
		     * then it will run more slowly)
		     */

		    yy_next_state = yy_try_NUL_trans( yy_current_state );

		    yy_bp = yytext + YY_MORE_ADJ;

		    if ( yy_next_state )
			{
			/* consume the NUL */
			yy_cp = ++yy_c_buf_p;
			yy_current_state = yy_next_state;
			goto yy_match;
			}

		    else
			{
			goto yy_find_action;
			}
		    }

		else switch ( yy_get_next_buffer() )
		    {
		    case EOB_ACT_END_OF_FILE:
			{
			yy_did_buffer_switch_on_eof = 0;

			if ( yywrap() )
			    {
			    /* note: because we've taken care in
			     * yy_get_next_buffer() to have set up yytext,
			     * we can now set up yy_c_buf_p so that if some
			     * total hoser (like flex itself) wants
			     * to call the scanner after we return the
			     * YY_NULL, it'll still work - another YY_NULL
			     * will get returned.
			     */
			    yy_c_buf_p = yytext + YY_MORE_ADJ;

			    yy_act = YY_STATE_EOF((yy_start - 1) / 2);
			    goto do_action;
			    }

			else
			    {
			    if ( ! yy_did_buffer_switch_on_eof )
				YY_NEW_FILE;
			    }
			}
			break;

		    case EOB_ACT_CONTINUE_SCAN:
			yy_c_buf_p = yytext + yy_amount_of_matched_text;

			yy_current_state = yy_get_previous_state();

			yy_cp = yy_c_buf_p;
			yy_bp = yytext + YY_MORE_ADJ;
			goto yy_match;

		    case EOB_ACT_LAST_MATCH:
			yy_c_buf_p =
			    &yy_current_buffer->yy_ch_buf[yy_n_chars];

			yy_current_state = yy_get_previous_state();

			yy_cp = yy_c_buf_p;
			yy_bp = yytext + YY_MORE_ADJ;
			goto yy_find_action;
		    }
		break;
		}

	    default:
#ifdef FLEX_DEBUG
		printf( "action # %d\n", yy_act );
#endif
		YY_FATAL_ERROR(
			"fatal flex scanner internal error--no action found" );
	    }
	}
    }


/* yy_get_next_buffer - try to read in a new buffer
 *
 * synopsis
 *     int yy_get_next_buffer();
 *     
 * returns a code representing an action
 *     EOB_ACT_LAST_MATCH - 
 *     EOB_ACT_CONTINUE_SCAN - continue scanning from current position
 *     EOB_ACT_END_OF_FILE - end of file
 */

static int yy_get_next_buffer( void )

    {
    register YY_CHAR *dest = yy_current_buffer->yy_ch_buf;
    register YY_CHAR *source = yytext - 1; /* copy prev. char, too */
    register int number_to_move, i;
    int ret_val;

    if ( yy_c_buf_p > &yy_current_buffer->yy_ch_buf[yy_n_chars + 1] )
	YY_FATAL_ERROR(
		"fatal flex scanner internal error--end of buffer missed" );

    /* try to read more data */

    /* first move last chars to start of buffer */
    number_to_move = yy_c_buf_p - yytext;

    for ( i = 0; i < number_to_move; ++i )
	*(dest++) = *(source++);

    if ( yy_current_buffer->yy_eof_status != EOF_NOT_SEEN )
	/* don't do the read, it's not guaranteed to return an EOF,
	 * just force an EOF
	 */
	yy_n_chars = 0;

    else
	{
	int num_to_read = yy_current_buffer->yy_buf_size - number_to_move - 1;

	if ( num_to_read > YY_READ_BUF_SIZE )
	    num_to_read = YY_READ_BUF_SIZE;

	else if ( num_to_read <= 0 )
	    YY_FATAL_ERROR( "fatal error - scanner input buffer overflow" );

	/* read in more data */
	YY_INPUT( (&yy_current_buffer->yy_ch_buf[number_to_move]),
		  yy_n_chars, num_to_read );
	}

    if ( yy_n_chars == 0 )
	{
	if ( number_to_move - YY_MORE_ADJ == 1 )
	    {
	    ret_val = EOB_ACT_END_OF_FILE;
	    yy_current_buffer->yy_eof_status = EOF_DONE;
	    }

	else
	    {
	    ret_val = EOB_ACT_LAST_MATCH;
	    yy_current_buffer->yy_eof_status = EOF_PENDING;
	    }
	}

    else
	ret_val = EOB_ACT_CONTINUE_SCAN;

    yy_n_chars += number_to_move;
    yy_current_buffer->yy_ch_buf[yy_n_chars] = YY_END_OF_BUFFER_CHAR;
    yy_current_buffer->yy_ch_buf[yy_n_chars + 1] = YY_END_OF_BUFFER_CHAR;

    /* yytext begins at the second character in yy_ch_buf; the first
     * character is the one which preceded it before reading in the latest
     * buffer; it needs to be kept around in case it's a newline, so
     * yy_get_previous_state() will have with '^' rules active
     */

    yytext = &yy_current_buffer->yy_ch_buf[1];

    return ( ret_val );
    }


/* yy_get_previous_state - get the state just before the EOB char was reached
 *
 * synopsis
 *     yy_state_type yy_get_previous_state();
 */

static yy_state_type yy_get_previous_state( void )

    {
    register yy_state_type yy_current_state;
    register YY_CHAR *yy_cp;

    yy_current_state = yy_start;

    for ( yy_cp = yytext + YY_MORE_ADJ; yy_cp < yy_c_buf_p; ++yy_cp )
	{
	YY_CHAR yy_c = (*yy_cp ? yy_ec[(int)*yy_cp] : 1);
	if ( yy_accept[yy_current_state] )
	    {
	    yy_last_accepting_state = yy_current_state;
	    yy_last_accepting_cpos = yy_cp;
	    }
	while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
	    {
	    yy_current_state = yy_def[yy_current_state];
	    if ( yy_current_state >= 123 )
		yy_c = yy_meta[(int)yy_c];
	    }
	yy_current_state = yy_nxt[yy_base[yy_current_state] + yy_c];
	}

    return ( yy_current_state );
    }


/* yy_try_NUL_trans - try to make a transition on the NUL character
 *
 * synopsis
 *     next_state = yy_try_NUL_trans( current_state );
 */

static yy_state_type yy_try_NUL_trans( register yy_state_type yy_current_state )
    {
    register int yy_is_jam;
    YY_CHAR *yy_cp = yy_c_buf_p;

    YY_CHAR yy_c = 1;
    if ( yy_accept[yy_current_state] )
	{
	yy_last_accepting_state = yy_current_state;
	yy_last_accepting_cpos = yy_cp;
	}
    while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
	{
	yy_current_state = yy_def[yy_current_state];
	if ( yy_current_state >= 123 )
	    yy_c = yy_meta[(int)yy_c];
	}
    yy_current_state = yy_nxt[yy_base[yy_current_state] + yy_c];
    yy_is_jam = (yy_base[yy_current_state] == 139);

    return ( yy_is_jam ? 0 : yy_current_state );
    }


static void yyunput( YY_CHAR c, register YY_CHAR *yy_bp )
    {
    register YY_CHAR *yy_cp = yy_c_buf_p;

    /* undo effects of setting up yytext */
    *yy_cp = yy_hold_char;

    if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
	{ /* need to shift things up to make room */
	register int number_to_move = yy_n_chars + 2; /* +2 for EOB chars */
	register YY_CHAR *dest =
	    &yy_current_buffer->yy_ch_buf[yy_current_buffer->yy_buf_size + 2];
	register YY_CHAR *source =
	    &yy_current_buffer->yy_ch_buf[number_to_move];

	while ( source > yy_current_buffer->yy_ch_buf )
	    *--dest = *--source;

	yy_cp += dest - source;
	yy_bp += dest - source;
	yy_n_chars = yy_current_buffer->yy_buf_size;

	if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
	    YY_FATAL_ERROR( "flex scanner push-back overflow" );
	}

    if ( yy_cp > yy_bp && yy_cp[-1] == '\n' )
	yy_cp[-2] = '\n';

    *--yy_cp = c;

    /* note: the formal parameter *must* be called "yy_bp" for this
     *       macro to now work correctly
     */
    YY_DO_BEFORE_ACTION; /* set up yytext again */
    }


#ifdef __cplusplus
static int yyinput( void )
#else
static int input( void )
#endif

    {
    int c;
    YY_CHAR *yy_cp = yy_c_buf_p;

    *yy_cp = yy_hold_char;

    if ( *yy_c_buf_p == YY_END_OF_BUFFER_CHAR )
	{
	/* yy_c_buf_p now points to the character we want to return.
	 * If this occurs *before* the EOB characters, then it's a
	 * valid NUL; if not, then we've hit the end of the buffer.
	 */
	if ( yy_c_buf_p < &yy_current_buffer->yy_ch_buf[yy_n_chars] )
	    /* this was really a NUL */
	    *yy_c_buf_p = '\0';

	else
	    { /* need more input */
	    yytext = yy_c_buf_p;
	    ++yy_c_buf_p;

	    switch ( yy_get_next_buffer() )
		{
		case EOB_ACT_END_OF_FILE:
		    {
		    if ( yywrap() )
			{
			yy_c_buf_p = yytext + YY_MORE_ADJ;
			return ( EOF );
			}

		    YY_NEW_FILE;

#ifdef __cplusplus
		    return ( yyinput() );
#else
		    return ( input() );
#endif
		    }
		    break;

		case EOB_ACT_CONTINUE_SCAN:
		    yy_c_buf_p = yytext + YY_MORE_ADJ;
		    break;

		case EOB_ACT_LAST_MATCH:
#ifdef __cplusplus
		    YY_FATAL_ERROR( "unexpected last match in yyinput()" );
#else
		    YY_FATAL_ERROR( "unexpected last match in input()" );
#endif
		}
	    }
	}

    c = *yy_c_buf_p;
    yy_hold_char = *++yy_c_buf_p;

    return ( c );
    }


/* jbk added static in front of func */
static void yyrestart( FILE *input_file )
    {
    if ( yy_current_buffer )
	yy_init_buffer( yy_current_buffer, input_file );
    else
	yy_current_buffer = yy_create_buffer( input_file, YY_BUF_SIZE );

    yy_load_buffer_state();
    }


/* jbk added static in front of func */
static void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer )
    {
    if ( yy_current_buffer == new_buffer )
	return;

    if ( yy_current_buffer )
	{
	/* flush out information for old buffer */
	*yy_c_buf_p = yy_hold_char;
	yy_current_buffer->yy_buf_pos = yy_c_buf_p;
	yy_current_buffer->yy_n_chars = yy_n_chars;
	}

    yy_current_buffer = new_buffer;
    yy_load_buffer_state();

    /* we don't actually know whether we did this switch during
     * EOF (yywrap()) processing, but the only time this flag
     * is looked at is after yywrap() is called, so it's safe
     * to go ahead and always set it.
     */
    yy_did_buffer_switch_on_eof = 1;
    }


/* jbk added static in front of func */
static void yy_load_buffer_state( void )
    {
    yy_n_chars = yy_current_buffer->yy_n_chars;
    yytext = yy_c_buf_p = yy_current_buffer->yy_buf_pos;
    yyin = yy_current_buffer->yy_input_file;
    yy_hold_char = *yy_c_buf_p;
    }


/* jbk added static in front of func */
static YY_BUFFER_STATE yy_create_buffer( FILE *file, int size )
    {
    YY_BUFFER_STATE b;

    b = (YY_BUFFER_STATE) malloc( sizeof( struct yy_buffer_state ) );

    if ( ! b )
	YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

    b->yy_buf_size = size;

    /* yy_ch_buf has to be 2 characters longer than the size given because
     * we need to put in 2 end-of-buffer characters.
     */
    b->yy_ch_buf = (YY_CHAR *) malloc( (unsigned) (b->yy_buf_size + 2) );

    if ( ! b->yy_ch_buf )
	YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

    yy_init_buffer( b, file );

    return ( b );
    }


/* jbk added static in front of func */
static void yy_delete_buffer( YY_BUFFER_STATE b )
    {
    if ( b == yy_current_buffer )
	yy_current_buffer = (YY_BUFFER_STATE) 0;

    free( (char *) b->yy_ch_buf );
    free( (char *) b );
    }


/* jbk added static in front of func */
static void yy_init_buffer( YY_BUFFER_STATE b, FILE *file )
    {
    b->yy_input_file = file;

    /* we put in the '\n' and start reading from [1] so that an
     * initial match-at-newline will be true.
     */

    b->yy_ch_buf[0] = '\n';
    b->yy_n_chars = 1;

    /* we always need two end-of-buffer characters.  The first causes
     * a transition to the end-of-buffer state.  The second causes
     * a jam in that state.
     */
    b->yy_ch_buf[1] = YY_END_OF_BUFFER_CHAR;
    b->yy_ch_buf[2] = YY_END_OF_BUFFER_CHAR;

    b->yy_buf_pos = &b->yy_ch_buf[1];

    b->yy_eof_status = EOF_NOT_SEEN;
    }

static int yyterminate_internal( void )
{
	/* jbk fix - buffer created by yy_create_buffer needs to be freed */
	yy_delete_buffer(yy_current_buffer);
	yy_current_buffer=NULL;
	return YY_NULL;
}

# line 90 "../dbLex.l"

