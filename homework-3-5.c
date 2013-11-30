#include <stdio.h>
#include <string.h>
int main()
{
    int T, count;
    char n;
    char key[22];
    char title[110];
    int p; 
    int l_key, l_title;
    
    scanf("%d", &T);
    
    while (T--) {
	scanf("%d", &n);

	printf("n=%d\n", n);
        getchar();
	fgets(key, sizeof(key), stdin);


	l_key = strlen(key);
	key[l_key-1] = '\0';
	l_key = strlen(key);
	count = 0;
	while (n--) {
	    fgets(title, sizeof(title), stdin);
	    l_title = strlen(title);
	    title[l_title-1] = '\0';
	    l_title = strlen(title);
	    p = 0;
	    for (i = 0; i < l_title; i++) {
		
	    }
	    
	}
	printf("%d\n", count);
    }
    return 0;
}
