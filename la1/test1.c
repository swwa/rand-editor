#include "la.local.h"

main(argc, argv)
int argc;
char *argv[];
{
	La_stream *plas;

	if(argc != 2) {
		fprintf(stderr,"No file specified\n");
		exit(1);
	}
	plas = la_open (argv[1], "", (void *)NULL, (La_bytepos) NULL);
	if (plas == (La_stream *)NULL) {
		printf("Open failed: %d\n", la_errno);
		exit (1);
	}
	la_fdump(plas->la_file, argv[1]);
	la_close(plas);
	return 0;
}
