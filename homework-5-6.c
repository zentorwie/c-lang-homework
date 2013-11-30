#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXN 1200

void swap_str(char *str1, char *str2);
void get_data(char *student, char *result, int *pro_num, char *str);


void pro_data(char *student, char *result, int pro_num, char stu[][52], int *problem, int score[][MAXN]);



int count_student = 0;
int count_problem = 0;

typedef struct {
    char s[100];
    int no;
} submit;


int main()
{
    int T, min, i, j, t, p;
    int score[MAXN][MAXN];
    int sum[MAXN] = {0};
    char stu[MAXN][52];
    char str[200];
    submit str_group[2010];
    int problem[MAXN];
    char temp_str[100];
//        printf("data_get!\n");
    char student[52];
    char result[20];
    int pro_num;
    submit temp_submit;
//    printf("data_get!\n");
//    freopen("data.in", "r", stdin);

    scanf("%d\n", &T);
//    getchar();
//    printf("data_get!\n");
    memset(score, 0, sizeof(score));
    for (i = 0; i < T; i++) {
	gets(str_group[i].s);
	for (p = 0, j = 0; str_group[i].s[j] != '\0'; p++, j++) {
	    temp_str[p] = str_group[i].s[j];
	}
	temp_str[p] = 0;
	str_group[i].no = atoi(temp_str);
    }

    for (i = 0; i < T - 1; i++) {
	min = i;
	for (j = i + 1; j < T; j++) {
	    if (str_group[j].no < str_group[min].no) 
		min = j;
	}
	temp_submit = str_group[i];
	str_group[i] = str_group[min];
	str_group[min] = temp_submit;
	
    }
	
    
    for (i = 0; i < T; i++) {

	get_data(student, result, &pro_num, str_group[i].s);
//	printf("data_get!\n");
//	printf("name: %s\nresult: %s\npro_num: %d\n", student, result, pro_num);
	pro_data(student, result, pro_num, stu, problem, score);
	
    }
    
    //sum up
    for (i = 0; i < count_student; i++) {
	for (j = 0; j < count_problem; j++) {
	    sum[i] += score[i][j];
	}
    }    

    //sort
    for (i = 0; i < count_student-1; i++) {
	min = i;
	for (j = i + 1; j < count_student; j++) {
	    if (strcmp(stu[j], stu[min]) < 0)
		min = j;
	}
	swap_str(stu[min], stu[i]);
	t = sum[i];
	sum[i] = sum[min];
	sum[min] = t;
    }

    for (i = 0; i < count_student; i++) {
	printf("%s %d\n", stu[i], sum[i]);
    }
    
    printf("\n");
    

    return 0;
}

void swap_str(char *str1, char *str2)
{
    char t[51];
    strcpy(t, str1);
    strcpy(str1, str2);
    strcpy(str2, t);
    return;
}


void get_data(char *student, char *result, int *pro_num, char *str)
{
    int i, p;
    char t[5];
    

    
    for (i = 0; str[i] != '_'; i++);
    for (i++, p = 0; str[i] != '_'; i++, p++)
	student[p] = str[i];
    student[p] = 0;

    for (i++, p = 0; str[i] != '_'; i++, p++)
	result[p] = str[i];
    result[p] = 0;

    for (i++, p = 0; str[i] != '.'; i++, p++)
	t[p] = str[i];
    t[p] = 0;
//    printf("came\n");    
    *pro_num = atoi(t);
    
//    printf("GET!\n");
    return;
}


void pro_data(char *student, char *result, int pro_num, char stu[][52], int *problem, int score[][MAXN])
{
    int index_stu = 0;
    int index_pro = 0;
    int i, j;
    int temp_score;
    
//    printf("Proceeding...\n");
    
//    printf("\n>Input info:\n");
//    printf("name: %s\nresult: %s\npro_num: %d\n\n", student, result, pro_num);
    for (i = 0; i < count_student; i++) {
	if (strcmp(student, stu[i]) == 0) {
	    index_stu = i;
	    break;
	}
    }
    if (i == count_student) {
	strcpy(stu[count_student++], student);
	index_stu = i;
//	printf(">stu : %s<\n", stu[i]);
//	printf("> New guy added!\n");
    }
        
    for (i = 0; i < count_problem; i++) {
	if (pro_num == problem[i]) {
	    index_pro = i;
	    break;
	}
    }
    if (i == count_problem) {
	problem[count_problem++] = pro_num;
	index_pro = i;
//	printf("> New problem added!\n");
    }

    switch (result[0]) {
    case 'A':
	temp_score = 95;
	break;
	
    case 'P':
	temp_score = 90;
	break;
	
    case 'W':
	temp_score = 70;
	break;
	
    case 'C':
	temp_score = 50;
	break;
    default:
//	printf("Error!\n");
	break;
    }
    
//    printf(">>>>temp_score: %d\n", temp_score);
//    printf(">>>>score[index_stu][index_pro]: %d\n", score[index_stu][index_pro]);
    if (score[index_stu][index_pro] == 0 && temp_score == 95)
        score[index_stu][index_pro] = 100;
    else if (score[index_stu][index_pro] < temp_score)
	score[index_stu][index_pro] = temp_score;
//    printf(">>>>score[index_stu][index_pro]: %d\n", score[index_stu][index_pro]);	
//    printf("Finished!\n");
    return;
}
