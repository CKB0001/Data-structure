#include<stdio.h>
#include<Windows.h>
#define Maxsize 100
typedef struct {
	int data[Maxsize];
	int top;
}SqStack;
/*����*/
SqStack InitStack(SqStack S);//��ʼ��
BOOLEAN StackEmpty(SqStack S);//�ж�ջ�Ƿ�Ϊ�գ�ջ�շ���true��
BOOLEAN StackNull(SqStack S);//�ж��Ƿ�ջ����ջ������true��
SqStack Push(SqStack S, int x);//��ջ
SqStack Pop(SqStack S);//��ջ
int GetTop(SqStack S);//��ջ��Ԫ��



int main() {
	SqStack stack;
	stack.top = -1;
	BOOLEAN c = TRUE;
	while (c) {
		printf("--------------------------------\n");
		printf("0------�˳�\n");
		printf("1------�жϴ�ջ�Ƿ�����\n");
		printf("2------�жϴ�ջ�Ƿ�Ϊ��\n");
		printf("3------���ջ��Ԫ��\n");
		printf("4------��ӡ��ջ��Ԫ��\n");
		printf("5------��ջ��Ԫ�س�ջ\n");
		printf("6------����ջ�е�����\n");
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
			case 1: {//�жϴ�ջ�Ƿ�����
				if (StackNull(stack)) {
					printf("��ջ����\n");
					system("pause");
				}
				else {
					printf("��ջ��û����\n");
					system("pause");
				}
				break;
			}
			case 2: {//�жϴ�ջ�Ƿ�Ϊ��
				if (StackEmpty(stack)) {
					printf("��ջΪ��\n");
					system("pause");
				}
				else {
					printf("��ջ��Ϊ��\n");
					system("pause");
				}
				break;

			}
			case 3: {//���ջ��Ԫ��
				if (StackNull(stack)) {
					printf("��ջ�����������Ԫ�أ�����\n");
					system("pause");
					break;
				}
				int w;//��Ҫ�����ջ��Ԫ�ص�ֵ
				printf("����������Ҫ���ջ��Ԫ�ص����ݣ�\n");
				scanf_s("%d",&w);
				stack = Push(stack, w);
				printf("���Ԫ�سɹ�\n");
				system("pause");
				break;
			}
			case 4: {//��ӡ��ջ��Ԫ��
				if (StackEmpty(stack)) {
					printf("��ջΪ�գ�����\n");
					system("pause");
					break;
				}
				printf("ջ��Ԫ�ص�ֵΪ��%d\n",GetTop(stack));
				system("pause");
				break;
			}
			case 5: {//��ջ��Ԫ�س�ջ
				if (StackEmpty(stack)) {
					printf("��ջΪ�գ�����\n");
					system("pause");
					break;
				}
				stack = Pop(stack);
				printf("Ԫ�س�ջ�ɹ�\n");
				system("pause");
				break;
			}
			case 6: {//����ջ�е�����
				stack = InitStack(stack);
				printf("ջ�ѱ����\n");
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
SqStack InitStack(SqStack S) {
	S.top = -1;
	return S;
}

//�ж�ջ�Ƿ�Ϊ��
BOOLEAN StackEmpty(SqStack S) {
	if (S.top == -1) {
		return TRUE;//ջΪ��
	}
	else
		return FALSE;//ջ��Ϊ��
}

//�ж��Ƿ�ջ����ջ������true��
BOOLEAN StackNull(SqStack S) {
	if (S.top == Maxsize - 1) {
		return TRUE;//ջ��
	}
	return FALSE;
}

//��ջ
SqStack Push(SqStack S, int x) {
	S.data[++S.top] = x;
	return S;
}

//��ջ
SqStack Pop(SqStack S) {
	S.data[S.top--];
	return S;

}

//��ջ��Ԫ��
int GetTop(SqStack S) {
	int x;
	x = S.data[S.top];
	return x;
}
