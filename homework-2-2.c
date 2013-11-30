#include <stdio.h>

int main()
{
    int T, a, b, c, A[10][10], B[10][10];
    int i, j, k;
    scanf("%d", &T);
    while (T--) {
	int C[10][10]={0};
	scanf("%d%d%d", &a, &b, &c);

	for (i = 0; i < a; i++)
	    for (j = 0; j < b; j++)
		scanf("%d", &A[i][j]);
	for (i = 0; i < b; i++)
	    for (j = 0; j < c; j++)
		scanf("%d", &B[i][j]);

	for (i = 0; i < a; i++) 
	    for (j = 0; j < c; j++) 
		for (k = 0; k < b; k++) 
		    C[i][j]+=(A[i][k]*B[k][j]);
		
	for (i = 0; i < a; i++) {
	    for (j = 0; j < c; j++)
		printf("%d ", C[i][j]);
	    printf("\n");
	}
	printf("\n");
    }
    
    return 0;
}
