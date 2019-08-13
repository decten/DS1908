#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환함수..
#include <string.h>   // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>    // _getch, putch  .. MS기반 C 비표준 함수
#include <time.h>     // clock .. 시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등  전통 C 함수 에러 
#pragma warning(disable:4477)   // unsigned <--> signed 관련 에러
#include "LinkedList.h"
/*

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
	List myList;
	list_init(&myList);

	// add() 동작확인
	printList(&myList);
	list_add(&myList, 100);  // 데이터 추가
	printList(&myList);
	list_add(&myList, 50);  // 데이터 추가
	printList(&myList);
	list_add(&myList, 100);  // 데이터 추가
	printList(&myList);
	list_add(&myList, 100);  // 데이터 추가
	printList(&myList);
	list_add(&myList, 70);  // 데이터 추가
	printList(&myList);

	// 데이터 수정
	list_set(&myList, 0, 40);
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 30);
	list_set(&myList, 10, -400);
	printList(&myList);

	// 데이터 조회 list_get()
	Data data;
	if (list_get(&myList, 4, &data)) printf("data=%d\n", data);
	if (list_get(&myList, 5, &data)) printf("data=%d\n", data);

	// [40 30 100 100 30 ]

	// 데이터 삭제
	list_remove(&myList, 2);    
	printList(&myList);    // [40 30 100 30 ]
	list_remove(&myList, 2);
	printList(&myList);    // [40 30 30 ]
	list_remove(&myList, 0);
	printList(&myList);    // [30 30 ]
	list_remove(&myList, 2);   // x
	list_remove(&myList, 1);    // [30]
	printList(&myList);
	list_remove(&myList, 0);    // []
	printList(&myList);


	// 데이터 삽입
	list_insert(&myList, 0, 100);  
	printList(&myList);               // [100 ]
	list_insert(&myList, 0, 200);
	printList(&myList);                // [200 100 ]
	list_insert(&myList, 1, 400);     
	printList(&myList);                 // [200 400 100 ]
	list_insert(&myList, 3, 500);
	printList(&myList);				// [200 400 100 500]







	printf("\n아무키나 입력하시면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()