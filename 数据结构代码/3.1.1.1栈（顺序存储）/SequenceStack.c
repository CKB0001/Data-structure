#include<stdio.h>
#include<Windows.h>
#define Maxsize 100
typedef struct {
	int data[Maxsize];
	int top;
}SqStack;
/*声明*/
SqStack InitStack(SqStack S);//初始化
BOOLEAN StackEmpty(SqStack S);//判断栈是否为空（栈空返回true）
BOOLEAN StackNull(SqStack S);//判断是否栈满（栈满返回true）
SqStack Push(SqStack S, int x);//进栈
SqStack Pop(SqStack S);//出栈
int GetTop(SqStack S);//读栈顶元素



int main() {
	SqStack stack;
	stack.top = -1;
	BOOLEAN c = TRUE;
	while (c) {
		printf("--------------------------------\n");
		printf("0------退出\n");
		printf("1------判断此栈是否已满\n");
		printf("2------判断此栈是否为空\n");
		printf("3------添加栈顶元素\n");
		printf("4------打印出栈顶元素\n");
		printf("5------将栈顶元素出栈\n");
		printf("6------重置栈中的数据\n");
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
			case 1: {//判断此栈是否已满
				if (StackNull(stack)) {
					printf("此栈已满\n");
					system("pause");
				}
				else {
					printf("此栈还没存满\n");
					system("pause");
				}
				break;
			}
			case 2: {//判断此栈是否为空
				if (StackEmpty(stack)) {
					printf("此栈为空\n");
					system("pause");
				}
				else {
					printf("此栈不为空\n");
					system("pause");
				}
				break;

			}
			case 3: {//添加栈顶元素
				if (StackNull(stack)) {
					printf("此栈已满不能添加元素！！！\n");
					system("pause");
					break;
				}
				int w;//所要输入的栈顶元素的值
				printf("请输入你所要添加栈顶元素的数据：\n");
				scanf_s("%d",&w);
				stack = Push(stack, w);
				printf("添加元素成功\n");
				system("pause");
				break;
			}
			case 4: {//打印出栈顶元素
				if (StackEmpty(stack)) {
					printf("此栈为空！！！\n");
					system("pause");
					break;
				}
				printf("栈顶元素的值为：%d\n",GetTop(stack));
				system("pause");
				break;
			}
			case 5: {//将栈顶元素出栈
				if (StackEmpty(stack)) {
					printf("此栈为空！！！\n");
					system("pause");
					break;
				}
				stack = Pop(stack);
				printf("元素出栈成功\n");
				system("pause");
				break;
			}
			case 6: {//重置栈中的数据
				stack = InitStack(stack);
				printf("栈已被清空\n");
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
SqStack InitStack(SqStack S) {
	S.top = -1;
	return S;
}

//判断栈是否为空
BOOLEAN StackEmpty(SqStack S) {
	if (S.top == -1) {
		return TRUE;//栈为空
	}
	else
		return FALSE;//栈不为空
}

//判断是否栈满（栈满返回true）
BOOLEAN StackNull(SqStack S) {
	if (S.top == Maxsize - 1) {
		return TRUE;//栈满
	}
	return FALSE;
}

//进栈
SqStack Push(SqStack S, int x) {
	S.data[++S.top] = x;
	return S;
}

//出栈
SqStack Pop(SqStack S) {
	S.data[S.top--];
	return S;

}

//读栈顶元素
int GetTop(SqStack S) {
	int x;
	x = S.data[S.top];
	return x;
}
