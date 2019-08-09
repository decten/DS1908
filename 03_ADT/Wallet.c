#include <stdio.h>
#include "Wallet.h"

// 지갑의 초기화
void wlt_init(Wallet *p)
{
	printf("지갑을 초기화 합니다\n");
	p->bill1000 = 0;
	p->coin500 = 0;
}

// 동전 삽입
void wlt_put_coin(Wallet *p, int coinNum)
{
	(p->coin500) += coinNum;
	printf("동전 %d 개 삽입되어 %d 개가 되었습니다\n", coinNum, p->coin500);
}

// 동전 추출
int wlt_take_coin(Wallet *p, int coinNum)
{
	if (p->coin500 < coinNum) {
		printf("동전개수가 부족하여 %d 개를 추출할수 없습니다\n", coinNum);
		return FAIL;  // 추출 실패
	}

	p->coin500 -= coinNum;
	printf("동전 %d 개 추출되어 %d 개가 되었습니다\n", coinNum, p->coin500);
	return SUCCESS;  // 추출 성공
}

// 지폐 삽입
void wlt_put_bill(Wallet *p, int billNum)
{
	p->bill1000 += billNum;
	printf("지폐 %d 개 삽입되어 %d 개가 되었습니다\n", billNum, p->bill1000);
}

// 지폐 추출
int wlt_take_bill(Wallet *p, int billNum)
{
	if (p->bill1000 < billNum) {
		printf("지폐개수가 부족하여 %d 개를 추출할수 없습니다\n", billNum);
		return FAIL;
	}

	p->bill1000 -= billNum;
	printf("지폐 %d 개 추출되어 %d개가 되었습니다\n", billNum, p->bill1000);
	return SUCCESS;
}

// 지갑내 잔액 확인
int wlt_balance(Wallet *p)
{
	return p->coin500 * 500 + p->bill1000 * 1000;
}