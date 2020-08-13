#include<stdio.h>
#include<Windows.h>
/*
int alter(int i)
{
	i = 2;
	return 1;
}

int main()
{
	int x = 0;
	//printf("int=%d\n",alter(x));
	char c;
	c = getchar();
	printf("%c",c);
	//printf("%d",x);
	system("pause");
	return 0;
}*/



#define Maxsize 100
typedef struct {
	char ch[Maxsize];
	int length;
}String;

//输出字符
void String_Print(String T) {
	int i;

	for (i = 0; i < T.length; i++) {
		printf("%c", T.ch[i]);
	}
	//printf("%d", T.length);
	printf("\n");
}

//获得并输出字符串的前缀和后缀并输出
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

		String* q;//记录字符串的前缀
		q = (String*)malloc(Maxsize * sizeof(String));
		String* h;//记录字符串的后缀
		h = (String*)malloc(Maxsize * sizeof(String));
		int j;
		//求出T中前i位的前缀
		for (j = 0; j < i; j++) {
			(q + j)->length = 0;
			//q[j].length = 0;
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

//输入字符（输入回车退出）
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


int main()
{
	String s, b;
	s.length = 0;
	b.length = 0;
	printf("sssssss\n");
	s = String_Insert(s);
	//String_Print(s);
	printf("bbbbbbb\n");
	b = String_Insert(b);
	printf("1\n");
	String_Print(s);
	printf("2\n");
	String_Print(b);
	//String_Affix(s);
	system("pause");
	return 0;
}