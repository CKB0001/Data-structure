/*顺序查找 就是简单的按顺序遍历一遍然后依次比较*/
/*本程序就是将数组按顺序遍历一遍依次查找。*/
#include<stdio.h>
#include<windows.h>
#define Maxsize 5
BOOLEAN search(int a[], int x);//顺序查找

int main() {
	int a[Maxsize],i,x=0;
	printf("请输入%d个数\n",Maxsize);
	for (i = 0; i < Maxsize; i++) {
		scanf_s("%d", &a[i]);
	}
	printf("请输入你要查找的数\n");
	scanf_s("%d",&x);
	if (search(a, x)) {
		printf("存在\n");
	}
	else {
		printf("不存在\n");
	}
	system("pause");
	return 0;
}

//顺序查找
BOOLEAN search(int a[], int key) {
	int i;
	for (i = 0; i < Maxsize; i++) {
		if (a[i] == key) {
			
			return TRUE;
		}
	}
		return FALSE;
}