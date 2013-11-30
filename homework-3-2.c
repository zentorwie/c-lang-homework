#include <stdio.h>
#include <string.h>

int getn(char str[]);
int s2int(char ch);
int main()
{
    char n[220];
    int sum = 0, dif = 0, s1 = 0, s2 = 0, T, l;
    int i, j;

    scanf("%d", &T);
    while (T--) {
	sum = 0;
	s1 = 0;
	s2 = 0;
	dif = 0;
	scanf("%s", n);
	l = strlen(n);
	for (i = 0; i < l; i++) {
	    if (i % 2 == 0)
		s1 += s2int(n[i]); //jishu
	    else 
		s2 += s2int(n[i]);
	    sum = s1 + s2;
	    dif = s1 - s2;
	    if (dif < 0)
		dif = -dif;
//	    printf("sum = %d\n", sum);
	}
	if (sum % 3 == 0)
	    printf("yes ");
	else 
	    printf("no ");

	if (dif % 11 == 0)
	    printf("yes");
	else 
	    printf("no");
	printf("\n");
    }
    return 0;
}

/*
int getn(char str[])
{
    char t[220]={0};
    char left[220]={0};
    
    int i, j, temp, less=0;
    int l = strlen(str);
//    printf("string length is : %d\n", l);
    left[0] = s2int(str[l-1]);
    for (i = l-1, j=0; i >= 0; i--, j++) {
	t[j] = left[j];
	temp = s2int(str[i]) - t[j];

	if (less == 1) {
	    less = 0;
	    temp--;
	}

	if (temp < 0) {
	    less = 1;
	    temp += 10;
	}

	left[j+1] = temp;
//	printf("left = %d, t = %d, temp = %d\n\n", left[j], t[j], temp);

	    
    }
//    printf("%s", str);
//    for (i = 0; i < l - 1; i++)
//	printf("%d", left[i]);
//    printf("\n");
//    for (i = 0; i < l - 1; i++)
//	printf("%d", t[i]);
    if (left[j-1] == 0)
	return 1;
    else 
	return 0;
    
}
*/
int s2int(char ch)
{
    return ch - '0';
}


