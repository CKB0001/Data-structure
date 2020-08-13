#include<stdio.h>
#include<Windows.h>
#define Maxsize 10
typedef struct {
	int data[Maxsize];
	int length;
}Sqlist;



//���Ա�Ĳ������
Sqlist ListInsert(Sqlist L, int i, int e) {
	if (i<1 || i>L.length + 1) {
		printf("%d,%d", i, L.length);
		printf("����λ�ó����λ��\n");
		return L;
	}
	if (L.length >= Maxsize) {
		printf("��̬���Ա�Ĵ洢�ռ����������ܲ���\n");
		return L;
	}
	int j;
	for (j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return L;
}

//ɾ������
Sqlist ListDelete(Sqlist L, int i, int e) {
	if (i<1 || i>L.length + 1) {
		printf("û�и�ɾ��λ��\n");
		return L;
	}
	e = L.data[i - 1];
	int j;
	for (j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return L;
}



int main()
{
	Sqlist list;
	int j;
	for (j = 0; j < Maxsize; j++)
	{
		list.data[j] = 0;
	}
	list.length = 0;
	for (j = 0; j < Maxsize; j++)
		list = ListInsert(list, j + 1, j);

	int i;
	for (i = 0; i < list.length; i++)
	{
		printf("%d  ", list.data[i]);
	}
	printf("\n");
	list = ListDelete(list, 2, 3);
	for (i = 0; i < list.length; i++)
	{
		printf("%d  ", list.data[i]);
	}

	system("pause");

}