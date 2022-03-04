#include <stdio.h>
#include <stdlib.h>

/*�ܼ����Ḯ��Ʈ ���α׷�*/
typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

typedef struct {
	ListNode* head;
}LinkedListType;

//�ʱ�ȭ �Լ�
void init(LinkedListType* L) {
	L->head = NULL;
}

//���� �Լ�
void addFirst(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	node->link = L->head;
	L->head = node;
}

void addLast(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	for (int i = 0; before->link != NULL; i++)
		before = before->link;
	node->data = item;
	node->link = NULL;
	before->link = node;
}

void add(LinkedListType* L, int pos, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++)
		before = before->link;
	node->data = item;
	node->link = before->link;
	before->link = node;
}

//���� �Լ�
int removeFirst(LinkedListType* L) {
	ListNode* removed;
	removed = L->head;
	L->head = removed->link;
	int rdata = removed->data;
	free(removed);
	return rdata;
}

int removeLast(LinkedListType* L) {
	ListNode* removed;
	ListNode* before = L->head;
	for (int i=0; before->link->link != NULL; i++)
		before = before->link;
	removed = before->link;
	before->link = NULL;
	int rdata = removed->data;
	free(removed);
	return rdata;
}

int remove(LinkedListType* L, int pos) {
	ListNode* removed;
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++)
		before = before->link;
	removed = before->link;
	before->link = removed->link;
	int rdata = removed->data;
	free(removed);
	return rdata;
}

//get �Լ�
int get(LinkedListType* L, int pos) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	return p->data;
}

//set �Լ�
void set(LinkedListType* L, int pos, int item) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	p->data = item;
}

//���
void printList(LinkedListType* L) {
	for (ListNode* p = L->head; p != NULL; p = p->link)
		printf("[%d} -> ", p->data);
	printf("NULL\n");
}

/*�ܼ����Ḯ��Ʈ ��*/

void main() {
	LinkedListType list;
	init(&list);

	addFirst(&list, 10); printList(&list);
	addFirst(&list, 20); printList(&list);
	addFirst(&list, 30); printList(&list);
	add(&list, 1, 40); printList(&list);
	add(&list, 1, 50); printList(&list);
	add(&list, 3, 60); printList(&list);
	addLast(&list, 70); printList(&list);
	addLast(&list, 80); printList(&list);
	addLast(&list, 90); printList(&list);

	printf("%d\n", removeFirst(&list)); printList(&list);
	printf("%d\n", removeLast(&list)); printList(&list);
	printf("%d\n", remove(&list, 2)); printList(&list);

	return;
}