#include <stdio.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct {
	Node* head; // ��带 ����ų �� �ִ� Ÿ���� �;��Ѵ�.
}HeadNode;

/* �Լ� �ۼ����
1. �Լ����� ���� �ȿ� ������ ä���
2. ������ �Լ� ȣ��� Ȱ���� ������� ä���
(�����Ҵ�)
�Ҵ�ũ��� ������� ũ��(������ ����� ����ü�� ����ű� ����)
�տ� �����Ҵ��� ���Ϲޱ� ���� �ڷ����� ����(������ ����Ʈ�� ȭ��ǥ�� �����ͷ� ����)
3. �Լ��� �� ����� �Լ��� ��°� �Է��� �˷��ش�*/

/* ����� �����ϴ� �Լ� */
HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode)); // h��� ���ڿ� ũ�⸦ �������ؼ�
	if (h != NULL) h->head = NULL; // h�� �����Ҵ��� �޾Ƽ� NULL�� �ƴϹǷ� if���� / h�� head�� ����Ű���ְ� �� ���� NULL�� �־��� ��Ȳ
	return h;
}
/*���� ���*/
void preinsertNode(HeadNode* h, int data)
{
	Node* newNode= (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = h->head; // ����� ����Ű�� ���� newNode�� next�� �����°�
		h->head = newNode;
	}
}
/*���� ���*/
void rearinsertNode(HeadNode* header, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = NULL;

		if (header->head == NULL)
		{
			header->head = newNode;
		}
		else if (header->head != NULL) // h ���� ��尡 �ִ� ���
		{
			Node* curr = header->head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = newNode;
		}
	}
}
/*���*/
void print_nodeData(HeadNode *h)
{
	Node* curr = h->head;
	int i = 1;

	while (curr != NULL)
	{
		printf("%d��° ��� ������ %d\n", i, curr->data);
		curr = curr->next;
		i++;
	}
}
/*��ü ��� ����*/
void allDelNode(HeadNode* h)
{
	// temp = h->head;
	// h->head = temp->next;
	// free(temp);
	Node* temp;
	while (h->head != NULL)
	{
		temp = h->head;
		h->head = temp->next;
		free(temp);
	}
	free(h);
}

Node* searchNode(HeadNode* h, int data)
{
	Node* s = h->head;

	while (s != NULL)
	{
		if (s->data == data)
		{
			printf("���� ã�� �ִ� ������ ���� : %d \n", data); 
			return s;
		}
		else s = s->next;
	}
	return s;
}

void searchdelNode(HeadNode* h,  Node* s)
{
	Node* temp = h->head;
	if (h->head == s)
	{
		h->head = temp->next;
	}

	if (s == NULL) return;
	else if (temp == NULL) return;
	else if (temp->next == s)
	{
		temp->next = s->next;
		free(s); // ��尡 ù��°�� ����ų�� ù��°�� s�̸�
	}
	else 
	{
		while (temp != s) // s�������� ��� ������
		{
			temp = temp->next;
		}
		temp->next = s->next;
		printf("�˻��� ������ %d�� �����մϴ�\n", s->data);
		free(s);
		
	}
	// 1. h->head == NULL
	
	// 2. s == NULL
	// 3. h->head->next == NULL : ����Ʈ�� ��尡 1��
	// 4. else 
	//		if (temp == s)  : ����Ʈ�� ��尡 2�� �̻�, ù��° 
	// 	    else
}
/*����*/
int main() {

	HeadNode* h = createHead();
	preinsertNode(h, 30);
	rearinsertNode(h, 10);
	rearinsertNode(h, 20);
	


	print_nodeData(h);
	
	Node* s = searchNode(h, 0);
	searchdelNode(h, s);

	print_nodeData(h);

	allDelNode(h);

	//print_nodeData(h);
	return 0;
}