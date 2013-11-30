#include <stdio.h>

int main()
{
    int T, all, i, c;
    scanf("%d", &T);
    while (T--) {
	scanf("%d", &all);
	i = -1;
	c = 0;
	while (all - (c += (i+=2)) >= 0);
	c = c - i;
	printf("%d\n", c);
    }
    return 0;
}
