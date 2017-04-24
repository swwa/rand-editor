#ifdef COMMENT
	Copyright abandoned, 1983, The Rand Corporation
#endif

#ifdef COMMENT
	The sun3 keyboard sends 3-byte escape sequences for the arrow
	keys, and 6-byte sequences for all other function keys.
	Note that (especially over a network) the full escape sequence
	for a particular function key is not always present,
	and action must be delayed.

	1st cut -- not optimized.  Should download the keys with
	more reasonable codes (ie the standard keyboard).
	    /Terry West, Rand - 10/2/84

#endif COMMENT

#define CTRL(x) ((x) & 31)

/*
 *  sun_lex[0-31] contains commands that map directly from
 *      <^char>,
 *
 *  sun_lex[32-177] (initialized in kini_sun) is a direct
 *      translation of the character set, i.e.,
 *      sun_lex['a'] = 'a', etc.
 */

char sun_lex[128] = {
    CCCMD       , /* <BREAK > */
    CCCMD       , /* <cntr A> */
    CCLWORD     , /* <cntr B> */
    CCUNAS1     , /* <cntr C> */
    CCMILINE    , /* <cntr D> */
    CCMIPAGE    , /* <cntr E> */
    CCPLLINE    , /* <cntr F> */
    CCHOME      , /* <cntr G> */
    CCMOVELEFT  , /* <cntr H> */
    CCTAB       , /* <cntr I> */
    CCMOVEDOWN  , /* <cntr J> */
    CCMOVEUP    , /* <cntr K> */
    CCMOVERIGHT , /* <cntr L> */
    CCRETURN    , /* <cntr M> */
    CCRWORD     , /* <cntr N> */
    CCOPEN      , /* <cntr O> */
    CCPICK      , /* <cntr P> */
    CCUNAS1     , /* <cntr Q> */
    CCPLPAGE    , /* <cntr R> */
    CCUNAS1     , /* <cntr S> */
    CCMISRCH    , /* <cntr T> */
    CCMARK      , /* <cntr U> */
    CCCLOSE     , /* <cntr V> */
    CCDELCH     , /* <cntr W> */
    CCUNAS1     , /* <cntr X> */
    CCPLSRCH    , /* <cntr Y> */
    CCINSMODE   , /* <cntr Z> */
    CCINSMODE   , /* <escape> */
    CCINT       , /* <cntr \> */
    CCREPLACE   , /* <cntr ]> */
    CCERASE     , /* <cntr ^> */
    CCSETFILE   , /* <cntr _> */
};

/*
 *  extended functions - <^x><^char>
 */

static char sun_lexX[128] = {
    CCUNAS1     , /* <BREAK > */
    CCSETFILE   , /* <cntr A> */
    CCSPLIT     , /* <cntr B> */
    CCCTRLQUOTE , /* <cntr C> */
    CCUNAS1     , /* <cntr D> */
    CCERASE     , /* <cntr E> */
    CCUNAS1     , /* <cntr F> */
    CCUNAS1     , /* <cntr G> */
    CCLWINDOW   , /* <cntr H> */
    CCUNAS1     , /* <cntr I> */
    CCJOIN      , /* <cntr J> */
    CCUNAS1     , /* <cntr K> */
    CCRWINDOW   , /* <cntr L> */
    CCUNAS1     , /* <cntr M> */
    CCDWORD     , /* <cntr N> */
    CCUNAS1     , /* <cntr O> */
    CCUNAS1     , /* <cntr P> */
    CCUNAS1     , /* <cntr Q> */
    CCREPLACE   , /* <cntr R> */
    CCUNAS1     , /* <cntr S> */
    CCTABS      , /* <cntr T> */
    CCBACKTAB   , /* <cntr U> */
    CCUNAS1     , /* <cntr V> */
    CCCHWINDOW  , /* <cntr W> */
    CCUNAS1     , /* <cntr X> */
    CCUNAS1     , /* <cntr Y> */
    CCUNAS1     , /* <cntr Z> */
    CCUNAS1     , /* <escape> */
    CCUNAS1     , /* <cntr \> */
    CCUNAS1     , /* <cntr ]> */
    CCUNAS1     , /* <cntr ^> */
    CCUNAS1     , /* <cntr _> */
};

