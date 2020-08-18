/*本程序使用循环队列的方式存储*/
//初始化: Q.front = Q.rear = 0
//队首指针进1: Q.front = (Q.front + 1) % Maxsize 
//队尾指针进1: Q.rear = (Q.rear + 1) % Maxsize 
//队列长度: (Q.rear - Q.front + Maxsize) % Maxsize
//队满条件: (Q.rear + 1) % Maxsize == Q.front
//队空条件: Q.front == Q.rear
//队列中元素个数: (Q.rear - Q.front + Maxsize) % Maxsize
#include<stdio.h>
#include<Windows.h>

#define Maxsize 100

typedef struct {
	int data[Maxsize];
	int front, rear;//队头和队尾指针
}SqQueue;

/*声明*/
BOOLEAN isEmpty(SqQueue Q);//判断队列是否为空
BOOLEAN isFull(SqQueue Q);//判断队列是否为满
SqQueue EnQueue(SqQueue Q, int x);//入队
SqQueue DeQueue(SqQueue Q);//出队
SqQueue InitQueue(SqQueue Q);//初始化00
int GetFront(SqQueue Q);//获取队首元素但不出队

int main() {
	SqQueue queue;
	queue.front = 0;
	queue.rear = 0;
	BOOLEAN c = TRUE;
	while (c) {
		printf("--------------------------------\n");
		printf("0------退出\n");
		printf("1------判断此队列是否已满\n");
		printf("2------判断此队列是否为空\n");
		printf("3------添加元素\n");
		printf("4------打印出队首元素\n");
		printf("5------将队首元素出队\n");
		printf("6------重置队列中的数据\n");
		printf("--------------------------------\n");
		printf("请输入选项:\n");
		int x;
		scanf_s("%d", &x);
		rewind(stdin);//清除缓冲区中的字符，不然它会残留scanf_s输入的\n,fflush(stdin)不建议使用，没有效果
		switch (x) {
		case 0: {//退出
			c = FALSE;
			break;
		}
		case 1: {//判断此队列是否已满
			if (isFull(queue)) {
				printf("此队列已满\n");
				system("pause");
			}
			else {
				printf("此队列还没存满\n");
				system("pause");
			}
			break;
		}
		case 2: {//判断此队列是否为空
			if (isEmpty(queue)) {
				printf("此队列为空\n");
				system("pause");
			}
			else {
				printf("此队列不为空\n");
				system("pause");
			}
			break;

		}
		case 3: {//添加元素
			if (isFull(queue)) {
				printf("此队列已满不能添加元素！！！\n");
				system("pause");
				break;
			}
			int w;//所要输入的元素的值
			printf("请输入你所要添加的数据：\n");
			scanf_s("%d", &w);
			queue = EnQueue(queue, w);
			printf("添加元素成功\n");
			system("pause");
			break;
		}
		case 4: {//打印出队首元素
			if (isEmpty(queue)) {
				printf("此队列为空！！！\n");
				system("pause");
				break;
			}
			printf("队首元素的值为：%d\n",GetFront(queue) );
			system("pause");
			break;
		}
		case 5: {//将队首元素出队
			if (isEmpty(queue)) {
				printf("此队列为空！！！\n");
				system("pause");
				break;
			}
			queue = DeQueue(queue);
			printf("元素出队成功\n");
			system("pause");
			break;
		}
		case 6: {//重置队列中的数据
			queue = InitQueue(queue);
			printf("队列已被清空\n");
			system("pause");
			break;
		}
		default: {
			printf("请输入正确的功能键\n");
			system("pause");
		}
		}

	}
	system("pause");
	return 0;
}

//判断队列是否为空
BOOLEAN isEmpty(SqQueue Q) {
	if (Q.front == Q.rear) {
		return TRUE;
	}
	return FALSE;
}

//判断队列是否为满
BOOLEAN isFull(SqQueue Q) {
	if ((Q.rear + 1) % Maxsize == Q.front) {
		return TRUE;
	}
	return FALSE;
}

//入队
SqQueue EnQueue(SqQueue Q, int x) {
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % Maxsize;
	return Q;
}

//出队(但不会得到值)
SqQueue DeQueue(SqQueue Q) {
	Q.front = (Q.front + 1) % Maxsize;
	return Q;
}

//初始化
SqQueue InitQueue(SqQueue Q) {
	Q.front = 0;
	Q.rear = 0;
	return Q;
}

//获取队首元素但不出队
int GetFront(SqQueue Q) {
	int x;
	x = Q.data[Q.front];
	return x;
}
