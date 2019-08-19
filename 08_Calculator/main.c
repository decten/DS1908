#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환함수..
#include <string.h>   // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>    // _getch, putch  .. MS기반 C 비표준 함수
#include <time.h>     // clock .. 시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등  전통 C 함수 에러 
#pragma warning(disable:4477)   // unsigned <--> signed 관련 에러

#include "ListBaseStack.h"
#include "ListQueue.h"

// 전역변수 
#define MAX_EXPR_LENGTH 100      // 수식 하나당 최대 문자열 길이
#define MAX_TOKEN_LENGTH 10      // 토큰 한개당 담을수 있는 최대 문자열 길이

#define TRUE 1
#define FALSE 0

// 연산자 우선순위(precedence) 정보
// + - * /
int PRECED_PLUS = 2;
int PRECED_MINUS = 2;
int PRECED_MUL = 3;   // +, - 보다는 우선순위 높으면 됨
int PRECED_DIV = 3;

// 연산자 우선순위 리턴
int getPreced(char *op)
{
	if(!strcmp("+", op)) return PRECED_PLUS;
	if(!strcmp("-", op)) return PRECED_MINUS;
	if(!strcmp("*", op)) return PRECED_MUL;
	if(!strcmp("/", op)) return PRECED_DIV;
	return 0;
}

// 연산자 우선순위 비교
//  리턴값:  0 -> 같다,   음수 -> op1 < op2,  양수 -> op1 > op2
int compOp(char *op1, char *op2)
{
	return getPreced(op1) - getPreced(op2);
}

// 주어진 문자열이 숫자(실수) 인지 확인
int isNumber(char *str)
{
	char *ep = NULL;
	double f = strtod(str, &ep);
	if (!ep || *ep) return FALSE;  // 숫자 아님

	return TRUE; // 숫자 맞음!
}

// infix expr 의 토큰 분리
void exprTokenizer(char *expr, Queue *tokQueue)
{
	char *delim = " \t";  // delimeter 는 공백과 탭

	char pBuf[MAX_TOKEN_LENGTH];   // 토큰 문자열 담을 버퍼

	char *ptr = strtok(expr, delim);
	while (ptr != NULL) 
	{
		queue_enq(tokQueue, ptr);
		ptr = strtok(NULL, delim);
	}
}

// infix 로 된 tokQueue 에서 postfix 방식으로 변환하여 postQueue 로 입력
void InfixToPostfix(Queue *tokQueue, Queue *postQueue)
{
	char token[MAX_TOKEN_LENGTH];
	char pTopBuf[MAX_TOKEN_LENGTH];  // 스택의 top 이 가리키는 데이터(토큰)담을 버퍼

	Stack opStack;  // operator 스택
	stack_init(&opStack);

	while (!queue_is_empty(tokQueue))
	{
		queue_deq(tokQueue, token);

		// token 이 operand(숫자)이면 큐(postQueue)에 넣기
		if (isNumber(token))
		{
			queue_enq(postQueue, token);   // 큐에 넣기
		}
		else
		{  // 숫자 아니면?  연산자 or 괄호
			char op = token[0];   // 연산자 추출 (※ 전제: 연산자는 모두 한글자)
			switch (op)
			{
			// 1. 연산자
			case '+':
			case '-':
			case '*':
			case '/':
				// stack 을 peek 하여
				// 자신(op) 보다 우선순위가 같거나 큰 연산자라면 pop 하여 queue에 넣기
				while (stack_peek(&opStack, pTopBuf))  // pop 하지 않고 일단 들여다 봄
				{
					if (0 > compOp(pTopBuf, token))  // pTopBuf의 우선순위가 token보다 작으면
						break;

					// 만약 우선순위가 같거나 크다면?
					stack_pop(&opStack, pTopBuf);  // pop 해서
					queue_enque(postQueue, pTopBuf);   // enqueue 하기
				}

				stack_push(&opStack, token);  // 최종적으로 자기 자신을 push

				break;

			// 2. 여는 괄호
			case '(':
			case '[':
			case '{':
				
				// TODO 

				break;

			// 3. 닫는 괄호
			case ')':
				break;
			case ']':
				break;
			case '}':
				break;
			}
		}



		//printf("%s\n", token);  // 테스트용
	}


	stack_destroy(&opStack);
}


// infix expr 연산식 문자열을 받아서 evaluate 한 결과값 리턴
double calcExpr(char *expr)
{
	Queue tokQueue;   // expr 에서 추출한 token 들을 담을 큐
	Queue postQueue;    // postfix expr로 변환되 token 들을 담을 큐
	Stack opStack;      // operator 스택, evaluation 용

	double result = 0; // 수식 연산 결과값

	queue_init(&tokQueue);
	queue_init(&postQueue);
	stack_init(&opStack);


	// 1. infix expr 문자열 --> 토큰분리 (tokQueue)
	exprTokenizer(expr, &tokQueue);

	// 2. infix 토큰(tokQueue) --> postfix 토큰 (postQueue)  (shunting yard algorithm 사용)
	InfixToPostfix(&tokQueue, &postQueue);

	// 3. postfix 토큰(postQueue) --> evaluate 계산 (result)


	stack_destroy(&opStack);
	queue_destroy(&postQueue);
	queue_destroy(&tokQueue);

	return result;  // 수식 결과값
}

int main(int argc, char** argv)
{
	// 테스트용 infix 수식

	char test_expr[][MAX_EXPR_LENGTH] = {
		"1 - ( 2 + 3 ( 4 - 5 * 6 ) * 7 ) + 8 * 9"
	};


	printf("결과 %.2f\n", calcExpr(test_expr[0]));


	printf("\n아무키나 입력하시면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()




/*
	{   // 문자열 스택 테스트
		//Stack stk;
		//stack_init(&stk);

		//stack_push(&stk, "hello");
		//stack_push(&stk, "123.4");
		//stack_push(&stk, "+");
		//stack_push(&stk, "=");
		//stack_push(&stk, "400");
		//stack_push(&stk, ")");

		//Data data[100];

		//while (!stack_is_empty(&stk))
		//{
		//	stack_pop(&stk, data);  printf("pop--> %s\n", data);
		//}

		//stack_destroy(&stk);
	}

	{  // 문자열 큐 테스트
		//Queue q;
		//queue_init(&q);

		//queue_enq(&q, "123");
		//queue_enq(&q, "+");
		//queue_enq(&q, "3.14");
		//queue_enq(&q, "*");
		//queue_enq(&q, "789");

		//Data data[100];
		//while(!queue_is_empty(&q))
		//{
		//	queue_deq(&q, data);  printf("deq --> %s\n", data);
		//}


		//queue_destroy(&q);
	}

*/

//{
//	char str[40] = "This is C ds";
//	printf("str[] = %s\n", str);

//	char *delim = " ";  // delimeter 구분자

//	char* ptr = strtok(str, delim);
//	while (ptr != NULL)
//	{
//		printf("%s\n", ptr);  // 토큰 출력
//		ptr = strtok(NULL, delim);
//	}

//}