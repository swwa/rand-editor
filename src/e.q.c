#ifdef COMMENT
/*
--------
file e.q.c
    exit command and related stuff
*/
#endif

#ifdef COMMENT
/*
	Copyright abandoned, 1983, The Rand Corporation
*/
#endif

#include "e.h"
#include "e.m.h"
#include "e.cm.h"
#include "e.fn.h"
#include "e.tt.h"

#include SIG_INCL

extern char *getenv ();
extern void reenter ();

#ifdef COMMENT
/*
     both DOSHELL and DOCALL must be defined in e.h
     Don't need these for 4.x
*/
#endif COMMENT

#ifdef DOSHELL
extern void docall ();

#ifdef COMMENT
/*
Cmdret
shell ()
.
    Do the "shell" command.
*/
#endif
Cmdret
shell ()
{
    register char *cp;
    static char *args[] = {"-", (char *)0};

    for (cp = cmdopstr; *cp && *cp == ' '; cp++)
	continue;

    if (*cp != '\0')
	return call ();

    if (saveall () == NO)
	return CROK;

    docall (args);
    /* never returns */
    /* NOTREACHED */
}
#endif DOSHELL

#ifdef DOCALL
#ifdef COMMENT
/*
Cmdret
call ()
.
    Do the "call" command.
*/
#endif
Cmdret
call ()
{
    register char *cp;
    static char *args[] = {"sh", "-c", (char *)0, (char *)0};

    for (cp = cmdopstr; *cp && *cp == ' '; cp++)
	continue;

    if (*cp == '\0')
	return CRNEEDARG;

    if (saveall () == NO)
	return CROK;

    args[2] = cp;
    docall (args);
    /* never returns */
    /* NOTREACHED */
}

#ifdef COMMENT
/*
void
docall (args)
    char *args[];
.
    Code called by shell() and call().
    Do all the cleanup as you would on exit.
    Fork a shell with 'args' and when it exits, re-exec editor.
*/
#endif
void
docall (args)
char *args[];
{
    char *ename;
    int child;
    int retstat;
    register Small j;

    savestate ();               /* to work from where it  left off    */
    cleanup (YES, YES);           /* restore terminal modes; free tmp   */
    for (j = 1; j <= NSIG ; j++) {
	if (j == SIGINT || j == SIGQUIT)
	    signal (j, SIG_IGN);
	else
	    signal (j, SIG_DFL);
    }

    for (j = 2; j < 25; )       /* HIGHFD */
	close (j++);
    dup (STDOUT);

#ifdef  ENVIRON
    shpath = append ((char *)getenv ("SHELL"), (char *)"");
#else   ENVIRON
    getpath ("sh", &shpath, NO);
#endif  ENVIRON

    if ((child = fork ()) != -1) {
	if (child == 0) {
	    execv (shpath, args);
	    printf ("Can't exec shell\n");
	    fflush (stdout);
#ifdef PROFILE
	    monexit (-1);
#else
	    exit (-1);
#endif
	    /* NOTREACHED */
	}
	else {
	    while (wait (&retstat) != child)
		continue;
	}
    }
    else
	printf ("Can't fork a shell\n");

    reenter ();

/* What is needed here is some way of re-execing this same image to get a
/* fresh data space, but using the same text.  Re-execing it by name is
/* not a reliable way to do this.
/**/
#ifdef  ENVIRON
    if ((ename = getenv ("PROGPATH")) == NULL)
	ename = "/bin/e";
#else   ENVIRON
#ifdef  UNIXV6
	ename = ENAME;
#else
	ename = "/bin/e";
#endif
#endif  ENVIRON

    execl (ename, append (loginflg? "-": "", ename), 0);
    printf ("Can't reenter editor \n");
#ifdef PROFILE
    monexit (-1);
#else
    exit (-1);
#endif
    /* never returns */
    /* NOTREACHED */
}
#endif DOCALL

#ifdef COMMENT
/*
void
reenter ()
.
    Ask the user to "Hit <RETURN> when ready to resume editing. ".
    When he has typed a <RETURN> return to caller.
*/
#endif
void
reenter ()
{
    register int j;

    putc (CCSTOP, keyfile);     /* stop replay at this point */
    printf ("Hit <RETURN> when ready to resume editing. ");
    fflush (stdout);
    while ((j = getchar ()) != EOF  && (j & 0377) != '\n')
	continue;
    return;
}


#define EXABORT         0
#define EXDUMP          1
#define EXNORMAL        2
#define EXNOSAVE        3
#define EXQUIT          4

