
#include<stdio.h>
#include<Windows.h>
#define Maxsize 5

int BSearch(int a[], int x);//�۰����(����С����)

int main() {
	int a[Maxsize], i, x = 0, B;
	printf("������%d����(����С����)\n",Maxsize);
	for (i = 0; i < Maxsize; i++) {
		scanf_s("%d", &a[i]);
	}
	printf("��������Ҫ���ҵ���\n");
	scanf_s("%d", &x);
	B = BSearch(a,x);
	if (B!= -1) {
		printf("���ڣ����ǵ�%d����\n", (B + 1));
	}
	else {
		printf("������\n");
	}
	system("pause");
	return 0;
}

//�۰����
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