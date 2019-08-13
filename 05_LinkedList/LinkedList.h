#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

/*
	LinkedList 의 ADT
*/

#define SUCCESS 1
#define FAIL  0

typedef int Data;     // 데이터는 int

// 노드 타입 정의
typedef struct _node {
	Data data;   // 노드 데이터
	struct _node *pNext;   // 다음 노드 포인터
} Node;

// LinkedList 타입 정의
typedef struct _linkedList {
	Node *pHead;   // 시작노드를 가리키는 포인터
	Node *pTail;   // 마지막 노드를 가리키는 포인터

	int numData;   // 데이터 개수 (노드의 개수)

	Node *pCurrent;  // iteration 용
} LinkedList;


/* LinkedList 의 동작 */
typedef LinkedList List;

void list_init(List *pList);   // 리스트 초기화
void list_destroy(List *pList);// 리스트 제거

int list_add(List *pList, Data data);// 데이터 추가
int list_remove(List *pList, int n);// 데이터 삭제 : n번째 데이터
int list_set(List *pList, int n, Data data);// 데이터 수정
int list_length(List *pList);// 데이터 개수

int list_get(List *pList, int n, Data *pData);// 데이터 조회 : n번째 데이터

void list_init_iter(List *pList);// iteration : 초기화
Data list_next(List *pList);// iteration : 다음 데이터 추출
int list_hasNext(List *pList);// iteration : 다음 데이터 유무


int list_insert(List* pList, int n, Data data);   // 데이터 삽입: n번째 위치에 데이터 삽입







#endif