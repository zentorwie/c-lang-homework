#include <stdio.h>
#include <string.h>

int main()
{
    char index[21], key[21], str[1010], table[501][21], t, ti;
    int l_str, n, m, i, j, T, min, p;
    scanf("%d", &T);
    getchar();
    while (T--) {
	gets(key);
	n = strlen(key);
	
	gets(str);
        l_str = strlen(str);
	m = l_str / n;
	if (l_str % n)
	    m++;
	
//	printf("m = %f\nn = %d\n", m, n);
	
	for (i = 0; i < n; i++) {
//	    if (key[i] >= 'a' && key[i] <= 'z')
//		key[i] -= 'a' - 'A';
	    index[i] = i;
	}

	//sort
	for (i = 0; i < n - 1; i++) {
	    min = i;
	    for (j = i + 1; j < n; j++) {
		if (key[j] < key[min]) {
		    min = j;
		}
	    }
	    t = key[i],        ti = index[i];
	    key[i] = key[min], index[i] = index[min];
	    key[min] = t,      index[min] = ti;
	}
	
	//debug
//	for (i = 0; i < n; i++) {
//	    printf("%c : %d\n", key[i], index[i]);
//	}

	for (j = 0, p = 0; j < n; j++) {
	    for (i = 0; i < m; i++, p++) {
		table[i][index[j]] = str[p];
	    }
	}
	
	for (i = 0; i < m; i++)
	    for (j = 0; j < n; j++)
		printf("%c", table[i][j]);
	printf("\n");
	    
    }
    

    return 0;
}
