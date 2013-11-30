#include <stdio.h>

int main()
{
    int N, a, b, c, x, y ,i;
    double s;
    scanf("%d", &N);
    a=b=c=x=y=0;
    for (i = 0; i < N; i++) {
	scanf("%d%d", &a, &b);
	c = 0;
	if (b >= 60)
	    c++;
	if (b >= 70)
	    c++;
	if (b >= 80)
	    c++;
	if (b >= 90)
	    c++;
	x += a*c;
	y += a;
    }
    printf("%.2lf\n", (x*1.0)/y);
    return 0;
}
