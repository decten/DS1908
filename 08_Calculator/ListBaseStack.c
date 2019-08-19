#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ�Լ�..
#include <string.h>   // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>    // _getch, putch  .. MS��� C ��ǥ�� �Լ�
#include <time.h>     // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() ��  ���� C �Լ� ���� 
#pragma warning(disable:4477)   // unsigned <--> signed ���� ����

#include "ListBaseStack.h"

// ���� �ʱ�ȭ
void stack_init(Stack *pStack)
{
	pStack->pTop = NULL;
}

// ������ ������� Ȯ��
int stack_is_empty(Stack *pStack)
{
	if (pStack->pTop == NULL) return SUCCESS;

	return FAIL;
}

// top �� ������ �߰� (push)
int stack_push(Stack *pStack, Data *pData)
{
	// ���ο� ��� ����
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));
	pNewNode->str = (char*)malloc(strlen(pData) + 1);  // ���ڿ�(��ū)�� ������ŭ �޸� ���� �Ҵ� **
	strcpy(pNewNode->str, pData);   // ���ڿ� ���� **

	// ��带 ���ÿ� �߰�
	pNewNode->pNext = pStack->pTop;
	pStack->pTop = pNewNode;

	return SUCCESS;
}

// top �� ������ ������ (pop)
int stack_pop(Stack *pStack, Data *pData)
{
	if (stack_is_empty(pStack)) {
		printf("Empty Stack\n");
		return FAIL;
	}

	Node *pCurrent = pStack->pTop;   // ������ ��� ���

	if(pData != NULL)
		strcpy(pData, pStack->pTop->str);   // **

	pStack->pTop = pStack->pTop->pNext;   // Top �̵�

	free(pCurrent->str);   // data ���� (�����޸� ����)  **
	free(pCurrent);   // pop �� ��� ����
	return SUCCESS;
}


// top �� ������ �̸����� (peek)
int stack_peek(Stack *pStack, Data *pData)
{
	if (stack_is_empty(pStack)) {
		printf("Empty Stack\n");
		return FAIL;
	}

	if (pData != NULL)
		strcpy(pData, pStack->pTop->str);   // top �� �����͸� ���� **

	return SUCCESS;
}

// ���� ����
void stack_destroy(Stack *pStack)
{
	while (!stack_is_empty(pStack))
	{
		stack_pop(pStack, NULL);   // ������ �� ����������� pop ��Ű��
	}
}


