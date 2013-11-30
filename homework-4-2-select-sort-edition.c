#include <stdio.h>

void select_sort(int *, int, int);

int main()
{
    int n, m, i, j;
    int a[1000000];
    while (scanf("%d%d", &n, &m)==2) {
	for (i = 0; i < n; i++)
	    scanf("%d", &a[i]);
	
	select_sort(a, n, m);

	for (i = 0; i < m; i++) {
	    printf("%d ", a[i]);
	}
	printf("\n");
    }
    return 0;
}

void select_sort(int *a, int size, int m) 
{
    int max, i, j, t;

    for (i = 0; i < m; i++) {
	max = i;
	for (j = i+1; j < size; j++) {
	    if (a[j] > a[max])
		max = j;
	}
	t = a[i], a[i] = a[max], a[max] = t;
    } 
    return;
}
 