in_sun (lexp, count)
char *lexp;
int *count;
{
    Reg1 int chr;
    Reg2 int nr;
    Reg3 char *icp;
    Reg4 char *ocp;

    icp = ocp = lexp;
    nr = *count;

    for (; nr > 0; nr--) {
	if ((chr = *icp++ & 0177) >= 040) {
	    if (chr == 0177)         /* DEL KEY KLUDGE FOR NOW */
		*ocp++ = CCBACKSPACE;
	    else
		*ocp++ = chr;
	}
	else if (chr == 033) {
	    if( nr == 1 ) {
		icp--;
		goto nomore;
	    }
	    else if ((*icp & 0177) != '[' ) {
		*ocp++ = CCUNAS1;
		continue;
	    }
	    else if (nr == 2) {    /* need at least 3 */
		icp--;
		goto nomore;
	    }

	    nr--;
	    chr = *icp++ & 0177;    /* a known '[' */

	    nr--;
	    switch (chr = *icp++ & 0177) {

	    /*
	     *  the following 4 are for a reset sun.
	     */
	    case 'A':                           /* R8 */
		*ocp++ = CCMOVEUP;
		break;

	    case 'B':                           /* R14 */
		*ocp++ = CCMOVEDOWN;
		break;

	    case 'C':                           /* R12 */
		*ocp++ = CCMOVERIGHT;
		break;

	    case 'D':                           /* R10 */
		*ocp++ = CCMOVELEFT;
		break;

	    case '1':   /* ESC[19{3-9}z */
		if( nr < 4 ) {
		    nr += 2;        /* set count and ptr back to ESC */
		    icp -= 3;
		    goto nomore;
		}
		nr -= 3;        /* for loop also subtracts 1 */
		icp++;          /* skip '9' */
		chr = *icp++ & 0177;
		icp++;          /* skip 'z' */
		switch (chr){
		case '3':                       /* L2 */
		    *ocp++ = CCINT;
		    break;
		case '4':                       /* L3 */
		    *ocp++ = CCUNAS1;
		    break;
		case '5':                       /* L4 */
		    *ocp++ = CCTABS;
		    break;
		case '6':                       /* L5 */
		    *ocp++ = CCJOIN;
		    break;
		case '7':                       /* L6 */
		    *ocp++ = CCCHWINDOW;
		    break;
		case '8':                       /* L7 */
		    *ocp++ = CCSPLIT;
		    break;
		case '9':                       /* L8 */
		    *ocp++ = CCMARK;
		    break;
		default:
		    *ocp++ = CCUNAS1;
		    break;
		}
		break;

	    case '2':
		if( nr < 4 ) {
		    nr += 2;
		    icp -= 3;
		    goto nomore;
		}
		nr -= 3;
		switch( chr = *icp++ & 0177 ) {
		case '0':      /* ESC[20{0189}z */
		    chr = *icp++ & 0177;
		    icp++;
		    switch( chr ) {
		    case '0':                   /* L9 */
			*ocp++ = CCBACKTAB;
			break;
		    case '1':                   /* L10 */
			*ocp++ = CCCMD;
			break;
		    case '8':                   /* R1 */
			*ocp++ = CCMIPAGE;
			break;
		    case '9':                   /* R2 */
			*ocp++ = CCREPLACE;
			break;
		    default:
			*ocp++ = CCUNAS1;
			break;
		    }
		    break;

		case '1':      /* ESC[21{0123468}z */
		    chr = *icp++ & 0177;
		    icp++;            /* skip 'z' */
		    switch( chr ) {
		    case '0':                   /* R3 */
			*ocp++ = CCPLPAGE;
			break;
		    case '1':                   /* R4 */
			*ocp++ = CCMILINE;
			break;
		    case '2':                   /* R5 */
			*ocp++ = CCCTRLQUOTE;
			break;
		    case '3':                   /* R6 */
			*ocp++ = CCPLLINE;
			break;
		    case '4':                   /* R7 */
			*ocp++ = CCMISRCH;
			break;
		    case '5':                   /* R8 on sun */
			*ocp++ = CCMOVEUP;
			break;
		    case '6':                   /* R9 */
			*ocp++ = CCPLSRCH;
			break;
		    case '7':                   /* R10 on sun */
			*ocp++ = CCMOVELEFT;
			break;
		    case '8':                   /* R11 */
			*ocp++ = CCHOME;
			break;
		    case '9':                   /* R11 */
			*ocp++ = CCMOVERIGHT;   /* R12 on sun */
			break;
		    default:
			*ocp++ = CCUNAS1;
			break;
		    }
		    break;

		case '2':       /* ESC[22{02456789}z */
		    chr = *icp++ & 0177;
		    icp++;            /* skip 'z' */
		    switch( chr ) {
		    case '0':                   /* R13*/
			*ocp++ = CCINSMODE;
			break;
		    case '1':                   /* R14 on sun */
			*ocp++ = CCMOVEDOWN;
			break;
		    case '2':                   /* R15*/
			*ocp++ = CCDELCH;
			break;
		    case '4':                   /* F1 */
			*ocp++ = CCLWINDOW;
			break;
		    case '5':                   /* F2 */
			*ocp++ = CCRWINDOW;
			break;
		    case '6':                   /* F3 */
			*ocp++ = CCSETFILE;
			break;
		    case '7':                   /* F4 */
			*ocp++ = CCPICK;
			break;
		    case '8':                   /* F5 */
			*ocp++ = CCERASE;
			break;
		    case '9':                   /* F6 */
			*ocp++ = CCCLOSE;
			break;
		    default:
			*ocp++ = CCUNAS1;
			break;
		    }
		    break;

		case '3':               /* ESC[23{012}z */
		    chr = *icp++ & 0177;
		    icp++;
		    switch( chr ) {
		    case '0':                   /* F7 */
			*ocp++ = CCOPEN;
			break;
		    case '1':                   /* F8 */
			*ocp++ = CCLWORD;
			break;
		    case '2':                   /* F9 */
			*ocp++ = CCRWORD;
			break;
		    default:
			*ocp++ = CCUNAS1;
			break;
		    }
		   break;

		default:
		    *ocp++ = CCUNAS1;
		    break;
		}
		break;

	    default:
		*ocp++ = CCUNAS1;
		break;
	    }

	}
	else if( chr == CTRL('X')) {
	    if( nr == 1 ) {
		icp--;
		goto nomore;
	    }
	    else {
		nr--;
		*ocp++ = sun_lexX[*icp++ & 0177];
	    }
	}
	else
	    *ocp++ = sun_lex[chr];
    }
 nomore:
    Block {
	int conv;
	*count = nr;     /* number left over - still raw */
	conv = ocp - lexp;
	while (nr-- > 0)
	    *ocp++ = *icp++;
	return conv;
    }
}


/*
 *  insert line
 */
il_sun (num) { printf ("\033[%dL", num); return num; }

/*
 *  delete line
 */
dl_sun (num) { printf ("\033[%dM", num); return num; }

kini_sun ()
{
	extern Flag singlescroll;
	register int n;

	/*
	 *  Unset singlescroll, and point to our own versions of
	 *  insert/delete line for fast operation.
	 */
	singlescroll = NO;
	term.tt_insline = il_sun;
	term.tt_delline = dl_sun;
#ifdef LMCHELP
	term.tt_so      = so_tcap;
	term.tt_soe     = soe_tcap;
#endif LMCHELP
	term.tt_bullets = NO;

	/*
	 * Initialize the input lex tables
	 */
	for(n=32; n<127; n++)
	    sun_lex[n] = n;             /* state 0 - std. char set */
	sun_lex[127] = CCMOVELEFT;

	for(n=32; n<128; n++)           /* state 1 - <^x><?> */
	    sun_lexX[n] = CCUNAS1;

	return;
}

kend_sun () { }

S_kbd kb_sun = {
/* kb_inlex */  in_sun,
/* kb_init  */  kini_sun,
/* kb_end   */  kend_sun,
};

