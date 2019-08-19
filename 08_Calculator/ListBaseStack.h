#ifndef __STACK_H__
#define __STACK_H__

#define SUCCESS 1
#define FAIL 0

/* ������ Adt */

/* ������ ������ */
#ifndef __NODE_DATA__
#define __NODE_DATA__
typedef char Data;     

typedef struct _node
{
	Data *str;   // ���ڿ� (�����޸�)
	struct _node *pNext;
} Node;
#endif

typedef struct _listStack
{
	Node *pTop; // �� �̹����������� numData ���� ����
} ListStack;

typedef ListStack Stack;

/* ������ ���� */
void stack_init(Stack *pStack);    // ���� �ʱ�ȭ
void stack_destroy(Stack *pStack);  // ���� ����

int stack_is_empty(Stack *pStack);// ������ ������� Ȯ��

int stack_push(Stack *pStack, Data *pData);// top �� ������ �߰� (push)
int stack_pop(Stack *pStack, Data *pData);// top �� ������ ������ (pop)
int stack_peek(Stack *pStack, Data *pData);// top �� ������ �̸����� (peek)

#endif
