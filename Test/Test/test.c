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

//����ַ�
void String_Print(String T) {
	int i;

	for (i = 0; i < T.length; i++) {
		printf("%c", T.ch[i]);
	}
	//printf("%d", T.length);
	printf("\n");
}

//��ò�����ַ�����ǰ׺�ͺ�׺�����
void String_Affix(String T) {

	//���iΪ0��1ʱ��ǰ��׺
	printf("--------------------------------------------\n");
	printf("**********\n");
	printf("%c\n", T.ch[0]);
	printf("**********\n");
	printf("ǰ׺\n");
	printf("ǰ׺ΪNULL\n");
	printf("��׺\n");
	printf("��׺ΪNULL\n");
	printf("--------------------------------------------\n");

	printf("--------------------------------------------\n");
	printf("**********\n");
	printf("%c%c\n", T.ch[0], T.ch[1]);
	printf("**********\n");
	printf("ǰ׺\n");
	printf("ǰ׺Ϊ%c\n", T.ch[0]);
	printf("��׺\n");
	printf("��׺Ϊ%c\n", T.ch[1]);
	printf("--------------------------------------------\n");


	//�õ�i>=2���ǰ��׺
	int i = 2;
	while (i < T.length)
	{

		String* q;//��¼�ַ�����ǰ׺
		q = (String*)malloc(Maxsize * sizeof(String));
		String* h;//��¼�ַ����ĺ�׺
		h = (String*)malloc(Maxsize * sizeof(String));
		int j;
		//���T��ǰiλ��ǰ׺
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

		//���T��ǰiλ�ĺ�׺
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
		//���
		printf("**********\n");
		int g;
		for (g = 0; g <= i; g++) {
			printf("%c", T.ch[g]);
		}
		printf("\n");
		printf("**********\n");

		printf("ǰ׺\n");
		for (g = 0; g < i; g++) {
			String_Print(*(q + g));
		}
		printf("��׺\n");
		for (g = 0; g < i; g++) {
			String_Print(*(h + g));
		}
		printf("--------------------------------------------\n");

		i++;//�ǳ��ؼ���һ��ֵ
		free(q);
		free(h);
	}


}

//�����ַ�������س��˳���
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