#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환함수..
#include <string.h>   // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>    // _getch, putch  .. MS기반 C 비표준 함수
#include <time.h>     // clock .. 시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등  전통 C 함수 에러 
#pragma warning(disable:4477)   // unsigned <--> signed 관련 에러

#include "ListBaseStack.h"

// 스택 초기화
void stack_init(Stack *pStack)
{
	pStack->pTop = NULL;
}

// 스택이 비었는지 확인
int stack_is_empty(Stack *pStack)
{
	if (pStack->pTop == NULL) return SUCCESS;

	return FAIL;
}

// top 에 데이터 추가 (push)
int stack_push(Stack *pStack, Data *pData)
{
	// 새로운 노드 생성
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));
	pNewNode->str = (char*)malloc(strlen(pData) + 1);  // 문자열(토큰)을 담을만큼 메모리 공간 할당 **
	strcpy(pNewNode->str, pData);   // 문자열 복사 **

	// 노드를 스택에 추가
	pNewNode->pNext = pStack->pTop;
	pStack->pTop = pNewNode;

	return SUCCESS;
}

// top 의 데이터 꺼내기 (pop)
int stack_pop(Stack *pStack, Data *pData)
{
	if (stack_is_empty(pStack)) {
		printf("Empty Stack\n");
		return FAIL;
	}

	Node *pCurrent = pStack->pTop;   // 삭제할 노드 기억

	if(pData != NULL)
		strcpy(pData, pStack->pTop->str);   // **

	pStack->pTop = pStack->pTop->pNext;   // Top 이동

	free(pCurrent->str);   // data 제거 (동적메모리 제거)  **
	free(pCurrent);   // pop 된 노드 제거
	return SUCCESS;
}


// top 의 데이터 미리보기 (peek)
int stack_peek(Stack *pStack, Data *pData)
{
	if (stack_is_empty(pStack)) {
		printf("Empty Stack\n");
		return FAIL;
	}

	if (pData != NULL)
		strcpy(pData, pStack->pTop->str);   // top 의 데이터만 추출 **

	return SUCCESS;
}

// 스택 제거
void stack_destroy(Stack *pStack)
{
	while (!stack_is_empty(pStack))
	{
		stack_pop(pStack, NULL);   // 스택이 다 비어질때까지 pop 시키기
	}
}


