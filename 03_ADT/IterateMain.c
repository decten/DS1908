#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환함수..
#include <string.h>   // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>    // _getch, putch  .. MS기반 C 비표준 함수
#include <time.h>     // clock .. 시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등  전통 C 함수 에러 
#pragma warning(disable:4477)   // unsigned <--> signed 관련 에러

#define MAX_LENGTH 4

#define TRUE 1
#define FALSE 0

typedef struct _IterArray
{
	int arr[MAX_LENGTH];
	int curPosition;   // iterator 구현을 위한 값
} IterArray;

// iterator 초기화
void iter_init(IterArray *p)
{
	printf("Iterator 초기화\n");
	p->curPosition = -1;
}

// 다음에 추출할 데이터 있나?
int iter_hasNext(IterArray *p)
{
	if (p->curPosition + 1 < MAX_LENGTH) {
		return TRUE;
	}
	else {
		printf("더이상 추출할 데이터가 없습니다\n");
		return FALSE;
	}
}

// 데이터 추출
int iter_next(IterArray *p)
{
	p->curPosition++;     // position 이 next 로 먼저 증가하고
	return p->arr[p->curPosition];   // 그 다음에 값을 가져온다
}

int main(int argc, char** argv)
{
	IterArray data = { {10, 20, 30, 40} , -1 };
	iter_init(&data);

	while (iter_hasNext(&data)) {
		printf("%d ", iter_next(&data));
	}
	printf("\n");

	// 다시 iterator 돌리려 하면?
	while (iter_hasNext(&data)) {
		printf("%d ", iter_next(&data));
	}
	printf("\n");

	// iterator 는 새로 동작시켜야 한다
	iter_init(&data);
	while (iter_hasNext(&data)) {
		printf("%d ", iter_next(&data));
	}
	printf("\n");



	printf("\n아무키나 입력하시면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()