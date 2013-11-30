#include <stdio.h>

int main()
{
    int  a, b, c, s, min, max;
    while (scanf("%d%d%d", &a, &b, &c)==3) {
	s = a+b+c;
	min = max = a;
	if (b > max)
	    max = b;
	if (b < min)
	    min = b;
	if (c > max)
	    max = c;
	if (c < min)
	    min = c;
	if (a == b || b == c || a == c)
	    printf("%d\n", max);
	else
	    printf("%d\n", s - min - max);
    }
   
    return 0;
}
