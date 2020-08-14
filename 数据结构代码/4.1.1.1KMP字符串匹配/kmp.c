/*������֮ǰʹ�����鵫������ջ������������Խ����Ϊָ�룬����Ϊָ���ע��Ҫ�����ͷţ�����Ҳѧϰ�������ָ���ǵȼ۵ģ�*/
/*����c���Եĺ�����û�а취������������ģ��������������һ��ֵ�ĵ�ַ������һ�㽫��ת��Ϊָ����д���*/

#include<stdio.h>
#include<Windows.h>
#include<string.h>
#define Maxsize 100
typedef struct {
	char ch[Maxsize];
	int length;
}String;
/*��������*/
int* get_PM(String T);//����ַ����Ĳ���ƥ��ֵ(���������ַ�����ǰ׺�ͺ�׺�ظ��Ĳ��֣���Ϊ�˵��˴����������ظ���һ��)
String String_Insert(String T);//�����ַ������룡�˳���
void String_Print(String T);//����ַ�
void String_Affix(String T);//��ò�����ַ�����ǰ׺�ͺ�׺�����
int String_Matching(String T1, String T2, int* pm);//�����ַ�����ƥ��(����ƥ�俪ʼ����ʼλ�ã�(λ�ô�1��ʼ����)��������ֵ����T1�ĳ������ʾ��ƥ�䣩

/*������*/
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
		printf("0------�˳�\n");
		printf("1------�����ַ���T1��T2\n");
		printf("2------����T1��T2���ַ���ƥ��\n");
		printf("3------���T2��ǰ��׺\n");
		printf("4------���PM��\n");
		printf("5------���T1��ֵ\n");
		printf("6------���T2��ֵ\n");
		printf("==================================\n");
		int x = 0;
		printf("������ѡ��:\n");
		scanf_s("%d", &x);
		rewind(stdin);//����������е��ַ�����Ȼ�������scanf_s�����\n,fflush(stdin)������ʹ�ã�û��Ч��
		switch (x) {
		case 0: {//�˳�
			c = FALSE;
			free(PM);
			break;
		}
		case 1: {//�����ַ���T1��T2
			{
				printf("���룡�����ַ�����\n");
				printf("������T1��ֵ\n");
				T1 = String_Insert(T1);
				printf("������T2��ֵ\n");
				T2 = String_Insert(T2);
			}
			break;
		}
		case 2: {//����T1��T2���ַ���ƥ��
			if (T1.length == 0 || T2.length == 0) {
				printf("������T1��T2��ֵ!!!\n");
				break;
			}
			else {
				PM = get_PM(T2);
				int w = 0;
				w = String_Matching(T1, T2, PM);
				if (w > T1.length) {
					printf("T2��T1��ƥ��\n");
				}
				else {
					printf("T2��T1ƥ�䣬T2��T1�ĵ�%dλ\n", w);
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
		case 3: {//���T2��ǰ��׺
			if (T1.length == 0 || T2.length == 0) {
				printf("������T1��T2��ֵ!!!\n");
				break;
			}
			else {
				String_Affix(T2);
				break;
			}
		}
		case 4: {//���PM��
			if (T2.length == 0) {
				printf("������T2��ֵ!!!\n");
				break;
			}
			else {
				PM = get_PM(T2);
				int j;
				printf("PM��Ϊ\n");
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
		case 5: {//���T1��ֵ
			if (T1.length == 0) {
				printf("������T1��ֵ!!!\n");
				break;
			}
			else {
				printf("�ַ���T1��ֵΪ");
				String_Print(T1);
				break;
			}
		}
		case 6: {//���T2��ֵ
			if (T2.length == 0) {
				printf("������T2��ֵ!!!\n");
				break;
			}
			else {
				printf("�ַ���T2��ֵΪ");
				String_Print(T2);
				break;
			}
		}
		default: {
			printf("��������ȷ��ѡ��!!!\n");
			break;
		}
		}
	}
	system("pause");
	return 0;
}

//�����ַ�����ƥ��(����ƥ�俪ʼ����ʼλ�ã�(λ�ô�1��ʼ����)��������ֵ����T1�ĳ������ʾ��ƥ�䣩
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

//����ַ����Ĳ���ƥ��ֵ(���������ַ�����ǰ׺�ͺ�׺�ظ��Ĳ��֣���Ϊ�˵��˴����������ظ���һ��)
int* get_PM(String T) {
	int* pm;
	pm = (int*)malloc(Maxsize * sizeof(int));
	//�趨pm����0��1����
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
		//String q[Maxsize];//��¼�ַ�����ǰ׺
		//String h[Maxsize];//��¼�ַ����ĺ�׺
		String* q;//��¼�ַ�����ǰ׺
		q = (String*)malloc(Maxsize * sizeof(String));
		String* h;//��¼�ַ����ĺ�׺
		h = (String*)malloc(Maxsize * sizeof(String));
		int j;
		//���T��ǰiλ��ǰ׺
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

		//ȷ������pm�е�ֵ
		int m = 0;//������pm�н��и�ֵ��ֵ
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

//�����ַ�������!�˳���
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

//����ַ�
void String_Print(String T) {
	int i;

	for (i = 0; i < T.length; i++) {
		printf("%c", T.ch[i]);
	}
	//printf("%d", T.length);
	printf("\n");
}

//��ò�����ַ�����ǰ׺�ͺ�׺
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

		//String q[Maxsize];//��¼�ַ�����ǰ׺
		//String h[Maxsize];//��¼�ַ����ĺ�׺
		String* q;//��¼�ַ�����ǰ׺
		q = (String*)malloc(Maxsize * sizeof(String));
		String* h;//��¼�ַ����ĺ�׺
		h = (String*)malloc(Maxsize * sizeof(String));
		int j;
		//���T��ǰiλ��ǰ׺
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