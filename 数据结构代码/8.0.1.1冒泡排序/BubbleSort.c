#include<stdio.h>
#include<Windows.h>
#define Maxsize 100

/*����*/
int* Input(int num);//���������Ϊ�۰������������0��λΪ�ڱ���������������ݴ�1��λ��ʼ��
int* Bubble_sort(int a[], int num);//����
void Print(int a[], int num);//ð�ݴ�ӡ
void swqp(int* a, int* b);//����

int main() {
	printf("����������Ҫ������ٸ�����:");
	int  num;//������ٸ�����
	scanf_s("%d", &num);
	num = num ;//0��λ�ݴ�����,����Ӧ�ö�һλ
	int* a;
	a = Input(num);
	/*����ʼ����ָ��ת��Ϊ���飨��Ϊc���Ժ������ܽ��������鴫������*/
	int i, b[Maxsize];
	for (i = 0; i < num; i++) {
		b[i] = *(a + i);
	}
	/*����������ָ��ת��Ϊ���飨��Ϊc���Ժ������ܽ��������鴫������*/

	//���򲢽���ת��Ϊ����
	a = Bubble_sort(b, num);


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


//��ӡ����Ϊ�۰������������0��λΪ�ڱ���������������ݴ�1��λ��ʼ��
void Print(int a[], int num) {
	int i;
	for (i = 0; i < num; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}

//����
void swqp(int* a, int* b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}