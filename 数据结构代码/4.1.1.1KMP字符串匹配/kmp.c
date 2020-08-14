/*本程序之前使用数组但发生了栈溢出的现象，所以将其改为指针，但改为指针后注意要将其释放；本次也学习到数组和指针是等价的，*/
/*而且c语言的函数是没有办法传出整个数组的，传出的是数组第一个值的地址，所以一般将其转换为指针进行传输*/

#include<stdio.h>
#include<Windows.h>
#include<string.h>
#define Maxsize 100
typedef struct {
	char ch[Maxsize];
	int length;
}String;
/*函数声明*/
int* get_PM(String T);//求出字符串的部分匹配值(其中有与字符串的前缀和后缀重复的部分，但为了调运次数少所以重复了一遍)
String String_Insert(String T);//输入字符（输入！退出）
void String_Print(String T);//输出字符
void String_Affix(String T);//获得并输出字符串的前缀和后缀并输出
int String_Matching(String T1, String T2, int* pm);//进行字符串的匹配(返回匹配开始的起始位置（(位置从1开始计算)，若返回值大于T1的长度则表示不匹配）

/*主函数*/
int main() {
	String T1, T2;
	int* PM;
	PM = (int*)malloc(Maxsize * sizeof(int));
	T1.length = 0;
	T2.length = 0;
	BOOLEAN c = TRUE;
	while (c)
	{
		printf("==================================\n");
		printf("0------退出\n");
		printf("1------输入字符串T1和T2\n");
		printf("2------进行T1和T2的字符串匹配\n");
		printf("3------输出T2的前后缀\n");
		printf("4------输出PM表\n");
		printf("5------输出T1的值\n");
		printf("6------输出T2的值\n");
		printf("==================================\n");
		int x = 0;
		printf("请输入选项:\n");
		scanf_s("%d", &x);
		rewind(stdin);//清除缓冲区中的字符，不然它会残留scanf_s输入的\n,fflush(stdin)不建议使用，没有效果
		switch (x) {
		case 0: {//退出
			c = FALSE;
			free(PM);
			break;
		}
		case 1: {//输入字符串T1和T2
			{
				printf("输入！结束字符输入\n");
				printf("请输入T1的值\n");
				T1 = String_Insert(T1);
				printf("请输入T2的值\n");
				T2 = String_Insert(T2);
			}
			break;
		}
		case 2: {//进行T1和T2的字符串匹配
			if (T1.length == 0 || T2.length == 0) {
				printf("请输入T1和T2的值!!!\n");
				break;
			}
			else {
				PM = get_PM(T2);
				int w = 0;
				w = String_Matching(T1, T2, PM);
				if (w > T1.length) {
					printf("T2与T1不匹配\n");
				}
				else {
					printf("T2与T1匹配，T2从T1的第%d位\n", w);
					int j;
					for (j = 0; j < T1.length; j++) {
						printf("%d\t", j + 1);
					}
					printf("\n");
					for (j = 0; j < T1.length; j++) {
						printf("%c\t", T1.ch[j]);
					}
					printf("\n");
					for (j = 0; j < w - 1; j++) {
						printf("%c\t", ' ');
					}
					for (j = 0; j < T2.length; j++) {
						printf("%c\t", T2.ch[j]);
					}
					printf("\n");
				}
				break;
			}
		}
		case 3: {//输出T2的前后缀
			if (T1.length == 0 || T2.length == 0) {
				printf("请输入T1和T2的值!!!\n");
				break;
			}
			else {
				String_Affix(T2);
				break;
			}
		}
		case 4: {//输出PM表
			if (T2.length == 0) {
				printf("请输入T2的值!!!\n");
				break;
			}
			else {
				PM = get_PM(T2);
				int j;
				printf("PM表为\n");
				for (j = 0; j < T2.length; j++) {
					printf("%d\t", j + 1);
				}
				printf("\n");
				for (j = 0; j < T2.length; j++) {
					printf("%c\t", T2.ch[j]);
				}
				printf("\n");
				for (j = 0; j < T2.length; j++) {
					printf("%d\t", *(PM + j));
				}
				printf("\n");
				break;
			}
		}
		case 5: {//输出T1的值
			if (T1.length == 0) {
				printf("请输入T1的值!!!\n");
				break;
			}
			else {
				printf("字符串T1的值为");
				String_Print(T1);
				break;
			}
		}
		case 6: {//输出T2的值
			if (T2.length == 0) {
				printf("请输入T2的值!!!\n");
				break;
			}
			else {
				printf("字符串T2的值为");
				String_Print(T2);
				break;
			}
		}
		default: {
			printf("请输入正确的选项!!!\n");
			break;
		}
		}
	}
	system("pause");
	return 0;
}

//进行字符串的匹配(返回匹配开始的起始位置（(位置从1开始计算)，若返回值大于T1的长度则表示不匹配）
int String_Matching(String T1, String T2, int* pm) {
	int move = 0;
	int i = 0, j = 0, t = 0;
	while (i < T1.length && j < T2.length) {
		if (j == 0) {
			if (T1.ch[i] != T2.ch[j]) {
				i++;
			}
		}
		else {
			if (T1.ch[i] != T2.ch[j]) {
				move = j - *(pm + (j - 1));				i = i - j + move;
				j = 0;
			}
		}
		if (T1.ch[i] == T2.ch[j]) {
			i++;
			j++;
		}
	}
	//printf("i=%d\n",i);
	//printf("j=%d\n",j);
	//printf("i-j=%d\n", (i - j));
	return i - j + 1;
}

