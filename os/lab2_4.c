#include <stdio.h>

int main(int argc, char** argv)
{
	long t[10], *p;
	int i;

	for (i=0; i<10; i++)
	    t[i] = i;

    p = t;

	for (i=0; i<10; i++)
		printf("%ld %ld %ld %ld\n", t[i], p[i], *(p+1), *(t+1));

	return 0;
}
