#include<stdio.h>
#include<Windows.h>

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//ͷ�巨
LinkList List_HeadInsert(LinkList L) {
	LNode* s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf_s("%d", &x);
	}
	return L;
}

//β�巨
LinkList List_TailInsert(LinkList L) {
	L = (LinkList)malloc(sizeof(LNode));

	LNode* s, * r = L;
	int x;
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf_s("%d", &x);
	}
	r->next = NULL;//Ϊ�������ӵ���䣨��ɾ����
	return L;
}

//���
void Print_list(LinkList L) {
	if (L != NULL)
	{
		printf("������������\n");
		LNode* s;
		s = (LNode*)malloc(sizeof(LNode));
		s = L->next;
		while (s != NULL) {
			printf("%d\n", s->data);
			s = s->next;
		}
		printf("���Ͼ��ǵ������е�ֵ\n");
	}
	else
	{
		printf("�����������в���ֵ!!!!\n");
	}
}

//����Ų������е�����(0Ϊͷ��㣩
LNode* GetNum(LinkList L, int i) {
	LNode* p;
	p = L->next;
	int s = 1;//��¼�������е�λ��
	if (i == 0) {
		return L;
	}
	if (i < 0) {
		return NULL;
	}
	while (p != NULL && s < i) {
		p = p->next;
		s++;
	}
	return p;
}

//��ֵ����(��û�и�ֵ�򷵻�NULL��
LNode* FindNum(LinkList L, int i) {
	LNode* s = L->next;
	while (s != NULL && i != s->data)
		s = s->next;
	return s;
}

//����λ���������в�����
LinkList LNode_Insert(LinkList L, int i, LNode* s) {
	LNode* p;
	p = GetNum(L, i - 1);
	if (p != NULL) {
		s->next = p->next;
		p->next = s;
		return L;
	}
	else
	{
		return NULL;//λ�ò�����
	}
}

//����λ��ɾ�����
LinkList LNode_Del(LinkList L, int i) {
	LNode* p, * q;
	p = GetNum(L, i - 1);
	if (p != NULL) {
		q = p->next;
		p->next = q->next;
		free(q);
		return L;
	}
	else
	{
		return  NULL;//λ�ò�����
	}

}


int main() {
	LinkList list;
	list = (LinkList)malloc(sizeof(LNode));
	list = NULL;
	BOOLEAN c = TRUE;//�жϳ����Ƿ�ִ����ȥ
	while (c)
	{
		int choice;//�ж�ִ���ĸ�����
		printf("----------------------------------------------\n");
		printf("0--�˳�\n");
		printf("1--ʹ��ͷ�巨����������\n");
		printf("2--ʹ��β�巨����������\n");
		printf("3--���������е����ִ�ӡ����\n");
		printf("4--����λ��ɾ���������еĽ��\n");
		printf("5--����λ�ò��ҵ������е�ֵ\n");
		printf("6--�жϸ�ֵ�Ƿ�����ڸõ�������\n");
		printf("7--�������в�����\n");
		printf("----------------------------------------------\n");
		printf("������˵��е�ѡ��\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 0://�˳�
		{
			c = FALSE;
			break;
		}
		case 1: //ʹ��ͷ�巨����������
		{
			printf("����9999��ֹͣ����õ�����\n");
			LinkList listhead = NULL;
			list = List_HeadInsert(listhead);
			break;
		}
		case 2://ʹ��β�巨����������
		{
			printf("����9999��ֹͣ����õ�����\n");
			LinkList listTail = NULL;
			list = List_TailInsert(listTail);
			break;
		}
		case 3://���������е����ִ�ӡ����
		{
			Print_list(list);
			break;
		}
		case 4://����λ��ɾ���������еĽ��
		{
			printf("����λ��ɾ���������еĽ��\n");
			printf("����ɾ���������н���λ��\n");
			int i;//ɾ���������н���λ��
			scanf_s("%d", &i);
			LinkList listdel;
			listdel = LNode_Del(list, i);
			if (listdel == NULL)
			{
				printf("�����λ������\n");
			}
			else
			{
				list = listdel;
			}
			break;
		}
		case 5://����λ�ò��ҵ������е�ֵ
		{
			printf("����λ�ò��ҵ������еĽ��\n");
			printf("������ҵ������н���λ��\n");
			int i;//���ҵ������н���λ��
			scanf_s("%d", &i);
			LNode* p;//����λ�ò��ҵ��Ľ��
			p = GetNum(list, i);
			if (p == NULL)
			{
				printf("�����λ������\n");
			}
			else
			{
				printf("��%dλ�õ�����Ϊ��%d\n", i, p->data);

			}
			break;
		}
		case 6://�жϸ�ֵ�Ƿ�����ڸõ�������
		{
			int i;//���ҵ�����
			LNode* p;//�������ݲ��ҵ��Ľ��
			printf("�����ж��Ƿ��ڵ������е�����\n");
			scanf_s("%d", &i);
			p = FindNum(list, i);
			if (p == NULL)
			{
				printf("�������ڴ˵������в�����\n");
			}
			else
			{
				printf("�������ڵ������д���\n");
			}
			break;
		}
		case 7://�������в�����
		{
			int i;//�����λ��
			LNode* p;//����Ľ��
			LinkList s;
			p = (LNode*)malloc(sizeof(LNode));
			printf("����������λ��\n");
			scanf_s("%d", &i);
			printf("���������Ľ�������\n");
			scanf_s("%d", &p->data);
			s = LNode_Insert(list, i, p);
			if (s != NULL)
			{
				printf("����ɹ�\n");
			}
			else
			{
				printf("����ʧ�ܣ�����λ�ô��󣡣���\n");
			}
			break;
		}
		default:
		{
			printf("��������ȷ��ѡ�����\n");
		}
		}
	}
	system("pause");
	return 0;
}