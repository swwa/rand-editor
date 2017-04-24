#ifdef COMMENT
	Copyright abandoned, 1983, The Rand Corporation
#endif

#include "la.local.h"

char *la_cfile = "changes";
#define MAXLINE 512

#ifdef UNIXV7
#include <signal.h>
char *ttyname ();
#endif
#ifdef UNIXV6
#include <sys/signals.h>
#endif
int sig ();

main (argc, argv)
int argc;
char *argv[];
{
    char test;
    int ind;

    if (argc-- <= 1) {
	    printf ("Usage: %s <test> <args> ...\n", argv[0]);
	    exit (1);
    }

    for (ind = 1; ind <= _NSIG; ++ind) {
#ifdef VAX
	if (ind == SIGILL)
#else
	if (ind == SIGABRT)
#endif
	    {}  /* do nothing */
	else
	    signal (ind, sig);
    }

    test = argv[1][0];
    for (ind = 1; ind < argc; ind++)
	argv[ind] = argv[ind + 1];

    la_maxchans = _NFILE;
    switch (test) {
    case 'u':
	return collecttest (argc, argv);

    case 'i':
	return inserttest (argc, argv);

    case 'g':
	return gettest (argc, argv);

    case 'd':
	return deletetest (argc, argv);

    case 'c':
	return clonetest (argc, argv);

    case 'p':
	return picktest (argc, argv);

    case 'P':
	return pointtest (argc, argv);

    case 's':
	return seektest (argc, argv);

    case 'b':
	return brktest (argc, argv);
    }
    return 0;
}

seektest (argc, argv)
int argc;
char *argv[];
{
    La_stream *tlas1;
    La_stream slas1;
    register int j;

    if (argc < 4){
	    printf ("Usage: %s s file [line# seektype]...\n", argv[0]);
	    exit (1);
    }
    if ((tlas1 = la_open (argv[1], "", &slas1, (La_bytepos) 0)) == (La_stream *)NULL) {
	printf ("Open failed: la_errno = %d\n", la_errno);
	exit (0);
    }
    la_fsddump (tlas1->la_file->la_ffsd, tlas1->la_file->la_lfsd, YES, "");
    for (j = 2; j < argc; j += 2) {
	(void) la_lseek (tlas1, (La_linepos) atoi (argv[j]), atoi (argv[j + 1]));
	la_sdump (tlas1, "");
    }
    la_fdump (tlas1->la_file, "");
 /* i = creat (",out", 0644);
    la_lflush (tlas1, (La_linepos) 0, la_lsize (tlas1), i, NO);
 */ printf ("%d\n", (int) la_close (tlas1));
    return 0;
}

brktest (argc, argv)
int argc;
char *argv[];
{
    La_stream *tlas1;
    La_stream slas1;
    La_fsd *ffsd, *lfsd, *n1fsd, *n2fsd;
    La_linepos line;
    La_linepos nlines;
    La_bytepos nbytes;

    if (argc != 4){
	printf ("Usage: %s b file line# nlines\n", argv[0]);
	exit (1);
    }
    line = atoi (argv[2]);
    nlines = atoi (argv[3]);

    if ((tlas1 = la_open (argv[1], "", &slas1, (La_bytepos) 0)) == (La_stream *)NULL) {
	printf ("Open failed: la_errno = %d\n", la_errno);
	exit (0);
    }
    (void) la_lseek (tlas1, line, 0);
    ffsd = tlas1->la_cfsd;
    (void) la_lseek (tlas1, line + nlines, 0);
    lfsd = tlas1->la_cfsd;
    (void) la_lseek (tlas1, line, 0);
    la_fsddump (ffsd, lfsd, YES, "");
    la_sdump (tlas1, "");

#ifdef LA_BP
    la_break (tlas1, BRK_REAL, &n1fsd, &n2fsd, &nlines, &nbytes);
#else
    la_break (tlas1, BRK_REAL, &n1fsd, &n2fsd, &nlines);
    nbytes = 0;
#endif
    printf ("Break results: lines=%D, bytes=%D, n1fsd=0x%04x, n2fsd=0x%04x\n",
	    nlines, nbytes, n1fsd, n2fsd);
    if ((ffsd = tlas1->la_cfsd)->fsdback)
	ffsd = ffsd->fsdback;
    (void) la_lseek (tlas1, line + nlines, 0);
    la_fsddump (ffsd, n2fsd, YES, "");
    (void) la_lseek (tlas1, 0, 0);
    (void) la_lseek (tlas1, line, 0);
    la_sdump (tlas1, "");

 /* la_fdump (tlas1->la_file, "");
    i = creat (",out", 0644);
    la_lflush (tlas1, (La_linepos) 0, la_lsize (tlas1), i, NO);
 */ printf ("%d\n", (int) la_close (tlas1));
    return 0;
}

