#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ�Լ�..
#include <string.h>   // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>    // _getch, putch  .. MS��� C ��ǥ�� �Լ�
#include <time.h>     // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() ��  ���� C �Լ� ���� 
#pragma warning(disable:4477)   // unsigned <--> signed ���� ����

#include "ListBaseStack.h"
#include "ListQueue.h"

// �������� 
#define MAX_EXPR_LENGTH 100      // ���� �ϳ��� �ִ� ���ڿ� ����
#define MAX_TOKEN_LENGTH 10      // ��ū �Ѱ��� ������ �ִ� �ִ� ���ڿ� ����

#define TRUE 1
#define FALSE 0

// ������ �켱����(precedence) ����
// + - * /
int PRECED_PLUS = 2;
int PRECED_MINUS = 2;
int PRECED_MUL = 3;   // +, - ���ٴ� �켱���� ������ ��
int PRECED_DIV = 3;

// ������ �켱���� ����
int getPreced(char *op)
{
	if(!strcmp("+", op)) return PRECED_PLUS;
	if(!strcmp("-", op)) return PRECED_MINUS;
	if(!strcmp("*", op)) return PRECED_MUL;
	if(!strcmp("/", op)) return PRECED_DIV;
	return 0;
}

// ������ �켱���� ��
//  ���ϰ�:  0 -> ����,   ���� -> op1 < op2,  ��� -> op1 > op2
int compOp(char *op1, char *op2)
{
	return getPreced(op1) - getPreced(op2);
}

// �־��� ���ڿ��� ����(�Ǽ�) ���� Ȯ��
int isNumber(char *str)
{
	char *ep = NULL;
	double f = strtod(str, &ep);
	if (!ep || *ep) return FALSE;  // ���� �ƴ�

	return TRUE; // ���� ����!
}

// infix expr �� ��ū �и�
void exprTokenizer(char *expr, Queue *tokQueue)
{
	char *delim = " \t";  // delimeter �� ����� ��

	char pBuf[MAX_TOKEN_LENGTH];   // ��ū ���ڿ� ���� ����

	char *ptr = strtok(expr, delim);
	while (ptr != NULL) 
	{
		queue_enq(tokQueue, ptr);
		ptr = strtok(NULL, delim);
	}
}

// infix �� �� tokQueue ���� postfix ������� ��ȯ�Ͽ� postQueue �� �Է�
void InfixToPostfix(Queue *tokQueue, Queue *postQueue)
{
	char token[MAX_TOKEN_LENGTH];
	char pTopBuf[MAX_TOKEN_LENGTH];  // ������ top �� ����Ű�� ������(��ū)���� ����

	Stack opStack;  // operator ����
	stack_init(&opStack);

	while (!queue_is_empty(tokQueue))
	{
		queue_deq(tokQueue, token);

		// token �� operand(����)�̸� ť(postQueue)�� �ֱ�
		if (isNumber(token))
		{
			queue_enq(postQueue, token);   // ť�� �ֱ�
		}
		else
		{  // ���� �ƴϸ�?  ������ or ��ȣ
			char op = token[0];   // ������ ���� (�� ����: �����ڴ� ��� �ѱ���)
			switch (op)
			{
			// 1. ������
			case '+':
			case '-':
			case '*':
			case '/':
				// stack �� peek �Ͽ�
				// �ڽ�(op) ���� �켱������ ���ų� ū �����ڶ�� pop �Ͽ� queue�� �ֱ�
				while (stack_peek(&opStack, pTopBuf))  // pop ���� �ʰ� �ϴ� �鿩�� ��
				{
					if (0 > compOp(pTopBuf, token))  // pTopBuf�� �켱������ token���� ������
						break;

					// ���� �켱������ ���ų� ũ�ٸ�?
					stack_pop(&opStack, pTopBuf);  // pop �ؼ�
					queue_enque(postQueue, pTopBuf);   // enqueue �ϱ�
				}

				stack_push(&opStack, token);  // ���������� �ڱ� �ڽ��� push

				break;

			// 2. ���� ��ȣ
			case '(':
			case '[':
			case '{':
				
				// TODO 

				break;

			// 3. �ݴ� ��ȣ
			case ')':
				break;
			case ']':
				break;
			case '}':
				break;
			}
		}



		//printf("%s\n", token);  // �׽�Ʈ��
	}


	stack_destroy(&opStack);
}


// infix expr ����� ���ڿ��� �޾Ƽ� evaluate �� ����� ����
double calcExpr(char *expr)
{
	Queue tokQueue;   // expr ���� ������ token ���� ���� ť
	Queue postQueue;    // postfix expr�� ��ȯ�� token ���� ���� ť
	Stack opStack;      // operator ����, evaluation ��

	double result = 0; // ���� ���� �����

	queue_init(&tokQueue);
	queue_init(&postQueue);
	stack_init(&opStack);


	// 1. infix expr ���ڿ� --> ��ū�и� (tokQueue)
	exprTokenizer(expr, &tokQueue);

	// 2. infix ��ū(tokQueue) --> postfix ��ū (postQueue)  (shunting yard algorithm ���)
	InfixToPostfix(&tokQueue, &postQueue);

	// 3. postfix ��ū(postQueue) --> evaluate ��� (result)


	stack_destroy(&opStack);
	queue_destroy(&postQueue);
	queue_destroy(&tokQueue);

	return result;  // ���� �����
}

int main(int argc, char** argv)
{
	// �׽�Ʈ�� infix ����

	char test_expr[][MAX_EXPR_LENGTH] = {
		"1 - ( 2 + 3 ( 4 - 5 * 6 ) * 7 ) + 8 * 9"
	};


	printf("��� %.2f\n", calcExpr(test_expr[0]));


	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()




/*
	{   // ���ڿ� ���� �׽�Ʈ
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

	{  // ���ڿ� ť �׽�Ʈ
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

//	char *delim = " ";  // delimeter ������

//	char* ptr = strtok(str, delim);
//	while (ptr != NULL)
//	{
//		printf("%s\n", ptr);  // ��ū ���
//		ptr = strtok(NULL, delim);
//	}

//}