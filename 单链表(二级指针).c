#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define TRUE 1
#define OVERFLOW -2
#define ERROR 0
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;
void print(LinkList L);
//链表初始化
int initList(LinkList* L) {
	if ((*L = (LinkList)malloc(sizeof(LNode))) == NULL)
		return FALSE;
	(*L)->next = NULL;
	return TRUE;
}
//头插法
Status CreateList_L(LinkList* L, int n)
{
	LinkList p;
	if ((*L = (LinkList)malloc(sizeof(LNode))) == NULL)
		return FALSE;
	(*L)->next = NULL;
	for (int i = n; i > 0; --i) {
		p = (LinkList)malloc(sizeof(LNode));
		if (p == NULL) exit(OVERFLOW);
		scanf_s("%d", &p->data);
		p->next = (*L)->next;
		(*L)->next = p;
	}
	print(*L);
}
//带头结点插入
Status ListInsert_L(LinkList L, int i, ElemType e) {
	int j = 0;
	LinkList p, s;
	p = L;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	if (s == NULL) exit(OVERFLOW);
	s->data = e;
	s->next = p->next;
	p->next = s;
	print(L);
	return OK;
}
Status ListDelete_L(LinkList L, int i) {
	int j = 0;
	LinkList p, q;
	ElemType e;
	p = L;
	while (p->next && j < i - 1) {
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1) return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	printf("元素%d已被删除\n", e);
	print(L);
	return OK;
}
//带头结点查找第i个元素
Status GetElem_L(LinkList L, int i) {
	int j = 1;
	ElemType e;
	LNode* p;
	p = L->next;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;
	printf("第%d个结点的值为%d\n", i, e);
	return OK;
}
void ClearList(LinkList* L) {
	LinkList p;
	while ((*L)->next) {
		p = (*L)->next;
		(*L)->next = p->next;
		free(p);
	}
	printf("\n链表已删除\n");
}
//遍历
void print(LinkList L) {
	LNode* p;
	p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
int length(LinkList L) {
	LinkList p;
	int n = 0;
	p = L->next;
	while (p != NULL) {
		p = p->next;
		n++;
	}
	return n;
}
//查找是否存在结点x
void search(LinkList L, int x) {
	LinkList p;
	p = L;
	while (p != NULL && p->data != x)
		p = p->next;
	if (p) printf("%d在链表内\n", x);
	else printf("%d不在链表内\n", x);
}
//判断是否递增
_Bool increae(LinkList L) {
	LinkList pre, p;
	pre = L->next;
	if (pre != NULL) {
		while (pre->next != NULL) {
			p = pre->next;
			if (p->data > pre->data) pre = p;
			else {
				printf("\n该链表不是递增的\n");
				return FALSE;
			}
		}
		printf("\n该链表是递增的\n");
		return TRUE;
	}
}
void reverse(LinkList L) {
	LinkList p, q;
	p = L->next;
	L->next = NULL;
	while (p != NULL) {
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
	printf("\n链表的逆置为:\n");
	print(L);
}
int main()
{
	int i;
	ElemType e;
	LinkList L;
	//initList(&L);
	printf("请输入插入结点的个数:\n");
	scanf_s("%d", &i);
	CreateList_L(&L, i);
	printf("\n请输入要插入的位置和元素:\n");
	scanf_s("%d%d", &i, &e);
	ListInsert_L(L, i, e);
	printf("\n请输入要删除结点的位置:\n");
	scanf_s("%d", &i);
	ListDelete_L(L, i);
	printf("\n请输入要查找结点的位置:\n");
	scanf_s("%d", &i);
	GetElem_L(L, i);
	printf("\n链表长度为:%d\n", length(L));
	printf("\n请输入要查找的元素:\n");
	scanf_s("%d", &e);
	search(L, e);
	increae(L);
	reverse(L);
	ClearList(&L);
	return 0;
}