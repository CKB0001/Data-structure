#include<stdio.h>
#include<Windows.h>

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//头插法
LinkList List_HeadInsert(LinkList L) {
	LNode* s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf_s("%d", &x);
	}
	return L;
}

//尾插法
LinkList List_TailInsert(LinkList L) {
	L = (LinkList)malloc(sizeof(LNode));

	LNode* s, * r = L;
	int x;
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf_s("%d", &x);
	}
	r->next = NULL;//为了输出添加的语句（可删除）
	return L;
}

//输出
void Print_list(LinkList L) {
	if (L != NULL)
	{
		printf("链表中数据有\n");
		LNode* s;
		s = (LNode*)malloc(sizeof(LNode));
		s = L->next;
		while (s != NULL) {
			printf("%d\n", s->data);
			s = s->next;
		}
		printf("以上就是单链表中的值\n");
	}
	else
	{
		printf("请先向单链表中插入值!!!!\n");
	}
}

//按序号查找其中的数字(0为头结点）
LNode* GetNum(LinkList L, int i) {
	LNode* p;
	p = L->next;
	int s = 1;//记录单链表中的位置
	if (i == 0) {
		return L;
	}
	if (i < 0) {
		return NULL;
	}
	while (p != NULL && s < i) {
		p = p->next;
		s++;
	}
	return p;
}

//按值查找(若没有该值则返回NULL）
LNode* FindNum(LinkList L, int i) {
	LNode* s = L->next;
	while (s != NULL && i != s->data)
		s = s->next;
	return s;
}

//根据位置向单链表中插入结点
LinkList LNode_Insert(LinkList L, int i, LNode* s) {
	LNode* p;
	p = GetNum(L, i - 1);
	if (p != NULL) {
		s->next = p->next;
		p->next = s;
		return L;
	}
	else
	{
		return NULL;//位置不存在
	}
}

//根据位置删除结点
LinkList LNode_Del(LinkList L, int i) {
	LNode* p, * q;
	p = GetNum(L, i - 1);
	if (p != NULL) {
		q = p->next;
		p->next = q->next;
		free(q);
		return L;
	}
	else
	{
		return  NULL;//位置不存在
	}

}


int main() {
	LinkList list;
	list = (LinkList)malloc(sizeof(LNode));
	list = NULL;
	BOOLEAN c = TRUE;//判断程序是否执行下去
	while (c)
	{
		int choice;//判断执行哪个功能
		printf("----------------------------------------------\n");
		printf("0--退出\n");
		printf("1--使用头插法创建单链表\n");
		printf("2--使用尾插法创建单链表\n");
		printf("3--将单链表中的数字打印出来\n");
		printf("4--根据位置删除单链表中的结点\n");
		printf("5--根据位置查找单链表中的值\n");
		printf("6--判断该值是否存在于该单链表中\n");
		printf("7--向单链表中插入结点\n");
		printf("----------------------------------------------\n");
		printf("请输入菜单中的选项\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 0://退出
		{
			c = FALSE;
			break;
		}
		case 1: //使用头插法创建单链表
		{
			printf("输入9999则停止输入该单链表\n");
			LinkList listhead = NULL;
			list = List_HeadInsert(listhead);
			break;
		}
		case 2://使用尾插法创建单链表
		{
			printf("输入9999则停止输入该单链表\n");
			LinkList listTail = NULL;
			list = List_TailInsert(listTail);
			break;
		}
		case 3://将单链表中的数字打印出来
		{
			Print_list(list);
			break;
		}
		case 4://根据位置删除单链表中的结点
		{
			printf("根据位置删除单链表中的结点\n");
			printf("输入删除单链表中结点的位置\n");
			int i;//删除单链表中结点的位置
			scanf_s("%d", &i);
			LinkList listdel;
			listdel = LNode_Del(list, i);
			if (listdel == NULL)
			{
				printf("输入的位置有误\n");
			}
			else
			{
				list = listdel;
			}
			break;
		}
		case 5://根据位置查找单链表中的值
		{
			printf("根据位置查找单链表中的结点\n");
			printf("输入查找单链表中结点的位置\n");
			int i;//查找单链表中结点的位置
			scanf_s("%d", &i);
			LNode* p;//根据位置查找到的结点
			p = GetNum(list, i);
			if (p == NULL)
			{
				printf("输入的位置有误\n");
			}
			else
			{
				printf("第%d位置的数据为：%d\n", i, p->data);

			}
			break;
		}
		case 6://判断该值是否存在于该单链表中
		{
			int i;//查找的数据
			LNode* p;//根据数据查找到的结点
			printf("输入判断是否在单链表中的数据\n");
			scanf_s("%d", &i);
			p = FindNum(list, i);
			if (p == NULL)
			{
				printf("该数据在此单链表中不存在\n");
			}
			else
			{
				printf("该数据在单链表中存在\n");
			}
			break;
		}
		case 7://向单链表中插入结点
		{
			int i;//插入的位置
			LNode* p;//插入的结点
			LinkList s;
			p = (LNode*)malloc(sizeof(LNode));
			printf("请输入插入的位置\n");
			scanf_s("%d", &i);
			printf("请输入插入的结点的数据\n");
			scanf_s("%d", &p->data);
			s = LNode_Insert(list, i, p);
			if (s != NULL)
			{
				printf("插入成功\n");
			}
			else
			{
				printf("插入失败，插入位置错误！！！\n");
			}
			break;
		}
		default:
		{
			printf("请输入正确的选项！！！\n");
		}
		}
	}
	system("pause");
	return 0;
}