#include<stdio.h>
#include<Windows.h>
#define Maxsize 100

/*����*/
int* Input(int num);//���������Ϊֱ�Ӳ�����������0��λΪ�ڱ���������������ݴ�1��λ��ʼ��
int* BinaryInsert_sort(int a[], int num);//�۰��������
void Print(int a[], int num);//��ӡ


int main() {
	printf("����������Ҫ������ٸ�����:");
	int  num;//������ٸ�����
	scanf_s("%d", &num);
	num = num + 1;//0��λΪ�ڱ�,����Ӧ�ö�һλ
	int* a;
	a = Input(num);
	/*����ʼ����ָ��ת��Ϊ���飨��Ϊc���Ժ������ܽ��������鴫������*/
	int i, b[Maxsize];
	for (i = 0; i < num; i++) {
		b[i] = *(a + i);
	}
	/*����������ָ��ת��Ϊ���飨��Ϊc���Ժ������ܽ��������鴫������*/

	//���򲢽���ת��Ϊ����
	a = BinaryInsert_sort(b, num);
	for (i = 0; i < num; i++) {
		b[i] = *(a + i);
	}

	printf("������Ϊ\n");
	Print(b, num);//�������ӡ����
	system("pause");
	return 0;
}

//���������Ϊ�۰������������0��λΪ�ڱ���������������ݴ�1��λ��ʼ��
int* Input(int num) {
	int a[Maxsize] = { 0 };
	int i;
	printf("����������\n");
	int input;//���������
	for (i = 1; i < num; i++) {
		scanf_s("%d", &input);
		a[i] = input;
	}
	return a;
}

//�۰��������
int* BinaryInsert_sort(int a[], int num) {
	int low, high, i;
	for (i = 2; i < num; i++) {
		a[0] = a[i];//�������ж�ֱ�Ӵ���ڱ�
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
		a[high + 1] = a[0];//���ݲ����λ����high+1
	}
	return a;
}




//��ӡ����Ϊ�۰������������0��λΪ�ڱ���������������ݴ�1��λ��ʼ��
void Print(int a[], int num) {
	int i;
	for (i = 1; i < num; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}