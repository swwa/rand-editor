#ifdef COMMENT
/*
--------
file e.tt.c
    Terminal-dependent code and data declarations
*/
#endif

#ifdef COMMENT
/*
	Copyright abandoned, 1983, The Rand Corporation
*/
#endif

#include "e.h"
#include "e.tt.h"
#include "e.sg.h"

/* fake delay */
#define delay(c)

/* the following is to save code space */
#ifndef BIGADDR
#undef putchar
#define putchar(c) fputc(c,stdout)
#endif

char   *kname;                  /* name of keyboard type */
char   *tname;                  /* name of terminal type */
Small   kbdtype;                /* which kind of keyboard */
Small   termtype;               /* which kind of terminal */
Short   screensize;             /* term.tt_width * term.tt_height */
Flag    fast;                   /* running at a fast baud rate (>= 4800) */
int     ospeed;                 /* tty output baud rate */
Flag    borderbullets = NO;     /* Enable bullets on borders */
S_term  term;
S_kbd   kbd;
Flag tt_lt2;            /* 2 lefts take fewer characters than an addr */
Flag tt_lt3;            /* 3 lefts take fewer characters than an addr */
Flag tt_rt2;            /* 2 rights take fewer characters than an addr */
Flag tt_rt3;            /* 3 rights take fewer characters than an addr */

#ifdef COMMENT
/*
   TO ADD A TERMINAL TYPE:
	 Increment NTERMINALS by 1
	 Define a T_xx manifest constant for the terminal
	 Add the names of the terminal to the termnames table.
	 Add an include for 'term/xx.c' in this file.
	 Add the TM_xx entry to the "tterm" structure initialization
	   at the end of this file.
	 Add the KB_xx entry to the "tkbd" structure initialization
	   at the end of this file.
	 See term/Doc for more instructions.
	 Write a "term/xx.c" file for the terminal.
	 Add term/xx.c to Makefile dependencies

   Terminal #1 is the default if you are on a system without environment
   variables.

*/
#endif

#define T_tcap      0   /* tcap.c       Termcap terminal -- must be 0 */
#define T_std       0   /* stdinlex.c   Standard keyboard */
#define T_vt100     1   /* vt100.c      DEC VT100 -- keyboard only */
#define T_vt52      2   /* vt100.c      DEC VT100 -- keyboard only */
#define T_sun       3   /* sun          SUN 3/4 keyboard only */
#define T_xterm     4   /* xterm.c      Xterm emulator with mouse */
#define NTERMINALS  5

S_looktbl termnames[] = {
    /* must be sorted in ascending ascii order */
#ifdef T_vt100
    "ansi",         T_vt100,
    "con80x25",     T_vt100,
    "console",      T_vt100,
#endif
    "default",      T_tcap,
#ifdef T_vt100
    "linux",        T_vt100,
    "minix",        T_vt100,
#endif
    "standard",	    T_tcap,
#ifdef T_sun
    "sun",	    T_sun,
    "sun-cmd",      T_sun,
#endif
#ifdef T_vt100
    "vt100",        T_vt100,
    "vt100w",       T_vt100,
#endif
#ifdef T_vt52
    "vt52",         T_vt52,
#endif
#ifdef T_xterm
    "xterm",        T_xterm,
#endif
    "",             0,
};

#include "term/standard.c"

#define KB_std &kb_std

#include "term/tcap.c"
#define TM_tcap &t_tcap
#define KB_tcap &kb_std

#ifdef T_vt100
# include "term/vt100.c"
# define TM_vt100 &t_tcap
# define KB_vt100 &kb_vt100
#else
# define TM_vt100 ((S_term *) 0)
# define KB_vt100 ((S_kbd *) 0)
#endif

#ifdef T_vt52
# include "term/vt52.c"
# define TM_vt52 &t_tcap
# define KB_vt52 &kb_vt52
#else
# define TM_vt52 ((S_term *) 0)
# define KB_vt52 ((S_kbd *) 0)
#endif

#ifdef T_sun
# include "term/sun.c"
# define TM_sun &t_tcap
# define KB_sun &kb_sun
#else
# define TM_sun ((S_term *) 0)
# define KB_sun ((S_kbd *) 0)
#endif

#ifdef T_xterm
# include "term/xterm.c"
# define TM_xterm &t_tcap
# define KB_xterm &kb_xterm
#else
# define TM_xterm ((S_term *) 0)
# define KB_xterm ((S_kbd *) 0)
#endif

/* the entries in this structure must be in the order of their
/* defined T_ values
/**/
S_term *tterm[NTERMINALS] = {
    TM_tcap 
   ,TM_vt100
   ,TM_vt52
   ,TM_sun
   ,TM_xterm
};

/* the entries in this structure must be in the order of their
/* defined T_ values
/**/
S_kbd *tkbd[NTERMINALS] = {
    KB_std     
   ,KB_vt100   
   ,KB_vt52
   ,KB_sun
   ,KB_xterm
};

