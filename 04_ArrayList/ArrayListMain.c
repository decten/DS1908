#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환함수..
#include <string.h>   // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>    // _getch, putch  .. MS기반 C 비표준 함수
#include <time.h>     // clock .. 시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등  전통 C 함수 에러 
#pragma warning(disable:4477)   // unsigned <--> signed 관련 에러
#include "ArrayList.h"

/*
	ArrayList 의 장점
		: 검색 속도 빠르다.  ex) n번째 데이터 추출!

	ArrayList 의 단점
		: 삭제 속도 느림.
		: 삽입 속도 느림.
*/


// 리스트 출력 도우미 함수
void printList(List *pList)
{
	list_init_iter(pList);   // iteration 초기화
	printf("[");
	while (list_hasNext(pList))
	{
		printf("%d ", list_next(pList));
	}

	printf("]\n");
}

int main(int argc, char** argv)
{
	List myList;   // ArrayList 변수 선언

	list_init(&myList);  // 리스트 초기화
	printList(&myList);
	
	list_add(&myList, 100);  // 데이터 추가
	printList(&myList);
	list_add(&myList, 50);  // 데이터 추가
	printList(&myList);
	list_add(&myList, 100);  // 데이터 추가
	printList(&myList);
	list_add(&myList, 20);  // 데이터 추가
	printList(&myList);
	
	list_add(&myList, 45);  // 데이터 추가 - 실패

	// 데이터 수정
	list_set(&myList, 0, 40);
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 30);  // 실패
	printList(&myList);

	// 데이터 개수
	printf("데이터 개수는 %d\n", list_length(&myList));

	// 데이터 조회
	Data data;
	if (list_get(&myList, 0, &data)) printf("0번째: %d\n", data);
	if (list_get(&myList, 6, &data)) printf("6번째: %d\n", data);
	if (list_get(&myList, 2, &data)) printf("2번째: %d\n", data);

	// 데이터 삭제
	list_remove(&myList, 2);
	printList(&myList);
	list_remove(&myList, 2);
	printList(&myList);
	list_remove(&myList, 0);
	printList(&myList);
	list_remove(&myList, 0);
	printList(&myList);
	list_remove(&myList, 0);
	printList(&myList);

	// insert 테스트
	printf("\n");
	list_add(&myList, 10);
	list_add(&myList, 20);
	printList(&myList);
	list_insert(&myList, 1, 40);
	printList(&myList);   // 10 40 20
	list_insert(&myList, 0, 5);
	printList(&myList);   // 5 10 40 20
	list_insert(&myList, 0, 5);  // 실패

	list_destroy(&myList);  // 리스트 제거


	printf("\n아무키나 입력하시면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()