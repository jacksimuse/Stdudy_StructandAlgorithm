#include <stdio.h>

typedef struct dlistnode {
	int data;
	struct dlistnode* next; // �ڸ� ����Ŵ
	struct dlistnode* prev; // ������ ����Ŵ
} DListnode;

typedef struct HeadNode {
	DListnode* head;
} HeadNode;

HeadNode* creatHeadNode() {
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL;
	return h;
}
DListnode* createNode(int data)
{
	DListnode* newNode = (DListnode*)malloc(sizeof(DListnode));
	if (newNode == NULL)
	{
		printf("�޸� �Ҵ� ����!");
		exit(1);
	}
	else {
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
}
void insertNode(HeadNode* phead, DListnode* preNode, DListnode* newNode)
{
	if (phead->head == NULL) { // ��尡 �Űܰ��鼭 newNode�� �� ��尡 �ִ� ���� ������ġ
		newNode->next = NULL;
		newNode->prev = NULL;
		phead->head = newNode;
	}
	else {
		newNode->next = preNode->next;
		preNode->next = newNode;
		newNode->prev = preNode;
		if (newNode->next != NULL)
			newNode->next->prev = newNode;
	}	
}
DListnode* findNode(HeadNode* phead, int data)
{
	DListnode* temp = phead->head;
	while (phead->head != data)
	{
		if (temp->data == data)
		{
			printf("ã�� ��� �����ʹ� %d�Դϴ�.\n", temp->data);
			return temp;
		}
		else temp = temp->next;
	}
	return temp;
}

void findDel(HeadNode* phead, DListnode* fn)
{
	DListnode* temp = phead->head;
	if (temp == fn) phead->head = temp->next;
	else if (fn == NULL) return;
	else if (temp->next == fn)
	{
		temp->next = fn->next;
		if (fn->next != NULL) fn->next->prev = temp;
	}
	while (temp->next != fn) // temp�� �˻���� �������
	{
		temp = temp->next;
	}
	temp->next = fn->next;
	fn->prev = temp;
	printf("�˻��� ��带 �����մϴ�\n");
	free(fn);
}
void allDelNode(HeadNode* phead)
{
	DListnode* temp;
	while (phead->head != NULL)
	{
		temp = phead->head;
		phead->head = temp->next;
		free(temp);
	}
	printf("��� �����մϴ�\n");
	free(phead);
}
void printallNode(HeadNode* phead)
{
	if (phead->head == NULL)
	{
		printf("����� ��尡 �����ϴ�.\n");
	}
	else
	{
		DListnode* curr = phead->head;
		int i = 1;
		while (curr != NULL)
		{
			printf("%d��° ��� ������ %d\n", i, curr->data);
			//printf("���� �ּ�: %u / ���� �ּ�: %u / ���� �ּ�: %u\n", curr->prev, curr, curr->next);
			curr = curr->next;
			i++;
		}
	}
}
int main()
{
	HeadNode* h = creatHeadNode();
	DListnode* newNode1 = createNode(10);
	DListnode* newNode2 = createNode(20);
	DListnode* newNode3 = createNode(30);
	insertNode(h, NULL, newNode1);
	insertNode(h, newNode1, newNode2);
	insertNode(h, newNode2, newNode3);


	printallNode(h);

	DListnode* fn = findNode(h, 20);
	findDel(h, fn);

	allDelNode(h);
	
	return 0;
}