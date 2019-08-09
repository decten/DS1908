#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환함수..
#include <string.h>   // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>    // _getch, putch  .. MS기반 C 비표준 함수
#include <time.h>     // clock .. 시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등  전통 C 함수 에러 
#pragma warning(disable:4477)   // unsigned <--> signed 관련 에러

/*

*/

int main(int argc, char** argv)
{
	// 배열 선언 및 초기화
	int arr[5] = {1, 2, 3, 4, 5};   // int 타입 5개를 담는 배열 arr 을 선언

	int i;
	// 배열[n] 의 index 는 0 부터 시작 ~ n - 1까지
	for (i = 0; i < 5; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	// 배열이름 arr ..  배열변수라고도 하나.  본질적으로 '포인터' 다!
	printf("arr = %d\n", arr);
	printf("arr = %p\n", arr);

	// sizeof() 연산자, byte 단위 용량 리턴
	int n = 100;
	printf("sizeof(n) = %d\n", sizeof(n));
	printf("sizeof(double) = %d\n", sizeof(double));
	printf("sizeof(arr[0]) = %d\n", sizeof(arr[0]));
	printf("sizeof(arr) = %d\n", sizeof(arr));   // 배열의 크기(size)

	// 배열원소의 개수
	// 배열의 길이 length
	printf("length = %d\n", sizeof(arr) / sizeof(arr[0]));






	printf("\n아무키나 입력하시면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()