#ifdef COMMENT
/*
Cmdret
eexit ()
.
    Exit from the editor.
    Do appropriate saves, cleanups, etc.
    Only returns if there is a syntax error in the exit command or an error
    happened while saving files.  Otherwise it ends with a call to exit().
.
		  saves   updates      deletes     deletes
		  files  state file   keystroke    'changes'
			   (.es1)    file (.ek1)  file (.ec1)
		  -----  ----------  -----------  -----------
    exit           YES      YES          YES         YES
    exit nosave     -       YES          YES         YES
    exit quit       -        -           YES         YES
    exit abort      -        -            -          YES
    exit dump       -        -            -           -
*/
#endif
Cmdret
eexit ()
{
    Small extblind;
    static S_looktbl exittable[] = {
	"abort"   , EXABORT    ,
	"dump"    , EXDUMP     ,
	"nosave"  , EXNOSAVE   ,
	"quit"    , EXQUIT     ,
	0, 0
    };

    if (opstr[0] == '\0')
	extblind = EXNORMAL;
    else {
	if (*nxtop)
	    return CRTOOMANYARGS;
	extblind = lookup (opstr, exittable);
	if (extblind == -1  || extblind == -2) {
	    mesg (ERRSTRT + 1, opstr);
	    return (Cmdret) extblind;
	}
	extblind = exittable[extblind].val;
    }

    switch (extblind) {
    case EXNORMAL:
	if (saveall () == NO)
	    return CROK;
	break;

    case EXABORT:
    case EXDUMP:
    case EXNOSAVE:
    case EXQUIT:
	d_put (0);
	fixtty ();
	screenexit (YES);
	break;

    default:
	return CRBADARG;
    }

    switch (extblind) {
    case EXDUMP:
	fatal (FATALEXDUMP, "Aborted");

    case EXNORMAL:
    case EXNOSAVE:
	if (!notracks)
	    savestate ();
    case EXQUIT:
    case EXABORT:
	cleanup (YES, extblind != EXABORT);
	if (extblind == EXNORMAL) {
#ifdef PROFILE
	    monexit (0);
#else
	    exit (0);
#endif
	    /* NOTREACHED */
	}
    }
#ifdef PROFILE
    monexit (1);
#else
    exit (1);
#endif
    /* NOTREACHED */
}

#ifdef COMMENT
/*
Flag
saveall ()
.
    Fix tty modes, put cursor at lower left.
    Do the actual modifcations to disk files:
      Save all the files that were modified and for which UPDATE is set.
      Rename files that were renamed.
      Delete files that were deleted.
    Return YES if all went OK, else NO.
*/
#endif
Flag
saveall ()
{
    register Fn i;
    register int j;

    d_put (0);
    fixtty ();
    screenexit (NO);

    /* The strategy here is to stave off all permanent actions until as
    /* late as possible.  Deletes and renames are not done until necessary.
    /* On the other hand, according to this precept, all of the modified
    /* files should be saved to temp files first, and then linked or
    /* copied to backups, etc.  But this would take too much disk space.
    /* So the saves go one at a time, with some deleting and renaming along
    /* the way.  If we bomb during a save and any deletes or renames have
    /* happened, we're probably screwed if we want to replay
    /**/

    /* delete all backup files to make disk space */
    /* then do the saves */
    for (j = 1; ;) {
	for (i = FIRSTFILE + NTMPFILES; i < MAXFILES; i++) {
	    if (   (fileflags[i] & (INUSE | UPDATE | DELETED))
		   == (INUSE | UPDATE)
		&& la_modified (&fnlas[i])
		&& savefile ((char *) 0, i, (Flag) fileflags[i] & INPLACE, (Flag) j) == NO
	       ) {
 err:           putchar ('\n');
		fflush (stdout);
		reenter ();
		setitty ();
		setotty ();
		windowsup = YES;
		fresh ();
		return NO;
	    }
	}
	if (j-- == 0)
	    break;
	putline (YES);
	la_sync (NO);   /* flush all cached buffers out */
    }


    /* do any deleting as necessary
    /* if any deleted names conflicted with NEW names or RENAMED names,
    /* they were already deleted by the save loop above */
    for (i = FIRSTFILE + NTMPFILES; i < MAXFILES; i++) {
	if ((fileflags[i] & (UPDATE | DELETED)) == (UPDATE | DELETED)) {
	    mesg (TELALL + 2, "DELETE: ", names[i]);
	    unlink (names[i]);
	}
    }

    /* do any renaming as necessary
    /* if any oldnames conflict with NEW names,
    /* or if any saved names wre RENAMED,
    /* they were already renamed by the save loop above */
    for (i = FIRSTFILE + NTMPFILES; i < MAXFILES; i++) {
	if (   (fileflags[i] & (UPDATE | RENAMED)) == (UPDATE | RENAMED)
	    && !svrename (i)
	   )
	    goto err;
    }

    putchar ('\n');
    fflush (stdout);
    return YES;
}

