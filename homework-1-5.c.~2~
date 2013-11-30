#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int T,n,i,j;
    char ch;
    scanf("%d", &T);
    while (T--) {
	scanf("%d %c", &n, &ch);
	for (i = 1; i <= n; i++) {
	    for (j = 0; j < n-i; j++) 
		printf(" ");
	    for (j = 0; j < 2 * i -1; j++)
		printf("%c", ch);
	    putchar('\n');
	}
	for (i = 2; i <= n; i++) {
	    for (j = 0; j < i-1; j++) 
		printf(" ");
	    for (j = 0; j <= 2*n - 2*i; j++)
		printf("%c", ch);
	    putchar('\n');
	}
    }
    return 0;
}
