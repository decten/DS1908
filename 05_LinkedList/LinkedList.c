#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환함수..
#include <string.h>   // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>    // _getch, putch  .. MS기반 C 비표준 함수
#include <time.h>     // clock .. 시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등  전통 C 함수 에러 
#pragma warning(disable:4477)   // unsigned <--> signed 관련 에러

#include "LinkedList.h"

// 리스트 초기화
void list_init(List *pList)
{
	// head용 dummy node 방식
	pList->pHead = (Node*)malloc(sizeof(Node));
	pList->pHead->pNext = NULL;
	pList->pTail = pList->pHead;   // 최초에는 tail과 head 동일

	pList->numData = 0;
	pList->pCurrent = NULL; 
	printf("리스트 초기화\n");
}
// 리스트 제거
void list_destroy(List *pList)
{
	list_init_iter(pList);
	Node *pPrev = NULL;
	while (list_hasNext(pList))
	{
		pPrev = pList->pCurrent;
		list_next(pList);  // pCurrent 이동
		free(pPrev);   // 노드 메모리 해제
	}

	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;

	printf("리스트 소멸\n");
}

// 데이터 추가
int list_add(List *pList, Data data)
{
	// 새로운 node 생성
	Node *pNewNode = (Node*)malloc(sizeof(Node));  // 새로운 Node 메모리 할당 (생성)
	memset(pNewNode, 0, sizeof(Node));    // 새로운 Node, 0으로 초기화
	pNewNode->data = data;       // 데이터 추가

	// tail 이 가리키던 next 를 위에서 만든 새로운 node 에 연결
	pList->pTail->pNext = pNewNode;

	// tail 이동
	pList->pTail = pNewNode;

	printf("[%d] 번째 데이터 %d 추가\n", pList->numData, data);

	(pList->numData)++;   // 데이터 개수 증가
	return SUCCESS;
}

// 데이터 수정
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) return FAIL;

	// head부터시작해서 n번째 노드 찾기,  iteration 사용
	list_init_iter(pList);  
	int i = 0;   // 현재 몇번째 노드?
	while (list_hasNext(pList))
	{
		list_next(pList);

		if (i >= n) break;   // n번째 노드 찾음!

		i++;
	}
	// 위 while 문이 끝나면 pCurrent 는 n번째 노드를 가리키고 있슴

	printf("%d 번째 데이터 수정 %d  --> %d\n", n, pList->pCurrent->data, data);

	pList->pCurrent->data = data;  // 데이터 수정

	return SUCCESS;
}

// 데이터 조회 : n번째 데이터
int list_get(List *pList, int n, Data *pData)
{
	if (n >= pList->numData) return FAIL;

	// n번째 node 찾기,  찾은node는 -> pCurrent
	list_init_iter(pList);
	int i = 0;
	while (list_hasNext(pList))
	{
		list_next(pList);
		if (i >= n) break;
		i++;
	}

	// n번째 노드의 data를 담아줌.
	*pData = pList->pCurrent->data;

	return SUCCESS;
}

// 데이터 삭제 : n번째 데이터
int list_remove(List *pList, int n)
{
	if (n >= pList->numData) return FAIL;

	// n번째 노드 찾기....
	// 이전 노드(previous node)도 알아야 한다.
	list_init_iter(pList);    
	int i = 0;
	Node *pPrev = NULL;   // 이전 노드를 가리킬 포인터
	while (list_hasNext(pList))
	{
		pPrev = pList->pCurrent;   // 이동하기 전의 pCurrent 값을 이전노드 로 기억해야 한다
		list_next(pList);
		if (i >= n) break;
		i++;
	}

	// 위 while 문이 끝나면 
	// pCurrent (n번째 노드), pPrev(n-1번째 노드) 가 결정됨.

	// 순서 잘 생각하기.. 꼬이면 ...엉망이 됩니다.


	// 삭제 진행!  
	pPrev->pNext = pList->pCurrent->pNext;

	// 만약 삭제하려던 n번째 노드가 tail 이었다면?
	if (pList->pCurrent == pList->pTail)
		pList->pTail = pPrev; // tail 을 이전 노드로 이동

	// n번째 노드삭제 동적 메모리 할당 해제! 꼭!
	free(pList->pCurrent);
	
	pList->numData--;  // 리스트 size 감소
	
	//printf("%d 번째 데이터 삭제\n", n);

	return SUCCESS;
}




// 데이터 개수
int list_length(List *pList)
{
	return pList->numData;
}


// iteration : 초기화
void list_init_iter(List *pList)
{
	pList->pCurrent = pList->pHead;  // head 부터 iteration 시작
}

// iteration : 다음 데이터 추출
Data list_next(List *pList)
{
	pList->pCurrent = pList->pCurrent->pNext;  // 우선 Current 를 다음으로 이동
	Data result = pList->pCurrent->data;
	return result;
}

// iteration : 다음 데이터 유무
int list_hasNext(List *pList)
{
	if (pList->pCurrent->pNext == NULL)  // '다음 노드' 존재 여부 체크
		return FAIL;

	return SUCCESS;
}

// 데이터 삽입: n번째 위치에 데이터 삽입
int list_insert(List* pList, int n, Data data)
{
	if (n > pList->numData) return FAIL;   // >= 이 아니라 > 이다!
	// ex) numData => 4
	// insert 가능 인덱스 : 0, 1, 2, 3, 4
	// get, remove, set 가능 인덱스 : 0, 1, 2, 3

	// ex) numData => 0
	// insert 가능 인덱스 : 0

	// 새로운 node 생성
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));
	pNewNode->data = data;

	if (pList->numData == 0) // #1 : 첫번째 데이터 insert 하는 경우
	{
		pList->pHead->pNext = pNewNode;
		pList->pTail = pNewNode;
	}
	else if (pList->numData == n)// #2 : 맨 끝 뒤에 insert 하는 경우
	{
		pList->pTail->pNext = pNewNode;
		pList->pTail = pNewNode;
	}
	else // #3 : 나머지.
	{
		// n번째 노드 찾기..
		// 이전노드 (prev node) 또한 알아야 한다.
		list_init_iter(pList);
		int i = 0;
		Node *pPrev = NULL; // 이전 노드를 가리킬 포인터
		while (list_hasNext(pList))
		{
			pPrev = pList->pCurrent;  // pCurrent 이동전에 pCurrent값을 이전 노드 값으로 기억해야 함
			list_next(pList);    // pCurrent 값 이동
			if (i >= n) break;    // n번째 노드 찾으면 종료
			i++;
		}

		// 위 while 문이 끝나면
		// pCurrent(n 번째 노드),  pPrev(n -1 번째 노드) 가 결정됨

		// 삽입동작 수행
		pPrev->pNext = pNewNode;   // 이전노드는 새로운 노드를 가리키고
		pNewNode->pNext = pList->pCurrent;    // 새로운 노드는 current 를 가리킴
	}

	(pList->numData)++;    // 개수증가
	return FAIL;
}
