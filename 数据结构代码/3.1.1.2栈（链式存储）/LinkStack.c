/*ջ����ʽ�洢�Ĳ������������ƣ���ջ�ͳ�ջ�Ĳ�����������ı�ͷ���У�ͷ�巨��*/
/*ע;��ȡջ��Ԫ��û��Ҫд����������д�˾Ͳ���ɾ�����Ծ��õ���*/
#include<stdio.h>
#include<Windows.h>

typedef struct Linknode{
	int data;
	struct Linknode *next;
}Linknode,*LiStack;
/*����*/
LiStack InitStack(LiStack S);//��ʼ��
BOOLEAN StackEmpty(LiStack S);//�ж�ջ�Ƿ�Ϊ�գ�ջ�շ���true��
LiStack Push(LiStack S, int x);//��ջ
LiStack Pop(LiStack S);//��ջ
int GetTop(LiStack S);//��ջ��Ԫ��



int main() {

	LiStack listack;
	listack = (LiStack)malloc(sizeof(Linknode));
	listack->next = NULL;
	BOOLEAN c = TRUE;
	while (c) {
		printf("--------------------------------\n");
		printf("0------�˳�\n");
		printf("1------�жϴ�ջ�Ƿ�Ϊ��\n");
		printf("2------���ջ��Ԫ��\n");
		printf("3------��ӡ��ջ��Ԫ��\n");
		printf("4------��ջ��Ԫ�س�ջ\n");
		printf("5------����ջ�е�����\n");
		printf("--------------------------------\n");
		printf("������ѡ��:\n");
		int x;
		scanf_s("%d", &x);
		rewind(stdin);//����������е��ַ�����Ȼ�������scanf_s�����\n,fflush(stdin)������ʹ�ã�û��Ч��
		switch (x) {
			case 0: {//�˳�
				c = FALSE;
				free(listack);
				break;
			}
			case 1: {//�жϴ�ջ�Ƿ�Ϊ��
				if (StackEmpty(listack)) {
					printf("��ջΪ��\n");
					system("pause");
					break;
				}
				else {
					printf("��ջ��Ϊ��\n");
					system("pause");
					break;
				}
			}
			case 2: {//���ջ��Ԫ��
				int w;//��Ҫ�����ջ��Ԫ�ص�ֵ
				printf("����������Ҫ���ջ��Ԫ�ص����ݣ�\n");
				scanf_s("%d", &w);
				listack = Push(listack, w);
				printf("���Ԫ�سɹ�\n");
				system("pause");
				break;
			}
			case 3: {//��ӡ��ջ��Ԫ��
				if (StackEmpty(listack)) {
					printf("��ջΪ��,���������ݣ�����\n");
					system("pause");
					break;
				}
				printf("%d\n", GetTop(listack));
				system("pause");
				break;
			}
			case 4: {//��ջ��Ԫ�س�ջ
				if (StackEmpty(listack)) {
					printf("��ջΪ��,���������ݣ�����\n");
					system("pause");
					break;
				}
				listack = Pop(listack);
				printf("��ջ�ɹ�\n");
				system("pause");
				break;
			}
			case 5: {//����ջ�е�����
				listack = InitStack(listack);
				printf("��ջ�����ã�����\n");
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
LiStack InitStack(LiStack S)
{
	free(S);
	S = (LiStack*)malloc(sizeof(Linknode));
	S->next = NULL;
	return S;
}

//�ж�ջ�Ƿ�Ϊ�գ�ջ�շ���true��
BOOLEAN StackEmpty(LiStack S)
{
	if (S->next == NULL) {
		return TRUE;
	}
	return FALSE;
}

//��ջ
LiStack Push(LiStack L, int x)
{
	Linknode* s;
	s = (Linknode*)malloc(sizeof(Linknode));
	s->data = x;
	s->next = L->next;
	L->next = s;
	return L;
}

//��ջ
LiStack Pop(LiStack S)
{

	S = S->next;
	return S;
}

//��ջ��Ԫ��
int GetTop(LiStack S)
{
	int x;
	x = S->next->data;
	return x;
}

