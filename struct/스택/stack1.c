#include <stdio.h>
#include <stdbool.h>

#define STACK_SZ 3 // �ش� ���ڰ� ���̸� ���ڷ� ��ȯ
//#define TRUE 1
//#define FALSE 2 <stdbool.h>���� T/F ���ص���

int isEmpty();  // ����üũ
int isFull();	// ��ȭüũ
void push(int); // ���ÿ� �Է�
int pop();		// ���ÿ� ���
int peek();		// ������ ����Ȯ��
void printStack();

int stack[STACK_SZ];
int top = -1;   // ���� ���� ��ġ, �׻� ������ �� ���� ����Ų��.
int main()
{
	push(10);
	push(11);
	push(12);
	pop();
	push(13);

	printStack();
	return 0;
}

int isEmpty()
{
	if (top <= -1) return true;
	else return false;
}
int isFull()
{
	if (top >= STACK_SZ - 1) true;
	else return false;
}
void push(int data)
{
	if (isFull()) // ȣ�Ⱚ�� ���ΰ�쵵 ���ǿ� �ش�
	{
		printf("STACK overflow!!\n");
		return;
	}
	else {
		stack[++top] = data; // ù top�� -1 �̹Ƿ� �������Ѽ� 0���� ���
	}
}
int pop()
{
	if (isEmpty()) {
		printf("STACK underflow!!\n");
		return;
	}
	else {
		return stack[top--]; // ž���� ���� ������ ����
	}
}
int peek()
{
	if (isEmpty())
	{
		printf("\n\n STACK is Empty! \n");
		return;
	}
	else return stack[top];
}
void printStack()
{
	int i;
	if (!isEmpty()) {
		for (i = 0; i <= top; i++) {
			printf("%d   ", stack[i]);
		}
	}
}