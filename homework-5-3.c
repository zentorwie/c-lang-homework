#include <stdio.h>
#include <string.h>
#define MAXN 151

int main()
{
    int T, n, i, p, count, cur, origin, flag;
    int a[MAXN], v[MAXN], loop[MAXN][MAXN];
    
    scanf("%d", &T);
    while (T--) {
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++) {
	    scanf("%d", &a[i]);
	}
	for (i = 1; i <= n; i++) {
	    scanf("%d", &a[i]);
	}

	p = 1;
	memset(v, 0, sizeof(v));
	flag = 0;
	cur = 1;
	
	while (p <= n) {
	    if (flag) {
		cur = a[cur];
		v[cur] = 1;
		if (cur == origin) {
		    printf(")");
		    flag = 0;
		}
		else
		    printf(",%d", cur);

	    }
	    else {
		if (v[p]) {
		    p++;
		}
		else {
		    origin = cur = p;
		    v[cur] = 1;
		    printf("(%d", cur);
		    flag = 1;
		}
	    }
	}
	printf("\n");

	//output


    }
	
    
    
    
    return 0;
}
