#include<stdio.h>
#include<Windows.h>
#define Maxsize 100

/*声明*/
int* Input(int num);//输入程序（因为直接插入排序数组0号位为哨兵，所以输入的数据从1号位开始）
int* BinaryInsert_sort(int a[], int num);//折半插入排序
void Print(int a[], int num);//打印


int main() {
	printf("请输入你想要输入多少个数字:");
	int  num;//输入多少个数字
	scanf_s("%d", &num);
	num = num + 1;//0号位为哨兵,所以应该多一位
	int* a;
	a = Input(num);
	/*（开始）将指针转化为数组（因为c语言函数不能将整个数组传过来）*/
	int i, b[Maxsize];
	for (i = 0; i < num; i++) {
		b[i] = *(a + i);
	}
	/*（结束）将指针转化为数组（因为c语言函数不能将整个数组传过来）*/

	//排序并将它转换为数组
	a = BinaryInsert_sort(b, num);
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
	for (i = 1; i < num; i++) {
		scanf_s("%d", &input);
		a[i] = input;
	}
	return a;
}

//折半插入排序
int* BinaryInsert_sort(int a[], int num) {
	int low, high, i;
	for (i = 2; i < num; i++) {
		a[0] = a[i];//不进行判断直接存进哨兵
		low = 1;
		high = i - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (a[mid] < a[0]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		int j;
		for (j = i - 1; j >= high + 1; --j) {
			a[j + 1] = a[j];
		}
		a[high + 1] = a[0];//数据插入的位置在high+1
	}
	return a;
}




//打印（因为折半插入排序数组0号位为哨兵，所以输出的数据从1号位开始）
void Print(int a[], int num) {
	int i;
	for (i = 1; i < num; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}