clonetest (argc, argv)
int argc;
char *argv[];
{
    La_stream *tlas1, *tlas2;
    La_stream slas1, slas2;
    register int j;

    if (argc < 4){
	    printf ("Usage: %s c file [line# seektype]...\n", argv[0]);
	    exit (1);
    }
    if ((tlas1 = la_open (argv[1], "", &slas1, (La_bytepos) 0)) == (La_stream *)NULL) {
	printf ("Open failed: la_errno = %d\n", la_errno);
	exit (0);
    }
    la_fsddump (tlas1->la_file->la_ffsd, tlas1->la_file->la_lfsd, YES, "");
    for (j = 2; j < argc; j += 2) {
	(void) la_lseek (tlas1, (La_linepos) atoi (argv[j]), atoi (argv[j + 1]));
	la_sdump (tlas1, "");
	tlas2 = la_clone (tlas1, &slas2);
	la_sdump (tlas2, "");
	la_close (tlas2);
    }
 /* la_fdump (tlas1->la_file, "");
    i = creat (",out", 0644);
    la_lflush (tlas1, (La_linepos) 0, la_lsize (tlas1), i, NO);
 */ printf ("%d\n", (int) la_close (tlas1));
    return 0;
}

inserttest (argc, argv)
int argc;
char *argv[];
{
    register char *cp;
    La_stream *tlas1;
    La_stream slas1;
    La_linepos line;
    char buf[28];

    if (argc != 4 && argc != 5){
	printf ("Usage: %s i file line# string\n", argv[0]);
	exit (1);
    }
    line = atoi (argv[2]);

    if ((tlas1 = la_open (argv[1], "", &slas1, (La_bytepos) 0)) == (La_stream *)NULL) {
	printf ("Open failed: la_errno = %d\n", la_errno);
	exit (0);
    }
    (void) la_lseek (tlas1, line, 0);
    la_fsddump (tlas1->la_file->la_ffsd, tlas1->la_file->la_lfsd, YES, "");
    la_sdump (tlas1, "");
    la_fdump (tlas1->la_file, "");

    move (argv[3], buf, (unsigned int) sizeof buf);
    for (cp = buf; *cp; cp++)
	continue;
    *cp++ = '\n';

    if (la_linsert (tlas1, buf, cp - buf) == -1) {
	printf ("Insert result: %D\n", la_errno);
	exit (0);
    }

    (void) la_lseek (tlas1, line, 0);
    la_fsddump (tlas1->la_file->la_ffsd, tlas1->la_file->la_lfsd, YES, "");
    la_sdump (tlas1, "");
    la_fdump (tlas1->la_file, "");

    la_lflush (tlas1, (La_linepos) 0, la_lsize (tlas1), 1, NO);
    printf ("%d\n", (int) la_close (tlas1));
    return 0;
}

