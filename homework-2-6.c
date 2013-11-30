#include <stdio.h>

int main()
{
    int T, cd, song, n, left, count;
    scanf("%d", &T);
    while (T--) {
	scanf("%d%d", &song, &cd);
	if (cd == 13)
	    cd--;
	n = (song-1) / cd + 1;
	if ((cd == 14 || song < cd) && song % cd == 13 )
	    n++;
	printf("%d\n", n);
    }
    return 0;
}