//求出字符串的部分匹配值(其中有与字符串的前缀和后缀重复的部分，但为了调运次数少所以重复了一遍)
int* get_PM(String T) {
	int* pm;
	pm = (int*)malloc(Maxsize * sizeof(int));
	//设定pm数组0和1部分
	*pm = 0;
	if (T.ch[0] == T.ch[1])
	{
		*(pm + 1) = 1;
	}
	else
	{
		*(pm + 1) = 0;
	}


	int i = 2;
	while (i < T.length)
	{
		//String q[Maxsize];//记录字符串的前缀
		//String h[Maxsize];//记录字符串的后缀
		String* q;//记录字符串的前缀
		q = (String*)malloc(Maxsize * sizeof(String));
		String* h;//记录字符串的后缀
		h = (String*)malloc(Maxsize * sizeof(String));
		int j;
		//求出T中前i位的前缀
		for (j = 0; j < i; j++) {
			(q + j)->length = 0;
			int u = 0;
			for (; u <= j; u++) {
				//q[j].ch[u] = T.ch[u];				
				//q[j].length++;
				(q + j)->ch[u] = T.ch[u];
				(q + j)->length++;
			}
		}

		//求出T中前i位的后缀		
		int x = 0;
		for (j = i; j > 0; j--, x++) {
			//h[x].length = 0;
			(h + x)->length = 0;
			int u = 0, f = j;
			for (; f <= i; f++, u++) {
				//h[x].ch[u] = T.ch[f];
				//h[x].length++;
				(h + x)->ch[u] = T.ch[f];
				(h + x)->length++;
			}
		}

		//确定数组pm中的值
		int m = 0;//向数组pm中进行赋值的值
		int y;
		for (y = 0; y < i; y++) {
			if (strcmp((q + y)->ch, (h + y)->ch) == 0)
			{
				if ((q + y)->length > m) {
					m = (q + y)->length;
				}
			}
			//printf("strcmp(q[y].ch,h[y].ch)=%d\n", strcmp(q[y].ch, h[y].ch));
			//pm[i] = m;
		}
		*(pm + i) = m;
		printf("pm[i]=%d\n", *(pm + i));
		i++;
	}
	return pm;
};

//输入字符（输入!退出）
String String_Insert(String T) {
	char c;
	c = getchar();
	while (c != '\n') {
		T.ch[T.length] = c;
		T.length++;
		c = getchar();
	}
	return T;
}

//输出字符
void String_Print(String T) {
	int i;

	for (i = 0; i < T.length; i++) {
		printf("%c", T.ch[i]);
	}
	//printf("%d", T.length);
	printf("\n");
}

//获得并输出字符串的前缀和后缀
void String_Affix(String T) {

	//输出i为0和1时的前后缀
	printf("--------------------------------------------\n");
	printf("**********\n");
	printf("%c\n", T.ch[0]);
	printf("**********\n");
	printf("前缀\n");
	printf("前缀为NULL\n");
	printf("后缀\n");
	printf("后缀为NULL\n");
	printf("--------------------------------------------\n");

	printf("--------------------------------------------\n");
	printf("**********\n");
	printf("%c%c\n", T.ch[0], T.ch[1]);
	printf("**********\n");
	printf("前缀\n");
	printf("前缀为%c\n", T.ch[0]);
	printf("后缀\n");
	printf("后缀为%c\n", T.ch[1]);
	printf("--------------------------------------------\n");


	//得到i>=2后的前后缀
	int i = 2;
	while (i < T.length)
	{

		//String q[Maxsize];//记录字符串的前缀
		//String h[Maxsize];//记录字符串的后缀
		String* q;//记录字符串的前缀
		q = (String*)malloc(Maxsize * sizeof(String));
		String* h;//记录字符串的后缀
		h = (String*)malloc(Maxsize * sizeof(String));
		int j;
		//求出T中前i位的前缀
		for (j = 0; j < i; j++) {
			//q[j].length = 0;
			(q + j)->length = 0;
			int u = 0;
			for (; u <= j; u++) {
				//q[j].ch[u] = T.ch[u];				
				//q[j].length++;
				(q + j)->ch[u] = T.ch[u];
				(q + j)->length++;
				//printf("q[%d].ch[%d]=====%c\n",j,u,q[j].ch[u]);
			}
		}

		//求出T中前i位的后缀
		int x = 0;
		for (j = i; j > 0; j--, x++) {

			//h[x].length = 0;
			(h + x)->length = 0;
			int u = 0, f = j;
			for (; f <= i; f++, u++) {

				//h[x].ch[u] = T.ch[f];
				//h[x].length++;
				(h + x)->ch[u] = T.ch[f];
				(h + x)->length++;
			}

		}


		printf("--------------------------------------------\n");
		//输出
		printf("**********\n");
		int g;
		for (g = 0; g <= i; g++) {
			printf("%c", T.ch[g]);
		}
		printf("\n");
		printf("**********\n");

		printf("前缀\n");
		for (g = 0; g < i; g++) {
			String_Print(*(q + g));
		}
		printf("后缀\n");
		for (g = 0; g < i; g++) {
			String_Print(*(h + g));
		}
		printf("--------------------------------------------\n");

		i++;//非常关键的一个值
		free(q);
		free(h);
	}
}