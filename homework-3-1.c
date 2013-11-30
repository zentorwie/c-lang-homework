#include <stdio.h>
#include <math.h>

int isPrime(int);

int main()
{
    int i, T, p[65550] = {0};
    p[2] = 1;
    for (i = 3; i <= 65536; i+=2) {
	if (isPrime(i))
	    p[i] = 1;
	
    }
    
    
    scanf("%d", &T);
    while (T--) {
	int a, b;
	scanf("%d%d", &a, &b);
	for (i = a; i <= b; i++) {
	    if (p[i])
		printf("%d ", i);
	}
	printf("\n");

    }
    return 0;
}

int isPrime (int number)
{
    int i;
    if (number <= 1)
	return 0;
    if (number % 2 == 0)
	return 1;
    for (i = 3; i < (int)sqrt(number) +1 ; i+=2) {
	if (number % i == 0)
	    return 0;
    }
    return 1;

}