collecttest (argc, argv)
int argc;
char *argv[];
{
    La_stream *tlas1, *tlas2;
    La_stream slas1, slas2;
    La_linepos line;
    La_linepos ndel;
    int nbytes;
    La_linepos insret;
    int collect;

    if (argc != 4){
	printf ("Usage: %s u file line# insfile\n", argv[0]);
	exit (1);
    }
    line = atoi (argv[2]);

    if ((tlas1 = la_open (argv[1], "", &slas1, (La_bytepos) 0)) == (La_stream *)NULL) {
	printf ("Open failed: la_errno = %d\n", la_errno);
	exit (0);
    }
    if ((tlas2 = la_open (argv[3], "", &slas2, (La_bytepos) 0)) == (La_stream *)NULL) {
	printf ("Open failed: la_errno = %d\n", la_errno);
	exit (0);
    }
    (void) la_lseek (tlas1, line, 0);
    la_fsddump (tlas1->la_file->la_ffsd, tlas1->la_file->la_lfsd, YES, "");
    la_sdump (tlas1, "");
    la_fdump (tlas1->la_file, "");

    collect = 1;
    for (;;) {
	char buf[MAXLINE];
	if ((nbytes = la_lget (tlas2, buf, MAXLINE)) <= 0)
	    break;
	if ((insret = la_lcollect (collect, buf, nbytes)) == -1) {
	    printf ("Insert result: %D\n", la_errno);
	    exit (0);
	}
	collect = 2;
    }
    ndel = 0;
    if ((insret = la_lrcollect (tlas1, &ndel, tlas2)) == -1) {
	printf ("Insert result: %D\n", la_errno);
	exit (0);
    }
    printf ("Inserted: %D\n", insret);

    (void) la_lseek (tlas1, line, 0);
    la_fsddump (tlas1->la_file->la_ffsd, tlas1->la_file->la_lfsd, YES, "");
    la_sdump (tlas1, "");
    la_fdump (tlas1->la_file, "");

    la_lflush (tlas1, (La_linepos) 0, la_lsize (tlas1), 1, NO);
    printf ("%d\n", (int) la_close (tlas1));
    return 0;
}

deletetest (argc, argv)
int argc;
char *argv[];
{
    La_stream *tlas1, *tlas2;
    La_stream slas1, slas2;
    La_fsd *ffsd, *lfsd;
    La_linepos line;
    La_linepos nlines;

    if (argc != 4 && argc != 5){
	printf ("Usage: %s d file line# nlines [save]\n", argv[0]);
	exit (1);
    }
    line = atoi (argv[2]);
    nlines = atoi (argv[3]);

    if ((tlas1 = la_open (argv[1], "", &slas1, (La_bytepos) 0)) == (La_stream *)NULL) {
	printf ("Open failed: la_errno = %d\n", la_errno);
	exit (0);
    }
    if ((tlas2 = la_open ("", "n", &slas2, (La_bytepos) 0)) == (La_stream *)NULL) {
	printf ("Open failed: la_errno = %d\n", la_errno);
	exit (0);
    }
    (void) la_lseek (tlas1, line, 0);
    ffsd = tlas1->la_cfsd;
    (void) la_lseek (tlas1, line + nlines, 0);
    lfsd = tlas1->la_cfsd;
    (void) la_lseek (tlas1, line, 0);
    la_fsddump (ffsd, lfsd, YES, "");
    la_sdump (tlas1, "tlas1");

    nlines = la_ldelete (tlas1, nlines, argc == 5? tlas2 : 0);
    printf ("Delete results: lines=%D\n", nlines);
    if ((ffsd = lfsd = tlas1->la_cfsd)->fsdback)
	ffsd = ffsd->fsdback;
    la_fsddump (ffsd, lfsd, YES, "");
    la_sdump (tlas1, "tlas1");

    if (argc == 5) {
	la_fsddump (tlas2->la_file->la_ffsd, tlas2->la_file->la_lfsd, YES,
		    "tlas2");
	la_sdump (tlas2, "tlas2");
    }
    la_fdump (tlas1->la_file, "tlas1");
    if (argc == 5)
	la_fdump (tlas2->la_file, "tlas2");

    Block {
	int out;
	if ((out = creat (",out", 0644)) >= 0)
	    printf ("Flushed: %D\n",
		 la_lflush (tlas1, (La_linepos) 0, la_lsize (tlas1), out, NO));
    }
    printf ("%d\n", (int) la_close (tlas1));
    return 0;
}

