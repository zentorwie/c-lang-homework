#include <stdio.h>
int main()
{
    int n, T, m, p=0, i;
    scanf("%d%d", &n, &T);
    while (T--) {
	scanf("%d", &m);
	for (i = 0; i < n; i++) 
	    printf("%d ", (i + n - (m % n)) % n + 1);
	printf("\n");
    }
    return 0;
}
