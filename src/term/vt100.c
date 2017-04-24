#ifdef COMMENT
	Copyright abandoned, 1983, The Rand Corporation
#endif

#define CTRL(x) ((x) & 31)
#define _BAD_ CCUNAS1

in_vt100 (lexp, count)
char *lexp;
int *count;
{
    int chr;
    int nr;
    char *icp;
    char *ocp;

    icp = ocp = lexp;
    nr = *count;
    for (; nr > 0; nr--) {
	chr = *icp++;
	if (chr >= 040 || chr < 0) {
	    if (chr == 0177)         /* DEL KEY KLUDGE FOR NOW */
		*ocp++ = CCBACKSPACE;
	    else
		*ocp++ = chr;
	}
	else if (chr == 033) {
	    if (nr < 2) {
		icp--;
		goto nomore;
	    }
	    nr--;
	    chr = *icp++;
	    if (chr == '[') {
		if (nr < 2) {
		    icp -= 2;
		    nr++;
		    goto nomore;
		}
		nr--;
		switch (chr = *icp++) {
		case 'A':
		    *ocp++ = CCMOVEUP;
		    break;

		case 'B':
		    *ocp++ = CCMOVEDOWN;
		    break;

		case 'C':
		    *ocp++ = CCMOVERIGHT;
		    break;

		case 'D':
		    *ocp++ = CCMOVELEFT;
		    break;

		default:
		    *ocp++ = CCUNAS1;
		    break;
		}
	    }
	    else if (chr == 'O') {
		if (nr < 2) {
		    icp -= 2;
		    nr++;
		    goto nomore;
		}
		nr--;
		chr = *icp++;
		if ('l' <= chr && chr <= 'y') Block {
		    static char xlt[] = {
			CCPICK         , /* l  , */
			CCOPEN         , /* m  - */
			CCDELCH        , /* n  . */
			CCUNAS1        , /* o    */
			CCINSMODE      , /* p  0 */
			CCMISRCH       , /* q  1 */
			CCPLSRCH       , /* r  2 */
			CCMARK         , /* s  3 */
			CCMIPAGE       , /* t  4 */
			CCPLPAGE       , /* u  5 */
			CCREPLACE      , /* v  6 */
			CCMILINE       , /* w  7 */
			CCPLLINE       , /* x  8 */
			CCSETFILE      , /* y  9 */
		    };
		    *ocp++ = xlt[chr - 'l'];
		}
		else if ('M' <= chr && chr <= 'S') Block {
		    static char xlt[] = {
			CCCMD          , /* M  ENTER */
			CCUNAS1        , /* N        */
			CCUNAS1        , /* O        */
			CCLWORD        , /* P  PF1   */
			CCRWORD        , /* Q  PF2   */
			CCBACKTAB      , /* R  PF3   */
			CCCLOSE        , /* S  PF4   */
		    };
		    *ocp++ = xlt[chr - 'M'];
		}
		else if ('A' <= chr && chr <= 'D') Block {
		    static char xlt[] = {
			CCMOVEUP       , /* A  up     */
			CCMOVEDOWN     , /* B  down   */
			CCMOVERIGHT    , /* C  right  */
			CCMOVELEFT     , /* D  left   */
		    };
		    *ocp++ = xlt[chr - 'A'];
		}
		else
		    *ocp++ = CCUNAS1;
	    }
	    else
		*ocp++ = CCUNAS1;
	}
	else if (chr == ('X' & 31)) {
	    if (nr < 2) {
		icp--;
		goto nomore;
	    }
	    nr--;
	    chr = *icp++;
	    switch (chr) {
	    case CTRL ('a'):
		*ocp++ = CCSETFILE;
		break;
	    case CTRL ('b'):
		*ocp++ = CCSPLIT;
		break;
	    case CTRL ('c'):
		*ocp++ = CCCTRLQUOTE;
		break;
	    case CTRL ('e'):
		*ocp++ = CCERASE;
		break;
	    case CTRL ('h'):
		*ocp++ = CCLWINDOW;
		break;
	    case CTRL ('j'):
		*ocp++ = CCJOIN;
		break;
	    case CTRL ('l'):
		*ocp++ = CCRWINDOW;
		break;
	    case CTRL ('r'):
		*ocp++ = CCREPLACE;
		break;
	    case CTRL ('t'):
		*ocp++ = CCTABS;
		break;
	    case CTRL ('u'):
		*ocp++ = CCBACKTAB;
		break;
	    case CTRL ('w'):
		*ocp++ = CCCHWINDOW;
		break;
	    default:
		*ocp++ = CCUNAS1;
		break;
	    }
	}
	else
	    *ocp++ = lexstd[chr];
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

kini_vt100 ()
{
    static char ini[] = {033,'='};
    fwrite (ini, sizeof ini, 1, stdout);
}
kend_vt100 ()
{
    static char end[] = {033,'>'};
    fwrite (end, sizeof end, 1, stdout);
}


S_kbd kb_vt100 = {
/* kb_inlex */  in_vt100,
/* kb_init  */  kini_vt100,
/* kb_end   */  kend_vt100,
};
