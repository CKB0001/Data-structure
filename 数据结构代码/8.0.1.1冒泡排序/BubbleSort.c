#include<stdio.h>
#include<Windows.h>
#define Maxsize 100

/*声明*/
int* Input(int num);//输入程序（因为折半插入排序数组0号位为哨兵，所以输入的数据从1号位开始）
int* Bubble_sort(int a[], int num);//排序
void Print(int a[], int num);//冒泡打印
void swqp(int* a, int* b);//交换

int main() {
	printf("请输入你想要输入多少个数字:");
	int  num;//输入多少个数字
	scanf_s("%d", &num);
	num = num ;//0号位暂存数据,所以应该多一位
	int* a;
	a = Input(num);
	/*（开始）将指针转化为数组（因为c语言函数不能将整个数组传过来）*/
	int i, b[Maxsize];
	for (i = 0; i < num; i++) {
		b[i] = *(a + i);
	}
	/*（结束）将指针转化为数组（因为c语言函数不能将整个数组传过来）*/

	//排序并将它转换为数组
	a = Bubble_sort(b, num);


	for (i = 0; i < num; i++) {
		b[i] = *(a + i);
	}

	printf("排序结果为\n");
	Print(b, num);//将结果打印出来
	system("pause");
	return 0;
}

//输入程序（因为折半插入排序数组0号位为哨兵，所以输入的数据从1号位开始）
int* Input(int num) {
	int a[Maxsize] = { 0 };
	int i;
	printf("请输入数据\n");
	int input;//输入的数据
	for (i = 0; i < num; i++) {
		scanf_s("%d", &input);
		a[i] = input;
	}
	return a;
}

int* Bubble_sort(int a[], int num)
{
	int i, j;
	BOOLEAN flag;
	for (i = 0; i < num; i++) {
		flag = TRUE;
		for (j = num - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				swap(&a[j], &a[j - 1]);
				flag = FALSE;
			}
			if (flag) {
				return a;
			}
		}
	}
	return a;
	
}


//打印（因为折半插入排序数组0号位为哨兵，所以输出的数据从1号位开始）
void Print(int a[], int num) {
	int i;
	for (i = 0; i < num; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}

//交换
void swqp(int* a, int* b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}