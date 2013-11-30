#include <stdio.h>
#include <math.h>


#define MAXN 50000
int isPrime(int);
void add_to_list(int number);
int is_in_list(int number);

int prime_list[MAXN];
int prime_count=0;

int main()
{
    int i, T, count, n;
    int factor, tried, flag, p;
    count = 1;

/*
    for (i = 0; i <50; i++) {
	if(isPrime(i))
	    printf("%d ", i);
	
    }
    printf("\n");
    for (i = 0; i < prime_count; i++) {
	printf("%d ", prime_list[i]);
    }
*/  
    add_to_list(2);
    for (i = 3; i < 50000; i+=2) {
//	printf("Yes\n");
	if (isPrime(i))
	    add_to_list(i);
    }
    /* for (i = 0; i < prime_count; i++) { */
    /* 	printf("%2d %2d\n", i, prime_list[i]); */
    /* } */

    scanf("%d", &T);
    while (T--) {
	scanf("%d", &n);
	printf("%d=", n);
//	factor = prime_list[0];
	p = 0;
	flag = 0;
	while(prime_list[p] <= (int)sqrt(n)) {
	    if (n % prime_list[p] == 0) {
		printf("%d*", prime_list[p]);
		n = n/prime_list[p];
		flag = 1;
	    }
	    else
		flag = 0;
	    
	    if (!flag)
		p++;
	}
	printf("%d\n", n);

	
    }

    return 0;
}

int isPrime (int number)
{
    int i;
    if (number <= 1)
	return 0;
    if (number == 2)
	return 1;
    for (i = 3; i < sqrt(number) +1 ; i+=2) {
	if (number % i == 0)
	    return 0;
    }
//    add_to_list(number);
    return 1;

}


int is_in_list(int number)
{
    int i;
    for (i = 0; i < prime_count; i++) 
	if (prime_list[i] == number)
	    return 1;
   
    return 0;
}

void add_to_list(int number)
{
    prime_list[prime_count++] = number;
    
    return;
}
