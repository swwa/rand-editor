#include <localenv.h>
#include	<stdio.h>

long
getlong (iop)
register FILE *iop;
{
    long i;
    register tmp;
    register char *cp;

    cp = (char *) &i;
    tmp = sizeof (long);
    *cp++ = getc (iop);
    if (feof(iop))
	return -1;
    --tmp;
    do
	*cp++ = getc (iop);
    while (--tmp);

    return i;
}
