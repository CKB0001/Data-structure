#include<stdio.h>
#include<Windows.h>
#define Maxsize 100

/*����*/
int* Input(int num);//���������Ϊϣ����������0��λ�ݴ����ݣ�������������ݴ�1��λ��ʼ��
int* Shell_sort(int a[], int num);//ϣ������
void Print(int a[], int num);//��ӡ


int main() {
	printf("����������Ҫ������ٸ�����:");
	int  num;//������ٸ�����
	scanf_s("%d", &num);
	num = num + 1;//0��λ�ݴ�����,����Ӧ�ö�һλ
	int* a;
	a = Input(num);
	/*����ʼ����ָ��ת��Ϊ���飨��Ϊc���Ժ������ܽ��������鴫������*/
	int i, b[Maxsize];
	for (i = 0; i < num; i++) {
		b[i] = *(a + i);
	}
	/*����������ָ��ת��Ϊ���飨��Ϊc���Ժ������ܽ��������鴫������*/

	//���򲢽���ת��Ϊ����
	a = Shell_sort(b, num);


	for (i = 0; i < num; i++) {
		b[i] = *(a + i);
	}

	printf("������Ϊ\n");
	Print(b, num);//�������ӡ����


	system("pause");
	return 0;
}

//���������Ϊϣ����������0��λ�ݴ����ݣ�������������ݴ�1��λ��ʼ��
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

int* Shell_sort(int a[], int num)//ϣ������
{
	int i,j,dk;//dkΪ����
	for (dk = num / 2; dk >= 1; dk = dk / 2) {
		for (i = dk + 1; i <= num; ++i) {
			if (a[i] < a[i - dk]) {
				a[0] = a[i];
				for (j = i - dk; j > 0 && a[0] > a[j]; j = j - dk) {
					a[j + dk] = a[j];
				}
				a[j + dk] = a[0];
			}
		}
	}
	return a;
}



//��ӡ����Ϊϣ����������0��λ�ݴ����ݣ�������������ݴ�1��λ��ʼ��
void Print(int a[], int num) {
	int i;
	for (i = 1; i < num; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}