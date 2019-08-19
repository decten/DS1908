#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ�Լ�..
#include <string.h>   // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>    // _getch, putch  .. MS��� C ��ǥ�� �Լ�
#include <time.h>     // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() ��  ���� C �Լ� ���� 
#pragma warning(disable:4477)   // unsigned <--> signed ���� ����

#include "ListQueue.h"

// ť �ʱ�ȭ
void queue_init(Queue *pq)
{
	pq->pFront = NULL;
	pq->pRear = NULL;
}

// ť ����
void queue_destroy(Queue *pq)
{
	while (!queue_is_empty(pq))  // ť���� �����Ͱ� �� �����������
	{
		queue_deq(pq, NULL);
	}

	pq->pFront = NULL;
	pq->pRear = NULL;
}


// ť ������� Ȯ��
int queue_is_empty(Queue *pq)
{
	if (pq->pFront == NULL)
		return SUCCESS;
	else
		return FAIL;
}

// ť�� ������ �߰� (enqueue)
int queue_enq(Queue *pq, Data *pData) //**
{
	// ���ο� ��� ����
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->pNext = NULL;
	pNewNode->str = (char*)malloc(strlen(pData) + 1);  // **
	strcpy(pNewNode->str, pData);  // ** ���ڿ� ����

	//pNewNode->data = data;  // ������ ����

	// ť�� �� ��������� (��, ó�� �����Ͱ� enq �ɶ�) ��
	// �׷��� ������ �����ؼ� ����
	if (queue_is_empty(pq))
	{
		pq->pFront = pNewNode;
		pq->pRear = pNewNode;
	}
	else
	{
		// enqueue �� rear ���� �߻�
		pq->pRear->pNext = pNewNode;
		pq->pRear = pNewNode;   // rear �� ���ο� ���� �̵�
	}
	return SUCCESS;
}

// ť���� ������ ������ (dequeue)
int queue_deq(Queue *pq, Data *pData)
{
	if (queue_is_empty(pq))  // ť���� �� ������ ������ ����
	{
		printf("Queue Error\n");
		return FAIL;
	}

	if (pData != NULL)
		strcpy(pData, pq->pFront->str);   // ** 

	// ������ ��带 ����� ������
	Node * delNode = pq->pFront;  

	pq->pFront = pq->pFront->pNext;  // ���� front �̵�

	free(delNode->str);  // ** ���ڿ� �����޸� ����
	free(delNode);// �׸����� ��� ����

	return SUCCESS;
}

// ������ ���� ������ �鿩�ٺ��� (peek)
int queue_peek(Queue *pq, Data *pData)
{
	if (queue_is_empty(pq))  // ť���� �� ������ ������ ����
	{
		printf("Queue Error\n");
		return FAIL;
	}

	if (pData != NULL)
		strcpy(pData, pq->pFront->str);   // **

	return SUCCESS;
}
