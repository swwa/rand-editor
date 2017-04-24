#ifdef COMMENT
	Copyright abandoned, 1983, The Rand Corporation
#endif

#include <stdio.h>
#include "ff.local.h"

main(argc, argv)
char **argv;
{
        Ff_stream *fi;
        Ff_stream *fo;
        int chr;
        char buf[100];
        register int j;

        fprintf (stderr, "Starting\n");
        fo = ff_open ("xxx", 1, 0);
	if (fo == (Ff_stream *)NULL) {
		fprintf(stderr, "can't open fo\n");
		exit (1);
	} else
        	fprintf (stderr, "fo is open\n");
        ff_alloc (2, 0);
        fprintf (stderr, "ff_alloc done\n");

        while (--argc >= 1) {
                ++argv;
                if ((fi = ff_open(*argv, 0, 0)) == (Ff_stream *)NULL) {
                        fprintf(stderr, "cat: can't open %s\n", *argv);
                        continue;
                }
                for (;;) {
                    if ((j = ff_read (fi, buf, sizeof buf, 0)) <= 0)
                        break;
                    if (ff_write (fo, buf, j) != j)
                        break;
                }
        /*      while ((chr = ff_getc(fi)) != EOF)
                        ff_putc(chr, fo);
        */
                ff_close(fi);
        }
        exit (0);
}
