#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환함수..
#include <string.h>   // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>    // _getch, putch  .. MS기반 C 비표준 함수
#include <time.h>     // clock .. 시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등  전통 C 함수 에러 
#pragma warning(disable:4477)   // unsigned <--> signed 관련 에러

/*
	C, C++ 에서 시간 측정하기
	방법1: time() 사용
	방법2: clock() 사용
*/

int main(int argc, char** argv)
{
	// time() 사용
	//{
	//	// time.h 의 time(NULL) 사용
	//	time_t start, end;

	//	int sum = 0;
	//	printf("time()측정 시작\n");
	//	start = time(NULL);
	//	for (int i = 0; i < 100000; i++) {
	//		for (int j = 0; j < 100000; j++) {
	//			sum += i * j;
	//		}
	//	}
	//	end = time(NULL);
	//	double result = (double)(end - start);
	//	printf("%f s\n", result);   // 결과시간 출력
	//}

	// clock() 사용
	{
		clock_t start, end;

		int sum = 0;
		printf("clock()측정 시작\n");
		start = clock();
		for (int i = 0; i < 100000; i++) {
			for (int j = 0; j < 100000; j++) {
				sum += i * j;
			}
		}
		end = clock();
		long result = (long)(end - start);
		printf("%ld ms\n", result);   // 결과시간 출력
	}


	printf("\n아무키나 입력하시면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()