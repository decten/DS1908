#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환함수..
#include <string.h>   // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>    // _getch, putch  .. MS기반 C 비표준 함수
#include <time.h>     // clock .. 시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등  전통 C 함수 에러 
#pragma warning(disable:4477)   // unsigned <--> signed 관련 에러
#include "ArrayList.h"

/* 매개변수 유효성 검증 생략 */

// 리스트 초기화
void list_init(List *pList)
{
	pList->numData = 0;
	pList->curPosition = -1;
	memset(pList->arr, 0, sizeof(pList->arr));   // 배열 arr 을 0 으로 초기화
	printf("리스트 초기화\n");
}

// 리스트 제거
void list_destroy(List *pList)
{
	pList->numData = 0;
	printf("리스트 제거\n");
}

// 데이터 추가
int list_add(List *pList, Data data)
{
	if (pList->numData >= LIST_LEN)
	{
		printf("데이터 추가 불가\n");
		return FAIL;
	}

	pList->arr[pList->numData] = data;

	printf("[%d] 번째 데이터 %d 추가\n", pList->numData, data);
	(pList->numData)++;
	return SUCCESS;
}

// 데이터 수정
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) {
		printf("%d 번째 데이터 수정 실패\n", n);
		return FAIL;
	}

	printf("%d 번째 데이터 수정 %d  --> %d\n", n, pList->arr[n], data);
	pList->arr[n] = data;  // n번째 데이터값을 data 로 수정
	return SUCCESS;
}

// 데이터 개수
int list_length(List *pList)
{
	return pList->numData;    // ArrayList 안의 현재 데이터 개수
}

// 데이터 조회 : n번째 데이터
int list_get(List *pList, int n, Data *pData)
{
	if (n >= pList->numData) return FAIL;

	*pData = pList->arr[n];   // 데이터값, 포인터가 가리키는 곳에 저장

	return SUCCESS;
}

// 데이터 삭제 : n번째 데이터
int list_remove(List *pList, int n)
{
	// 배열이니까.. 중간에 삭제 하면 뒤의 데이터들을 한칸씩 당겨야 한다 (복사발생!!)
	if (n >= pList->numData) {
		printf("%d 번째 데이터 삭제 실패\n", n);
		return FAIL;
	}

	// n번째 부터 시작해서 numData번째 이전까지 한칸씩 당기기
	for (int i = n; i < pList->numData; i++)
	{
		pList->arr[i] = pList->arr[i + 1];  // 뒤의 것으로 앞의 것을 복사해 넣기 (덮어쓰기)
	}

	pList->numData--;   // 리스트 개수 감소

	//printf("%d 번째 데이터 삭제 성공\n", n);

	return SUCCESS;
}


// iteration : 초기화
void list_init_iter(List *pList)
{
	pList->curPosition = -1;  // 뒤로 한칸 당겨놓고 시작
}

// iteration : 다음 데이터 추출
Data list_next(List *pList)
{
	pList->curPosition++;    // 일단 position 증가
	Data result = pList->arr[pList->curPosition];   // position 의 데이터 값 추출

	return result;
}

// iteration : 다음 데이터 유무
int list_hasNext(List *pList)
{
	if (pList->curPosition + 1 < pList->numData)
		return SUCCESS;   

	return FAIL;
}


// 데이터 삽입: n번째 위치에 데이터 삽입
int list_insert(List* pList, int n, Data data)
{
	// 이미 다 차있으면 불가
	if (pList->numData >= LIST_LEN){
		printf("데이터 추가삽입 불가\n");
		return FAIL;
	}

	// 중간, 끝 삽입 허용
	if (n > pList->numData){
		printf("%d 번째 위치에 삽입 불가\n", n);
		return FAIL;
	}

	// 기존의 n번째 부터 한칸씩 뒤로 밀려나야 한다.
	// 맨뒤에서부터!!! n 앞의 것들을 한칸씩 우측으로 복사
	for (int i = pList->numData; i - 1 >= n; i--)
	{
		pList->arr[i] = pList->arr[i - 1];
	}

	pList->arr[n] = data;  // n 번재 새 데이터 삽입
	pList->numData++;   // 데이터 개수 증가
	
	//printf("%d번째 데이터 %d 삽입 성공\n", n, data);

	return SUCCESS;
}