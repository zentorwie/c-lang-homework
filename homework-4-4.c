#include <stdio.h>
#include <string.h>


int main()
{
    int N, i, j, team, l, count[2];
    char str[110], board[2][20];
   
    while (1) {
	scanf("%d", &N);
	if (N == 0)
	    break;
	memset(board, '-', sizeof(board));
	memset(count, 0, sizeof(count));
	team = 0;
	
	getchar();

	for (i = 0; i < N; i++) {
	    
//	    printf("player %d:\n", i+1);
	    gets(str);
	    
	    l = strlen(str);
	    
//	    printf("l = %d\n", l);
	    if (l <= 8) {
		board[team][i / 2] = 'O';
		count[team]++;
	    }
	    else if (str[l - 8] == ' ' && str[l - 7] == 'n' && str[l - 6] == 'o') {
		board[team][i / 2] = 'X';
	    }
	    else {
		//printf("Goal!\n");
		board[team][i / 2] = 'O';
		count[team]++;
	    }
	    team = 1 - team;
	}
	
	
	
	for (i = 1; i <= (N+1)/2; i++) {
	    printf("%d ", i);
	}
	printf("Score\n");
	 
	for (i = 0; i < (N+1) / 2; i++)
	    printf("%c ", board[0][i]);
	printf("%d\n", count[0]);

	for (i = 0; i < (N+1) / 2; i++)
	    printf("%c ", board[1][i]);
	printf("%d\n", count[1]);
	 
	     
	 
    }
    return 0;
}
