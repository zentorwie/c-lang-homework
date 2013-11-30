#include <stdio.h>
#include <math.h>

int main()
{
    int T, n, i;
    double d,c,min;
    scanf("%d", &T);
    while (T--) {
	scanf("%d%lf", &n, &c);
	min = 100000.0;
	for (i = 1; i < n; i++) {
	    scanf("%lf", &d);

	    if (fabs(d - c) < fabs(min))
		min = d - c;
	    c = d;
	}
	printf("%.2f\n", min);
	
    }
    return 0;
}
