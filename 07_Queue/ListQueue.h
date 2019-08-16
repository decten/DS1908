#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define SUCCESS 1
#define FAIL 0

/* 큐의 데이터 */
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

/* 큐의 동작 */
void queue_init(Queue *pq);   // 큐 초기화
void queue_destroy(Queue *pq); // 큐 제거

int queue_is_empty(Queue *pq); // 큐 비었는지 확인

int queue_enq(Queue *pq, Data data); // 큐에 데이터 추가 (enqueue)
int queue_deq(Queue *pq, Data *pData);// 큐에서 데이터 꺼내기 (dequeue)
int queue_peek(Queue *pq, Data *pData);// 다음에 꺼낼 데이터 들여다보기 (peek)

#endif
