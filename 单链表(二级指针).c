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
//�����ʼ��
int initList(LinkList* L) {
	if ((*L = (LinkList)malloc(sizeof(LNode))) == NULL)
		return FALSE;
	(*L)->next = NULL;
	return TRUE;
}
//ͷ�巨
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
//��ͷ������
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
	printf("Ԫ��%d�ѱ�ɾ��\n", e);
	print(L);
	return OK;
}
//��ͷ�����ҵ�i��Ԫ��
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
	printf("��%d������ֵΪ%d\n", i, e);
	return OK;
}
void ClearList(LinkList* L) {
	LinkList p;
	while ((*L)->next) {
		p = (*L)->next;
		(*L)->next = p->next;
		free(p);
	}
	printf("\n������ɾ��\n");
}
//����
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
//�����Ƿ���ڽ��x
void search(LinkList L, int x) {
	LinkList p;
	p = L;
	while (p != NULL && p->data != x)
		p = p->next;
	if (p) printf("%d��������\n", x);
	else printf("%d����������\n", x);
}
//�ж��Ƿ����
_Bool increae(LinkList L) {
	LinkList pre, p;
	pre = L->next;
	if (pre != NULL) {
		while (pre->next != NULL) {
			p = pre->next;
			if (p->data > pre->data) pre = p;
			else {
				printf("\n�������ǵ�����\n");
				return FALSE;
			}
		}
		printf("\n�������ǵ�����\n");
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
	printf("\n���������Ϊ:\n");
	print(L);
}
int main()
{
	int i;
	ElemType e;
	LinkList L;
	//initList(&L);
	printf("�����������ĸ���:\n");
	scanf_s("%d", &i);
	CreateList_L(&L, i);
	printf("\n������Ҫ�����λ�ú�Ԫ��:\n");
	scanf_s("%d%d", &i, &e);
	ListInsert_L(L, i, e);
	printf("\n������Ҫɾ������λ��:\n");
	scanf_s("%d", &i);
	ListDelete_L(L, i);
	printf("\n������Ҫ���ҽ���λ��:\n");
	scanf_s("%d", &i);
	GetElem_L(L, i);
	printf("\n������Ϊ:%d\n", length(L));
	printf("\n������Ҫ���ҵ�Ԫ��:\n");
	scanf_s("%d", &e);
	search(L, e);
	increae(L);
	reverse(L);
	ClearList(&L);
	return 0;
}