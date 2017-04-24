void fill ( d, n, c)
char *d;
int n;
char c;
{
	while (n-- > 0)
		*d++ = c;
}
