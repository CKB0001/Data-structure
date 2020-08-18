/*������ʹ��ѭ�����еķ�ʽ�洢*/
//��ʼ��: Q.front = Q.rear = 0
//����ָ���1: Q.front = (Q.front + 1) % Maxsize 
//��βָ���1: Q.rear = (Q.rear + 1) % Maxsize 
//���г���: (Q.rear - Q.front + Maxsize) % Maxsize
//��������: (Q.rear + 1) % Maxsize == Q.front
//�ӿ�����: Q.front == Q.rear
//������Ԫ�ظ���: (Q.rear - Q.front + Maxsize) % Maxsize
#include<stdio.h>
#include<Windows.h>

#define Maxsize 100

typedef struct {
	int data[Maxsize];
	int front, rear;//��ͷ�Ͷ�βָ��
}SqQueue;

/*����*/
BOOLEAN isEmpty(SqQueue Q);//�ж϶����Ƿ�Ϊ��
BOOLEAN isFull(SqQueue Q);//�ж϶����Ƿ�Ϊ��
SqQueue EnQueue(SqQueue Q, int x);//���
SqQueue DeQueue(SqQueue Q);//����
SqQueue InitQueue(SqQueue Q);//��ʼ��00
int GetFront(SqQueue Q);//��ȡ����Ԫ�ص�������

int main() {
	SqQueue queue;
	queue.front = 0;
	queue.rear = 0;
	BOOLEAN c = TRUE;
	while (c) {
		printf("--------------------------------\n");
		printf("0------�˳�\n");
		printf("1------�жϴ˶����Ƿ�����\n");
		printf("2------�жϴ˶����Ƿ�Ϊ��\n");
		printf("3------���Ԫ��\n");
		printf("4------��ӡ������Ԫ��\n");
		printf("5------������Ԫ�س���\n");
		printf("6------���ö����е�����\n");
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
		case 1: {//�жϴ˶����Ƿ�����
			if (isFull(queue)) {
				printf("�˶�������\n");
				system("pause");
			}
			else {
				printf("�˶��л�û����\n");
				system("pause");
			}
			break;
		}
		case 2: {//�жϴ˶����Ƿ�Ϊ��
			if (isEmpty(queue)) {
				printf("�˶���Ϊ��\n");
				system("pause");
			}
			else {
				printf("�˶��в�Ϊ��\n");
				system("pause");
			}
			break;

		}
		case 3: {//���Ԫ��
			if (isFull(queue)) {
				printf("�˶��������������Ԫ�أ�����\n");
				system("pause");
				break;
			}
			int w;//��Ҫ�����Ԫ�ص�ֵ
			printf("����������Ҫ��ӵ����ݣ�\n");
			scanf_s("%d", &w);
			queue = EnQueue(queue, w);
			printf("���Ԫ�سɹ�\n");
			system("pause");
			break;
		}
		case 4: {//��ӡ������Ԫ��
			if (isEmpty(queue)) {
				printf("�˶���Ϊ�գ�����\n");
				system("pause");
				break;
			}
			printf("����Ԫ�ص�ֵΪ��%d\n",GetFront(queue) );
			system("pause");
			break;
		}
		case 5: {//������Ԫ�س���
			if (isEmpty(queue)) {
				printf("�˶���Ϊ�գ�����\n");
				system("pause");
				break;
			}
			queue = DeQueue(queue);
			printf("Ԫ�س��ӳɹ�\n");
			system("pause");
			break;
		}
		case 6: {//���ö����е�����
			queue = InitQueue(queue);
			printf("�����ѱ����\n");
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

//�ж϶����Ƿ�Ϊ��
BOOLEAN isEmpty(SqQueue Q) {
	if (Q.front == Q.rear) {
		return TRUE;
	}
	return FALSE;
}

//�ж϶����Ƿ�Ϊ��
BOOLEAN isFull(SqQueue Q) {
	if ((Q.rear + 1) % Maxsize == Q.front) {
		return TRUE;
	}
	return FALSE;
}

//���
SqQueue EnQueue(SqQueue Q, int x) {
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % Maxsize;
	return Q;
}

//����(������õ�ֵ)
SqQueue DeQueue(SqQueue Q) {
	Q.front = (Q.front + 1) % Maxsize;
	return Q;
}

//��ʼ��
SqQueue InitQueue(SqQueue Q) {
	Q.front = 0;
	Q.rear = 0;
	return Q;
}

//��ȡ����Ԫ�ص�������
int GetFront(SqQueue Q) {
	int x;
	x = Q.data[Q.front];
	return x;
}
