/*˳����� ���Ǽ򵥵İ�˳�����һ��Ȼ�����αȽ�*/
/*��������ǽ����鰴˳�����һ�����β��ҡ�*/
#include<stdio.h>
#include<windows.h>
#define Maxsize 5
BOOLEAN search(int a[], int x);//˳�����

int main() {
	int a[Maxsize],i,x=0;
	printf("������%d����\n",Maxsize);
	for (i = 0; i < Maxsize; i++) {
		scanf_s("%d", &a[i]);
	}
	printf("��������Ҫ���ҵ���\n");
	scanf_s("%d",&x);
	if (search(a, x)) {
		printf("����\n");
	}
	else {
		printf("������\n");
	}
	system("pause");
	return 0;
}

//˳�����
BOOLEAN search(int a[], int key) {
	int i;
	for (i = 0; i < Maxsize; i++) {
		if (a[i] == key) {
			
			return TRUE;
		}
	}
		return FALSE;
}