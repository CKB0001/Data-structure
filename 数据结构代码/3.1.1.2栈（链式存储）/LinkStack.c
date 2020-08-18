/*栈的链式存储的操作与链表类似，入栈和出栈的操作都在链表的表头进行（头插法）*/
/*注;获取栈顶元素没必要写个函数，但写了就不想删了所以就用到了*/
#include<stdio.h>
#include<Windows.h>

typedef struct Linknode{
	int data;
	struct Linknode *next;
}Linknode,*LiStack;
/*声明*/
LiStack InitStack(LiStack S);//初始化
BOOLEAN StackEmpty(LiStack S);//判断栈是否为空（栈空返回true）
LiStack Push(LiStack S, int x);//进栈
LiStack Pop(LiStack S);//出栈
int GetTop(LiStack S);//读栈顶元素



int main() {

	LiStack listack;
	listack = (LiStack)malloc(sizeof(Linknode));
	listack->next = NULL;
	BOOLEAN c = TRUE;
	while (c) {
		printf("--------------------------------\n");
		printf("0------退出\n");
		printf("1------判断此栈是否为空\n");
		printf("2------添加栈顶元素\n");
		printf("3------打印出栈顶元素\n");
		printf("4------将栈顶元素出栈\n");
		printf("5------重置栈中的数据\n");
		printf("--------------------------------\n");
		printf("请输入选项:\n");
		int x;
		scanf_s("%d", &x);
		rewind(stdin);//清除缓冲区中的字符，不然它会残留scanf_s输入的\n,fflush(stdin)不建议使用，没有效果
		switch (x) {
			case 0: {//退出
				c = FALSE;
				free(listack);
				break;
			}
			case 1: {//判断此栈是否为空
				if (StackEmpty(listack)) {
					printf("此栈为空\n");
					system("pause");
					break;
				}
				else {
					printf("此栈不为空\n");
					system("pause");
					break;
				}
			}
			case 2: {//添加栈顶元素
				int w;//所要输入的栈顶元素的值
				printf("请输入你所要添加栈顶元素的数据：\n");
				scanf_s("%d", &w);
				listack = Push(listack, w);
				printf("添加元素成功\n");
				system("pause");
				break;
			}
			case 3: {//打印出栈顶元素
				if (StackEmpty(listack)) {
					printf("此栈为空,请输入数据！！！\n");
					system("pause");
					break;
				}
				printf("%d\n", GetTop(listack));
				system("pause");
				break;
			}
			case 4: {//将栈顶元素出栈
				if (StackEmpty(listack)) {
					printf("此栈为空,请输入数据！！！\n");
					system("pause");
					break;
				}
				listack = Pop(listack);
				printf("出栈成功\n");
				system("pause");
				break;
			}
			case 5: {//重置栈中的数据
				listack = InitStack(listack);
				printf("此栈已重置！！！\n");
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
LiStack InitStack(LiStack S)
{
	free(S);
	S = (LiStack*)malloc(sizeof(Linknode));
	S->next = NULL;
	return S;
}

//判断栈是否为空（栈空返回true）
BOOLEAN StackEmpty(LiStack S)
{
	if (S->next == NULL) {
		return TRUE;
	}
	return FALSE;
}

//进栈
LiStack Push(LiStack L, int x)
{
	Linknode* s;
	s = (Linknode*)malloc(sizeof(Linknode));
	s->data = x;
	s->next = L->next;
	L->next = s;
	return L;
}

//出栈
LiStack Pop(LiStack S)
{

	S = S->next;
	return S;
}

//读栈顶元素
int GetTop(LiStack S)
{
	int x;
	x = S->next->data;
	return x;
}

