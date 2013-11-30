#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int T, seq[310], j_index, prev, cur, n, i;
    

    scanf("%d", &T);
    while (T--) {
	memset(seq, 0, sizeof(seq));
	
	scanf("%d%d", &n, &prev);
	
	for (i = 0; i < n - 1; i++) {
	    scanf("%d", &cur);
	    j_index = cur - prev;
	    if (j_index < 0) j_index = -j_index;
	    if (j_index < n)
		seq[j_index] = 1;
	    prev = cur;
	}




	for (i = 1; i < n; i++) {
	    if (seq[i] == 0)
		break;
	}

	if (i == n)
	    printf("Jolly\n");
	else
	    printf("Not jolly\n");
	

	
    }
    
    return 0;
}
