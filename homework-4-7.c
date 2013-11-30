#include <stdio.h>
#include <string.h>
void select_sort(char*, int);

int main()
{
    char key[25], str[1010], table[25][50], seq[25];
    int l_key, l_str, p, i, j, row_all, o_l_str;
    int count;
    int key_a[25]={0};
    gets(key);
    gets(str);
    l_key = strlen(key);
    l_str = strlen(str);
    o_l_str = l_str;

    count = 0;
    for (i=0; i < l_str; i++) {
	if (str[i] == ' ')
	    count++;
    }
    
    l_str -= count;

//    printf("lk = %d\nls = %d\n", l_key, l_str);
    row_all = (l_str+l_key-1) / l_key;
//    printf("rowa = %d\n", row_all);
    for (p = 0, j = 0; j < row_all; j++) {
	for (i = 0; i < l_key; i++, p++) {
	    if (p >= o_l_str)
		table[i][j] = 'E';
	    else if (str[p] == ' ')
		i--;
	    else {
		if (str[p] >= 'a' && str[p] <= 'z')
		    str[p] += 'A'-'a';
		table[i][j] = str[p];
	       
	    }
	}
    }
    for (i = 0; i < l_key; i++)
	table[i][row_all] = '\0';
    

    for (i = 0; i < l_key; i++)
	seq[i] = key[i];
        
    select_sort(seq, l_key);
    /* for (i = 0; i < l_key; i++) */
    /* 	printf("%3d", seq[i]); */
    
    for (i = 0; i < l_key; i++)
	for (j = 0; j < l_key; j++)
	    if (seq[i] == key[j] && key_a[j] == 0) {
		key_a[j] = 1;
		printf("%s", table[j]);
		break;
	    }
    printf("\n");
    return 0;
}


void select_sort(char *key_char, int size)
{
    int i, j, t, min;
    for (i = 0; i < size -1; i++) {
	min = i;
	for (j = i+1; j < size; j++) {
	    if (key_char[j] < key_char[min]) {
		min = j;
	    }
	}
	t = key_char[i], key_char[i] = key_char[min], key_char[min] = t;
    }

    //  for (i = 0; i < size; i++) 
//	printf("%c", key_char[i]);
    //  printf("\n");
    
    return;
}
