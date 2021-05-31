#include <stdio.h>

typedef struct listnode {
	int data;
	struct listnode* link;
}ListNode;

typedef struct {
	ListNode* head;
}HeadNode;

HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL;
	return h;
}

ListNode* createNode(HeadNode* h, int data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		printf("�޸� �Ҵ� ����!!");
		return;
	}
	else {
		newNode->data = data;
		newNode->link = NULL;
		return newNode;
	}
}

void insertFirstNode(HeadNode* h, ListNode* newNode)
{
	if (h->head == NULL)
	{
		h->head = newNode; // ��尡 ���� ������ �ּҰ� �Ǹ� �Űܰ���
		newNode->link = newNode; // ���� ����Ʈ�� �ڱ��ڽ��� ���� �ּҰ� �Ǹ� ��� ������.
	}
	else {
		newNode->link = h->head->link;
		h->head->link = newNode;
	}
}

void insertLastNode(HeadNode* h, ListNode* newNode)
{
	if (h->head == NULL)
	{
		h->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = h->head->link;
		h->head->link = newNode;
		h->head = newNode;
	}
}
void print_Node(HeadNode* h)
{
	ListNode* curr = h->head;
	int i = 1, cnt = 0;

	while (curr != NULL)
	{
		printf("%d��° ��� ������ %d\n", i, curr->data);
		curr = curr->link;
		i++;
		cnt++;
		/*switch (i % 3)
		{
		case 1: i = 1;
		case 2: i = 2;
		case 0: i = 3;
		}*/
		if (cnt == 10) break;
	}
}
int main() {

	HeadNode* h = createHead();
	ListNode* n1 = createNode(h, 10);
	ListNode* n2 = createNode(h, 20);
	ListNode* n3 = createNode(h, 30);

	insertFirstNode(h, n1);
	insertLastNode(h, n3);

	print_Node(h);
	return 0;
}