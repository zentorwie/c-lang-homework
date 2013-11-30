#include <stdio.h>



void insert(int, int *, int);


typedef struct node{
    int data;
    int next;
} Point;


int get_where(Point *, int, int, int);
void print_a(Point *, int);

int main()
{
    int i;
    Point a[1000000];
    int t_data, count, where, t;
    int n, m;
/*    
    for (i = 0; i < 10; i++) {
	a[i].data = 10-i;
	a[i].next = i+1;
    }


    for (;;) {
	scanf("%d", &t_data);
	printf("insert point : %d\n", get_where(a, t_data, 5));
	for (i = 0; i < 10; i++) {
	    printf("%3d", a[i].data);
	 
	}
	printf("\n");
	for (i = 0; i < 10; i++) {
	 
	    printf("%3d", a[i].next);
	}
    }
    
    for (i = 10; i < 14; i++) {
	scanf("%d", &t_data);
	a[i].data = t_data;
	where = 2;
	//insert chain node
	t = a[where].next;
	a[where].next = i;
	a[i].next = t;

    }
    /*for (i = 0; i < 14; i++) {
      printf("%d ", a[i].data);

      }
      printf("\n");
    print_a(a, 13);

    
    
    return 0;
*/
    
    while (scanf("%d%d", &n, &m) == 2) {
	if (m > n)
	    m = n;
	count = 1;
	a[0].data = 10000000;
	a[0].next = 1;
	a[1].data = -10000000;
       	for (i = 1; i <= n; i++) {
	    
	    scanf("%d", &t_data);
	    count++;
	    
	    where = get_where(a, t_data, m+1, count);
	    if (where == -1)
		continue;

	    
	    a[i].data = t_data;
	    
	    //insert chain node
	    t = a[where].next;
	    a[where].next = i;
	    a[i].next = t;
//	    printf("insert point : %d\n%d\n", where, a[where].next);
	}
	
	print_a(a, m);

    }
    

    return 0;
}

int get_where(Point *a, int data, int end, int contain)
{
    int current = 0, prev = 0, count = 1;
    if (end == 1 && contain == 1)
	return 0;
    while (data < a[current].data && count < contain ) {
//	printf("t_data : %d\nNode : a[%d]\ndata : %d\nnext : %d\n\n",		       data, current, a[current].data, a[current].next);
	if (count >= end) {
	    //    printf("Exceed!\n");
	    return -1;
	}
	else {
	    prev = current;
	    current = a[current].next;
	    count++;
	}
    }
    
    return prev;
}

void print_a(Point *a, int end)
{
    int current = a[0].next;
    int count = 1;
    while (count++ <= end) {
	printf("%d ", a[current].data);
	current = a[current].next;
    }

    printf("\n");
	
    return;
}
