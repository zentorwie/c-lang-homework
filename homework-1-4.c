#include <stdio.h>

int main()
{
    int T,i,n;
    double a, s, min, max;
    scanf("%d", &T);
    while (T--) {
	min = 10.0;
	max = 0.0;
	s = 0.00;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
	    scanf("%lf", &a);
//	    printf("a = %f\n", a);
	    if (a < min)
		min = a;
	    if (a > max)
		max = a;
	    s = s + a;
	}
//	printf("%f", s);
	printf("%.2f\n", (s - max - min)/(n-2));
    }	
    return 0;
}