#ifdef COMMENT
/*
Flag
savestate ()
.
    Update the state file.
    See State.fmt for a description of the state file format.
*/
#endif
Flag
savestate ()
{
    register Short  i;
    char   *fname;
    register S_window *window;
    char stbuf[BUFSIZ];
    FILE *stfile;

    curwksp->ccol = cursorcol;
    curwksp->clin = cursorline;

    unlink (rfile);
    if ((stfile = fopen (rfile, "w")) == NULL)
	return NO;
    setbuf (stfile, stbuf);
    chmod (rfile,0600);

    /*  Put out a flag word which can't match revision number.
    /*  Later, if all is OK, we'll seek back to beginning and put out the
    /*  revision number.
    /**/
    putshort ((short) 0, stfile);

    /* terminal type name */
    putshort ((short) (strlen (tname) + 1), stfile);
    fputs (tname, stfile);
    putc ('\0', stfile);

    putc (term.tt_height, stfile);
    putc (term.tt_width, stfile);

    /* time of start of session */
    putlong (strttime, stfile);

    /* tabstops */
    putshort ((short) ntabs, stfile);
    if (ntabs > 0) Block {
	Reg1 int ind;
	for (ind = 0; ind < ntabs; ind++)
	    putshort ((short) tabs[ind], stfile);
    }

    putshort ((short) linewidth, stfile);

    if (searchkey == 0)
	putshort ((short) 0, stfile);
    else {
	putshort ((short) (strlen (searchkey) + 1), stfile);
	fputs (searchkey, stfile);
	putc ('\0', stfile);
    }

    putc (insmode, stfile);
    putc (patmode, stfile);     /* Added Purdue CS 10/8/82 MAB */

    putc (curmark != 0, stfile);
    if (curmark) {
	putlong  ((long) curmark->mrkwinlin, stfile);
	putshort ((short) curmark->mrkwincol, stfile);
	putc     (curmark->mrklin, stfile);
	putshort ((short) curmark->mrkcol, stfile);
    }

#ifdef LMCV19
#ifdef LMCAUTO
    putc (autofill, stfile);
    putshort (autolmarg, stfile);
#else  LMCAUTO
    putc ((char) 0, stfile);
    putshort (0, stfile);
#endif LMCAUTO
#endif LMCV19

    putc (nwinlist, stfile);
    for (i = Z; i < nwinlist; i++)
	if (winlist[i] == curwin)
	    break;
    putc (i, stfile);
    for (i = Z; i < nwinlist; i++) {
	window = winlist[i];
	putc (window->prevwin, stfile);
	putc     (window->tmarg, stfile);
	putshort ((short) window->lmarg, stfile);
	putc     (window->bmarg, stfile);
	putshort ((short) window->rmarg, stfile);
#ifdef LMCV19
	putc     (window->winflgs, stfile);
#endif LMCV19
	putshort ((short) window->plline, stfile);
	putshort ((short) window->miline, stfile);
	putshort ((short) window->plpage, stfile);
	putshort ((short) window->mipage, stfile);
	putshort ((short) window->lwin, stfile);
	putshort ((short) window->rwin, stfile);
	if (fname = names[window->altwksp->wfile]) {
	    putshort ((short) (strlen (fname) + 1), stfile);
	    fputs (fname, stfile);
	    putc ('\0', stfile);
	    putlong  ((long) window->altwksp->wlin, stfile);
	    putshort ((short) window->altwksp->wcol, stfile);
	    putc     (window->altwksp->clin, stfile);
	    putshort ((short) window->altwksp->ccol, stfile);
	}
	else
	    putshort ((short) 0, stfile);
	fname = names[window->wksp->wfile];
	putshort ((short) (strlen (fname) + 1), stfile);
	fputs (fname, stfile);
	putc ('\0', stfile);
	putlong  ((long) window->wksp->wlin, stfile);
	putshort ((short) window->wksp->wcol, stfile);
	putc     (window->wksp->clin, stfile);
	putshort ((short) window->wksp->ccol, stfile);
    }
    if (ferror (stfile)) {
	fclose (stfile);
	return NO;
    }
    fseek (stfile, 0L, 0);
    putshort (revision, stfile);   /* state file is OK */
    fclose (stfile);
    return  YES;
}
