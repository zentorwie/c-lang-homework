#include <stdio.h>
#include <string.h>

#define MAX_RESULT 10010
#define MAX_STR    110

int main()
{
    int T;
    char str_1[MAX_STR], str_2[MAX_STR], result[MAX_RESULT]; 
    
    scanf("%d", &T);
    while (T--) {
	int i, j, p;
	int l_1, l_2, more, sirslt;
	scanf("%s%s", str_1, str_2);
	l_1 = strlen(str_1);
	l_2 = strlen(str_2);
	
	for (i = 0; i < l_1; i++) 
	    str_1[i] -= '0';
	for (i = 0; i < l_2; i++)
	    str_2[i] -= '0';
	
	memset(result, 0, MAX_RESULT);
	for (i = l_2 - 1; i >= 0; i--) {
	    p = l_2 - 1- i; 
	    more = 0;
	    for (j = l_1 - 1; j >= 0; j--) {
		sirslt = result[p] + str_1[j] * str_2[i] + more;
		result[p++] = sirslt % 10;
		more = sirslt / 10;
	    }
	    result[p] = more;
	}

	//p will be the length of the result string
	
	//for (i = MAX_RESULT-1; i >= 0; i--) 
	//    if (result[i] != 0)
	//	break;
	if (result[p-1] == 0)
	    printf("0");
	else {
	    if (result[p] != 0)
		printf("%d", result[p]);
	    for (i = p-1; i >= 0; i--)
		printf("%d", result[i]);
	}
	printf("\n");
	
    }
    return 0;
}
