#include <stdio.h>

int main()
{
    int N, L, V, i, j, k, loc;
    char gen, drc;
    long int sum;
    int single_step;
    int max;
    while (1) {
	scanf("%d%d%d", &N, &L, &V);
	if (N == 0)
	    break;
	
	single_step = 0;
	sum = 0;
	max = 0;
	while (N--) {
	    scanf("%d %c %c", &loc, &gen, &drc);
	    if (drc == 'E') {
		if (loc == L)
		    continue;
		single_step = L - loc;
       	    }
	    else {
		if (loc == 0)
		    continue;
		single_step = loc;
	    }
	    if (single_step > max)
		max = single_step;
	    sum += single_step;
	}
	printf("%.2lf %.2lf\n", max*1.0/V, sum*1.0);
    }
    return 0;
}

