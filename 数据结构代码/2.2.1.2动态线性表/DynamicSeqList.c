#include<stdio.h>
#include<Windows.h>

#define SIZE 10

typedef struct
{
	int* data;//存放的数据
	int len;//线性表的长度
	int MaxSize;////数组最大容量
}Sqlist;
int main()
{
	Sqlist* sqlist;
	sqlist = (Sqlist*)malloc(SIZE * sizeof(Sqlist*));
	sqlist->data = (int*)malloc(SIZE * sizeof(int*));
	int q = 29;
	int s = 23;

	sqlist->data = &q;

	printf("%d", *(sqlist->data));

	system("pause");
	return 0;
}