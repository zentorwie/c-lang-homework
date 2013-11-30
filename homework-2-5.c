#include <stdio.h>

int main()
{
    int R[10010]={0}, L, M, a, b, i, c;
    scanf("%d%d", &L, &M);
    
    while (M--) {
	scanf("%d%d", &a, &b);
	for (i = a; i <= b; i++)
	    R[i] = 1;
    }
    c = 0;
    for (i = 0; i <= L; i++)
	if (!R[i])
	    c++;
    printf("%d\n", c);
    
    return 0;
}
