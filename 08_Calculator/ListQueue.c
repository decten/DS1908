#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환함수..
#include <string.h>   // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>    // _getch, putch  .. MS기반 C 비표준 함수
#include <time.h>     // clock .. 시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등  전통 C 함수 에러 
#pragma warning(disable:4477)   // unsigned <--> signed 관련 에러

#include "ListQueue.h"

// 큐 초기화
void queue_init(Queue *pq)
{
	pq->pFront = NULL;
	pq->pRear = NULL;
}

// 큐 제거
void queue_destroy(Queue *pq)
{
	while (!queue_is_empty(pq))  // 큐안의 데이터가 가 비어질때까지
	{
		queue_deq(pq, NULL);
	}

	pq->pFront = NULL;
	pq->pRear = NULL;
}


// 큐 비었는지 확인
int queue_is_empty(Queue *pq)
{
	if (pq->pFront == NULL)
		return SUCCESS;
	else
		return FAIL;
}

// 큐에 데이터 추가 (enqueue)
int queue_enq(Queue *pq, Data *pData) //**
{
	// 새로운 노드 생성
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->pNext = NULL;
	pNewNode->str = (char*)malloc(strlen(pData) + 1);  // **
	strcpy(pNewNode->str, pData);  // ** 문자열 복사

	//pNewNode->data = data;  // 데이터 저장

	// 큐가 다 비어있을때 (즉, 처음 데이터가 enq 될때) 와
	// 그렇지 않을때 구분해서 동작
	if (queue_is_empty(pq))
	{
		pq->pFront = pNewNode;
		pq->pRear = pNewNode;
	}
	else
	{
		// enqueue 는 rear 에서 발생
		pq->pRear->pNext = pNewNode;
		pq->pRear = pNewNode;   // rear 는 새로운 노드로 이동
	}
	return SUCCESS;
}

// 큐에서 데이터 꺼내기 (dequeue)
int queue_deq(Queue *pq, Data *pData)
{
	if (queue_is_empty(pq))  // 큐에서 더 꺼낼게 없으면 에러
	{
		printf("Queue Error\n");
		return FAIL;
	}

	if (pData != NULL)
		strcpy(pData, pq->pFront->str);   // ** 

	// 삭제될 노드를 기억할 포인터
	Node * delNode = pq->pFront;  

	pq->pFront = pq->pFront->pNext;  // 먼저 front 이동

	free(delNode->str);  // ** 문자열 동적메모리 해제
	free(delNode);// 그리고나서 노드 삭제

	return SUCCESS;
}

// 다음에 꺼낼 데이터 들여다보기 (peek)
int queue_peek(Queue *pq, Data *pData)
{
	if (queue_is_empty(pq))  // 큐에서 더 꺼낼게 없으면 에러
	{
		printf("Queue Error\n");
		return FAIL;
	}

	if (pData != NULL)
		strcpy(pData, pq->pFront->str);   // **

	return SUCCESS;
}
