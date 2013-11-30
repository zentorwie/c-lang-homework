#include <stdio.h>

int main()
{
    int T, a, b, c, t;
    scanf("%d", &T);
    while (T--) {
	scanf("%d%d%d", &a, &b, &c);
	if (a > b)
	    t=a,a=b,b=t;
	if (b > c)
	    t=b,b=c,c=t;
	if (a > c)
	    t=a,a=c,c=t;
	if (a==b||b==c||a==c)
	    printf("%d\n", c);
	else
	    printf("%d\n", b);
    }
    return 0;
}
