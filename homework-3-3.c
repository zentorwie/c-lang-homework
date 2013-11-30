#include <stdio.h>
#include <string.h>

int str_convert(char[]);

int main()
{
    char number[11];
    char str[1000];
    int T;
//    printf("%d", str_convert("0124"));

    scanf("%d", &T);
    
    while (T--) {
	int i=0, flag=0, p=0, l;
	char ch;
	scanf("%s", str);
	l = strlen(str);
	for (i = 0; i < l; i++) {
	    if (str[i] >= '0' && str[i] <= '9') {
		if (flag) {
		    p++;
		}
		else {
		    flag = 1;
		    p = 0;
		}
		number[p] = str[i];
	    }
	    else {
		if (flag) {
		    flag = 0;
		    p++;
		    number[p] = '\0';
		    printf("%d ", str_convert(number));
		}
	    }
	}

	if (flag) {
	    flag = 0;
	    p++;
	    number[p] = '\0';
	    printf("%d ", str_convert(number));
	}
	printf("\n");
    }
    return 0;
}

int str_convert(char str[])
{
    int result = 0, i, l, oct = 1;
    l = strlen(str);
    for (i = l - 1; i >= 0; i--) {
	result += (str[i] - '0') * (oct*=10)/10;
    }
    return result;
}


int str_convert(char str[])
{
    int result = 0, i, l, oct = 1;
    l = strlen(str);
    for (i = l - 1; i >= 0; i--, oct*=10) {
	result += (str[i] - '0') * oct;
    }
    return result;
}