picktest (argc, argv)
int argc;
char *argv[];
{
    La_stream *tlas1, *tlas2, *tlas3;
    La_stream slas1, slas2, slas3;
    La_fsd *ffsd, *lfsd;
    La_linepos line;
    La_linepos nlines;

    if (argc != 4 && argc != 5){
	printf ("Usage: %s p file line# nlines [stay]\n", argv[0]);
	exit (1);
    }
    line = atoi (argv[2]);
    nlines = atoi (argv[3]);

    if (   (tlas1 = la_open (argv[1], "", &slas1, (La_bytepos) 0)) == (La_stream *)NULL
	|| (tlas3 = la_open ("", "n", &slas3, (La_bytepos) 0)) == (La_stream *)NULL
	|| (tlas2 = la_clone (&slas3, &slas2)) == (La_stream *)NULL
       ) {
	printf ("Open failed: la_errno = %d\n", la_errno);
	exit (0);
    }
    if (argc == 5)
	la_stayset (tlas2);
    (void) la_lseek (tlas1, line, 0);
    ffsd = tlas1->la_cfsd;
    (void) la_lseek (tlas1, line + nlines, 0);
    lfsd = tlas1->la_cfsd;
    (void) la_lseek (tlas1, line, 0);
    la_fsddump (ffsd, lfsd, YES, "");
    la_sdump (tlas1, "tlas1");
    la_fdump (tlas1->la_file, "tlas1");

    nlines = la_lcopy (tlas1, tlas3, nlines);
    printf ("Copy results: lines=%D\n", nlines);

    la_fsddump (tlas2->la_file->la_ffsd, tlas2->la_file->la_lfsd, YES, "");
    la_sdump (tlas2, "tlas2");
    la_sdump (tlas3, "tlas3");

    la_fdump (tlas1->la_file, "tlas1");
    la_fdump (tlas2->la_file, "tlas2");

    {
    int i;

    i = creat (",out", 0644);
    printf ("Flushed: %D\n",
	     la_lflush (tlas2, (La_linepos) 0, la_lsize (tlas2), i, NO));
    }
    return 0;
}

pointtest (argc, argv)
int argc;
char *argv[];
{
    La_stream *tlas;
    La_stream slas;
    La_fsd *ffsd, *lfsd;
    La_linepos line;
    La_linepos nlines;

    if (argc != 3 && argc != 4) {
	printf ("Usage: %s P file line# [nlines]\n", argv[0]);
	exit (1);
    }
    line = atoi (argv[2]);
    if (argc == 4)
	nlines = atoi (argv[3]);
    else
	nlines = 1;

    if ((tlas = la_open (argv[1], "", &slas, (La_bytepos) 0)) == (La_stream *)NULL) {
	printf ("Open failed: la_errno = %d\n", la_errno);
	exit (0);
    }

    (void) la_lseek (tlas, line, 0);

    {
	int count;
	char *cp;

	count = la_lpnt(tlas, &cp);
	write(1, cp, count);
    }
    return 0;
}

gettest (argc, argv)
int argc;
char *argv[];
{
    La_stream *tlas1;
    La_stream slas1;
    register int j;
    int lbyte;
    int nbytes;
    char buf[MAXLINE];

    if (argc < 4){
	    printf ("Usage: %s g file [line# lbyte #bytes]...\n", argv[0]);
	    exit (1);
    }
    if ((tlas1 = la_open (argv[1], "", &slas1, (La_bytepos) 0)) == (La_stream *)NULL) {
	printf ("Open failed: la_errno = %d\n", la_errno);
	exit (0);
    }
    la_fsddump (tlas1->la_file->la_ffsd, tlas1->la_file->la_lfsd, YES, "");
    for (j = 2; j < argc; j += 3) {
	(void) la_lseek (tlas1, (La_linepos) atoi (argv[j]), 0);
	tlas1->la_lbyte = lbyte = atoi (argv[j + 1]);
	tlas1->la_ffpos += lbyte;
	tlas1->la_bpos += lbyte;
	if ((nbytes = atoi (argv[j + 2])) > MAXLINE) {
	    printf ("%d > %d.  Abort.\n", nbytes, MAXLINE);
	    break;
	}
	la_sdump (tlas1, "");
	nbytes = la_lget (tlas1, buf, nbytes);
	printf ("%d: %*.*s\n", nbytes, nbytes, nbytes, buf);
	la_sdump (tlas1, "");
    }
 /* la_fdump (tlas1->la_file, "");
    i = creat (",out", 0644);
    la_lflush (tlas1, (La_linepos) 0, la_lsize (tlas1), i, NO);
 */ printf ("%d\n", (int) la_close (tlas1));
    return 0;
}

sig ()
{
    abort ();
}

/* VARARGS1 */
dbgpr (fmt)
char *fmt;
{
    printf ("%r", &fmt);
    fflush (stdout);
    return;
}
