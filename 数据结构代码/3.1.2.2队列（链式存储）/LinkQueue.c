#include<stdio.h>
#include<Windows.h>

typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

/*����*/
LinkQueue InitQueue(LinkQueue Q);//��ʼ��
BOOLEAN IsEmpty(LinkQueue Q);//�ж��Ƿ�Ϊ��
LinkQueue EnQueue(LinkQueue Q,int x);//���
LinkQueue DeQueue(LinkQueue Q);//���ӣ�������ö���Ԫ�أ�
int GetFront(LinkQueue Q);//��ö���Ԫ��

int main() {
	LinkQueue  linkqueue;
	linkqueue.front = (LinkNode*)malloc(sizeof(LinkNode));
	linkqueue.rear = (LinkNode*)malloc(sizeof(LinkNode));
	linkqueue.front = linkqueue.rear;
	linkqueue.front->next = NULL;
	BOOLEAN c = TRUE;
	while (c) {
		printf("--------------------------------\n");
		printf("0------�˳�\n");
		printf("1------�жϴ˶����Ƿ�Ϊ��\n");
		printf("2------���Ԫ��\n");
		printf("3------��ӡ������Ԫ��\n");
		printf("4------������Ԫ�س���\n");
		printf("5------���ö����е�����\n");
		printf("--------------------------------\n");
		printf("������ѡ��:\n");
		int x;
		scanf_s("%d", &x);
		rewind(stdin);//����������е��ַ�����Ȼ�������scanf_s�����\n,fflush(stdin)������ʹ�ã�û��Ч��
		switch (x) {
			case 0: {//�˳�
				c = FALSE;
				break;
			}
			case 1: {//�жϴ˶����Ƿ�Ϊ��
				if (IsEmpty(linkqueue)) {
					printf("�˶���Ϊ��\n");
					system("pause");
					break;
				}
				else {
					printf("�˶��в�Ϊ��\n");
					system("pause");
					break;
				}			
			}
			case 2: {//���Ԫ��
					printf("�����������ӵ�Ԫ��\n");
					int j=0;
					scanf_s("%d",&j);
					linkqueue = EnQueue(linkqueue, j);
					printf("��ӳɹ�\n");
					system("pause");
					break;
			
			}
			case 3: {//��ӡ������Ԫ��
				if (IsEmpty(linkqueue)) {
					printf("�������Ԫ��\n");
					system("pause");
					break;
				}
				else {
					int j = 0;
					j = GetFront(linkqueue);
					printf("�����еĵ�һ��Ԫ����%d\n",j);
					system("pause");
					break;
				}
			}
			case 4: {//������Ԫ�س���
				if (IsEmpty(linkqueue)) {
					printf("�������Ԫ��\n");
					system("pause");
					break;
				}
				else {
					linkqueue = DeQueue(linkqueue);
					printf("���ӳɹ�\n");
					system("pause");
					break;
				}
			}
			case 5: {//���ö����е�����
				linkqueue = InitQueue(linkqueue);
					printf("���óɹ�\n");
					system("pause");
					break;			
			}
			default: {
				printf("��������ȷ�Ĺ��ܼ�\n");
				system("pause");
			}
		}
	}
	system("pause");
	return 0;
}

//��ʼ��
LinkQueue InitQueue(LinkQueue Q)
{
	Q.front = (LinkNode*)malloc(sizeof(LinkNode));
	Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front = Q.rear;
	Q.front->next = NULL;
	return Q;
}

//�ж��Ƿ�Ϊ��
BOOLEAN IsEmpty(LinkQueue Q)
{  
	if (Q.front == Q.rear) {
		return TRUE;
	}
	return FALSE;
}

//���
LinkQueue EnQueue(LinkQueue Q, int x)
{
	LinkNode* s;
	s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
	return Q;
}

//���ӣ�������ö���Ԫ�أ�
/*
	 ___		 ___		 ___	
	|   |------>|   |------>|   |
	 ---         ---         ---  
	  |			  |			  |
	  |			  |			  |
	�׽ڵ�		  p			β���
	ΪNULL	p=front->next	 rear	
	front	  p�������	 rear->next=rear	
*/
LinkQueue DeQueue(LinkQueue Q)
{
	LinkNode* p = Q.front->next;
	Q.front->next = p->next;
	if (Q.rear == p) {
		Q.rear = Q.front;//��ԭ������ֻ��һ����㣬ɾ������
	}
	//free(p);
	return Q;
}

//��ö���Ԫ��
int GetFront(LinkQueue Q)
{
	LinkNode* p = Q.front->next;
	int x = p->data;
	//free(p);
	return x;
}
