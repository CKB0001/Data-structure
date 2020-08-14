
#include<stdio.h>
#include<Windows.h>
#define Maxsize 5

int BSearch(int a[], int x);//折半查找(按从小到大)

int main() {
	int a[Maxsize], i, x = 0, B;
	printf("请输入%d个数(按从小到大)\n",Maxsize);
	for (i = 0; i < Maxsize; i++) {
		scanf_s("%d", &a[i]);
	}
	printf("请输入你要查找的数\n");
	scanf_s("%d", &x);
	B = BSearch(a,x);
	if (B!= -1) {
		printf("存在，且是第%d个数\n", (B + 1));
	}
	else {
		printf("不存在\n");
	}
	system("pause");
	return 0;
}

//折半查找
int BSearch(int a[],int key) {
	int mid = 0, high = Maxsize - 1 , low = 0;
	while (low <= high) {
		mid = (high + low) / 2;
		if (a[mid] == key) {
			return mid;
		}
		else
		{
			if (a[mid] > key) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
	}
	return -1;

}