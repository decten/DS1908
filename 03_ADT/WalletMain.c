#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환함수..
#include <string.h>   // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>    // _getch, putch  .. MS기반 C 비표준 함수
#include <time.h>     // clock .. 시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등  전통 C 함수 에러 
#pragma warning(disable:4477)   // unsigned <--> signed 관련 에러
#include "Wallet.h"
/*

*/

int main(int argc, char** argv)
{
	Wallet myWallet;  // 지갑 데이터 생성

	wlt_init(&myWallet);   // 지갑 초기화
	wlt_put_coin(&myWallet, 2);// 동전삽입 : 500원 x 2개
	wlt_put_bill(&myWallet, 1);// 지폐삽입 : 1000원 x 1장

	printf("잔액 %d\n", wlt_balance(&myWallet)); 

	wlt_take_coin(&myWallet, 2);   // 동전 추출
	wlt_take_bill(&myWallet, 2);   // 지폐 추출

	printf("잔액 %d\n", wlt_balance(&myWallet));

	printf("\n아무키나 입력하시면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()