#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int T, i, j, l, exsist; 
    char str1[60], str2[60];
    scanf("%d", &T);
    while (T--) {
	scanf("%s %s", str1, str2);
//	puts(str1);
//	puts(str2);
	
	l = strlen(str1);
	
	if (strlen(str2) != l)
	    printf("No\n");
	else {
	    exsist = 1;
	    for (i = 0; i < l; i++) {
		int flag = 0;
		for (j = 0; j < l; j++) {
		    if (toupper(str2[j]) == toupper(str1[i])) {
			str2[j] = '*';
			flag = 1;
			break;
		    }
		}
		if (flag == 0) {
		    exsist = 0;
		    printf("No\n");
		    break;
		}
	    }
	    if (exsist)
		printf("Yes\n");
	    
	}
	    


    }

    
    return 0;
}
