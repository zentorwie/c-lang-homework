#include <stdio.h>
#include <math.h>
int main()
{
    int T, n, a, b, i, count;
    long int data[1110], sum;
    double S, A, sigma;
    scanf("%d", &T);

    while (T--) {
	count = 0;
	sum = 0;
	sigma = 0.0;
	A = 0.0;
	S = 0.0;
	scanf("%d%d%d", &n, &a, &b);
	for (i = 0; i < n; i++) {
	    scanf("%ld", &data[i]);
	    if (data[i] >= a && data[i] <= b) {
		count++;
	    }
	}
	if (count == 0) {
	    printf("0.00 0.00\n");
	    continue;
	}

	for (i = 0; i < n; i++) {
	    if (data[i] >= a && data[i] <= b) {
		A += data[i]*1.0/count;
	    }
	}
	
	printf("%.2f ", A);

	for (i = 0; i < n; i++) {
	    if (data[i] >= a && data[i] <= b) {
		sigma += pow(data[i] - A, 2.0)/(count*count);
	    }
	}
	
	S = sqrt(sigma);
	printf("%.2f\n", S);
	
	
    }
    return 0;
}
