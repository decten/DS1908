#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define SUCCESS 1
#define FAIL 0

/* ť�� ������ */
typedef int Data;

typedef struct _node
{
	Data data;
	struct _node *pNext;
} Node;

typedef struct _lQueue
{
	Node *pFront;
	Node *pRear;
} LQueue;

typedef LQueue Queue;

/* ť�� ���� */
void queue_init(Queue *pq);   // ť �ʱ�ȭ
void queue_destroy(Queue *pq); // ť ����

int queue_is_empty(Queue *pq); // ť ������� Ȯ��

int queue_enq(Queue *pq, Data data); // ť�� ������ �߰� (enqueue)
int queue_deq(Queue *pq, Data *pData);// ť���� ������ ������ (dequeue)
int queue_peek(Queue *pq, Data *pData);// ������ ���� ������ �鿩�ٺ��� (peek)

#endif