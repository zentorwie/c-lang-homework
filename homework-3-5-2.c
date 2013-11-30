#include <stdio.h>
#include <string.h>

int main()
{
    char key[15], str[110], temp[110];
    int N, T, flag=0, p=0, i, l;
    int count;
    scanf("%d", &T);
    while (T--) {
	
	scanf("%d", &N);
	getchar();
	gets(key);
	count = 0;
	while (N--) {
	    gets(str);
//	    puts(key);
//	    puts(str);
	    
	    flag = 0;
	    l = strlen(str);
	   
	    for (i = 0; i <= l; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') ) {
		    if (flag) {
			p++;
		    }
		    else {
			flag = 1;
			p = 0;
		    }
		    temp[p] = str[i];
		}
		else {
		    if (flag) {
			flag = 0;
			p++;
			temp[p] = '\0';
			if ((strcmp(key,temp) == 0)) {
			    count++;
			    break;
			    //	    puts("GET!");
			}
		    }
		}
	    }
/*	    if (flag) {
		flag = 0;
		p++;
		temp[p] = '\0';
		if ((strcmp(key,temp) == 0)){
		    count++;
		    //puts("GET!");
		}
		}*/

	   


	}
	if (count!=0)
	    printf("%d\n", count);
	else
	    printf("Do not find\n");
	printf("\n");
    }
    return 0;
}
