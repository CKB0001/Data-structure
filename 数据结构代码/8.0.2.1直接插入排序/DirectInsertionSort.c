#include<stdio.h>
#include<Windows.h>
#define Maxsize 100

/*����*/
int* Input(int num);//���������Ϊֱ�Ӳ�����������0��λΪ�ڱ���������������ݴ�1��λ��ʼ��
int* DirectInsertion_sort(int a[], int num);//ֱ�Ӳ���������ʵ������ָ�룬����Ҳ����Ҫ����ֵ�����������Ƚϲ��ÿ������Խ�������׵�ַ���أ�
void Print(int a[], int num);//��ӡ

int main() {
	printf("����������Ҫ������ٸ�����:");
	int  num;//������ٸ�����
	scanf_s("%d",&num);
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
	a = DirectInsertion_sort(b, num);
	for (i = 0; i < num; i++) {
		b[i] = *(a + i);
	}

	printf("������Ϊ\n");
	Print(b, num);//�������ӡ����
	system("pause");
	return 0;
}


//���������Ϊֱ�Ӳ�����������0��λΪ�ڱ���������������ݴ�1��λ��ʼ��
int* Input(int num) {
	int a[Maxsize] = { 0 };
	int i;	
	printf("����������\n");
	int input;//���������
	for (i = 1; i < num;i++) {
		scanf_s("%d",&input);
		a[i] = input;
	}
	return a;
}
//ֱ�Ӳ���������ʵ������ָ�룬����Ҳ����Ҫ����ֵ�����������Ƚϲ��ÿ������Խ�������׵�ַ���أ�
int* DirectInsertion_sort(int a[], int num) {
	int i,j;
	for (i = 2; i < num; i++) {
		if (a[i] < a[i - 1]) {
			a[0] = a[i];//��ֵ�����ڱ�
			for (j = i - 1; a[0] < a[j]; j--) {
				a[j + 1] = a[j];
			}
			a[j + 1] = a[0];
		}
	}
	return a;
}


//��ӡ����Ϊֱ�Ӳ�����������0��λΪ�ڱ���������������ݴ�1��λ��ʼ��
void Print(int a[] ,int num) {
	int i;
	for (i = 1; i < num; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}