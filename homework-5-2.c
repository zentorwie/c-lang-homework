#include <stdio.h>
#include <string.h>
int main()
{
    int T, n, m, a, b, mark, count, i;
    int score[101];

    scanf("%d", &T);
    while (T--) {
	memset(score, 0, sizeof(score));

	scanf("%d", &n);
	
	while (n--) {
	    scanf("%d", &mark);
	    score[mark]++;
	}
	
	scanf("%d", &m);
	while (m--) {
	    scanf("%d%d", &a, &b);
	    count = 0; 
	    for (i = a; i <= b; i++) {
		count += score[i];
	    }
	    printf("%d\n", count);
	}
	printf("\n");

	
    }
    
    return 0;
}
