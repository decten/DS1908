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
	for (int i = 0; i < 10; i++) {  // for 블럭 안에서 선언된 지역변수 i
		printf("%d, ", i);
	}
	printf("\n");
	//printf("i = %d", i);  // 블럭 끝난 이후에는 i 사용 못함.

	{
		int n = 10;
		{
			int n = 20;  // 헉!?
			printf("n = %d\n", n);
		}
		printf("n = %d\n", n);
	}
	//printf("n = %d\n", n);

	{
		int  n = 100;
	}

	// 주소 
	{
		int n = 10;
		printf("n = %d\n", n);

		// 주소연산자 &
		printf("n 의 주소는 %p\n", &n);   // 변수 n 의 주소
	}
	printf("\n");
	// 주소를 담는 타입: 포인터 
	{
		int n = 100;
		int *p;      // p 는 int 타입이 아니라 int* 타입

		p = &n;   // 포인터 변수 p 에  'n의 주소' 대입
		printf("p = %p, &n = %p 같다 \n", p, &n);

	}






	printf("\n아무키나 입력하시면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()