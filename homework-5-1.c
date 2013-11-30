#include <stdio.h>

#define MAXN 1010

int main()
{
    int T, n, i, j, prev, cur, p, max_len, max_count, cur_len, all_count;
    int a[MAXN], len[MAXN];
    scanf("%d", &T);
    while (T--) {
	scanf("%d", &n);
	if (n == 1) {
	    scanf("%d", &cur);
	    printf("1 1\n{%d}\n", cur);
	    continue;
	}
	scanf("%d", &prev);
	a[0] = prev;
	len[0] = 1;
	p = 0;
	max_len = 1;
	max_count = 1;
	n--;
	while (n--) {
	    scanf("%d", &cur);
	    if (cur == prev) {
		len[p]++;
	    }
	    else {
		p++;
		a[p] = cur;
		len[p] = 1;
	    }
	    prev = cur;
	    
	    if (len[p] > max_len) {
		max_len = len[p];
		max_count = 1;
	    }
	    else if  (len[p] == max_len) {
		max_count++;
	    }
	}
	all_count = p + 1;

//	for (i = 0; i < all_count; i++) 
//	    printf("%d\n", len[i]);

	//output
	printf("%d %d\n", max_count, max_len);
	for (i = 0; i < all_count-1; i++) {
	    printf("{");
	    for (j = 0; j < len[i]-1; j++) {
		printf("%d,", a[i]);
	    }
	    printf("%d},", a[i]);
//	    printf("\n");
	}
	printf("{");
	for (j = 0; j < len[i]-1; j++) {
	    printf("%d,", a[i]);
	}
	printf("%d}\n", a[i]);
    }
    return 0;
}
