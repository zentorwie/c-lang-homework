#include <stdio.h>

#define MAXN 100010

int main()
{
    int T, N, i, j, l_stone[MAXN], l_gap[MAXN], flag;
    double min, max, min_step, max_step, stone[MAXN][2];
    scanf("%d", &T);
    while (T--) {
	scanf("%d", &N);
	for (i = 0; i < N; i++) 
	    scanf("%d", &l_stone[i]);
	for (i = 0; i < N-1; i++)
	    scanf("%d", &l_gap[i]);
	
	//every stone
	stone[0][0] = 0;
	stone[0][1] = l_stone[0];
	for (i = 1; i < N; i++) {
	    stone[i][0] = stone[i-1][1] + l_gap[i-1];
	    stone[i][1] = stone[i][0] + l_stone[i];
	}
	
	//debug
	/* for (i = 0; i < N; i++) { */
	/*     printf("[%f, %f]\n", stone[i][0], stone[i][1]); */
	/* } */
	
	min_step = stone[1][0];
	max_step = stone[1][1]; 
	min = stone[1][0];
	max = stone[1][1];

	flag = 1;
	for (i = 1; i < N-1; i++) {
	    min += min_step;
	    max += max_step;
	    
	    if (!((min >= stone[i+1][0] && min <= stone[i+1][1]) || \
		  (max >= stone[i+1][0] && max <= stone[i+1][1]))) {
		flag = 0;
		break;
	    }
	    else {
		if (min <= stone[i+1][0])
		    min = stone[i+1][0];
		if (max >= stone[i+1][1])
		    max = stone[i+1][1];

		min_step = min / (i+1);
		max_step = max / (i+1);
	    }
		
	    
	    
	}

	if (flag) {
	    printf("%.2f\n", min_step);
	}
	else 
	    printf("impossible\n");
	
	
    }
    
    

    
    return 0;
}
