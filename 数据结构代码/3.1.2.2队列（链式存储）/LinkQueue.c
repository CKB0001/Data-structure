#include<stdio.h>
#include<Windows.h>

typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

/*声明*/
LinkQueue InitQueue(LinkQueue Q);//初始化
BOOLEAN IsEmpty(LinkQueue Q);//判断是否为空
LinkQueue EnQueue(LinkQueue Q,int x);//入队
LinkQueue DeQueue(LinkQueue Q);//出队（但不获得队首元素）
int GetFront(LinkQueue Q);//获得队首元素

int main() {
	LinkQueue  linkqueue;
	linkqueue.front = (LinkNode*)malloc(sizeof(LinkNode));
	linkqueue.rear = (LinkNode*)malloc(sizeof(LinkNode));
	linkqueue.front = linkqueue.rear;
	linkqueue.front->next = NULL;
	BOOLEAN c = TRUE;
	while (c) {
		printf("--------------------------------\n");
		printf("0------退出\n");
		printf("1------判断此队列是否为空\n");
		printf("2------添加元素\n");
		printf("3------打印出队首元素\n");
		printf("4------将队首元素出队\n");
		printf("5------重置队列中的数据\n");
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
			case 1: {//判断此队列是否为空
				if (IsEmpty(linkqueue)) {
					printf("此队列为空\n");
					system("pause");
					break;
				}
				else {
					printf("此队列不为空\n");
					system("pause");
					break;
				}			
			}
			case 2: {//添加元素
					printf("请输入队列添加的元素\n");
					int j=0;
					scanf_s("%d",&j);
					linkqueue = EnQueue(linkqueue, j);
					printf("添加成功\n");
					system("pause");
					break;
			
			}
			case 3: {//打印出队首元素
				if (IsEmpty(linkqueue)) {
					printf("请先添加元素\n");
					system("pause");
					break;
				}
				else {
					int j = 0;
					j = GetFront(linkqueue);
					printf("队列中的第一个元素是%d\n",j);
					system("pause");
					break;
				}
			}
			case 4: {//将队首元素出队
				if (IsEmpty(linkqueue)) {
					printf("请先添加元素\n");
					system("pause");
					break;
				}
				else {
					linkqueue = DeQueue(linkqueue);
					printf("出队成功\n");
					system("pause");
					break;
				}
			}
			case 5: {//重置队列中的数据
				linkqueue = InitQueue(linkqueue);
					printf("重置成功\n");
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

//初始化
LinkQueue InitQueue(LinkQueue Q)
{
	Q.front = (LinkNode*)malloc(sizeof(LinkNode));
	Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front = Q.rear;
	Q.front->next = NULL;
	return Q;
}

//判断是否为空
BOOLEAN IsEmpty(LinkQueue Q)
{  
	if (Q.front == Q.rear) {
		return TRUE;
	}
	return FALSE;
}

//入队
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

//出队（但不获得队首元素）
/*
	 ___		 ___		 ___	
	|   |------>|   |------>|   |
	 ---         ---         ---  
	  |			  |			  |
	  |			  |			  |
	首节点		  p			尾结点
	为NULL	p=front->next	 rear	
	front	  p将会出队	 rear->next=rear	
*/
LinkQueue DeQueue(LinkQueue Q)
{
	LinkNode* p = Q.front->next;
	Q.front->next = p->next;
	if (Q.rear == p) {
		Q.rear = Q.front;//若原队列中只有一个结点，删除后变空
	}
	//free(p);
	return Q;
}

//获得队首元素
int GetFront(LinkQueue Q)
{
	LinkNode* p = Q.front->next;
	int x = p->data;
	//free(p);
	return x;
}
