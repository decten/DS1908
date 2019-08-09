#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환함수..
#include <string.h>   // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>    // _getch, putch  .. MS기반 C 비표준 함수
#include <time.h>     // clock .. 시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등  전통 C 함수 에러 
#pragma warning(disable:4477)   // unsigned <--> signed 관련 에러

/*
	구조체
*/

int main(int argc, char** argv)
{
	{
		struct Student   // Student 라는 구조체 정의
		{
			int age;        // 멤버변수 2개 
			char gender;
		};

		// Student 구조체 타입 변수 선언
		struct Student stu1;
		// 구조체 멤버 사용 : 멤버 접근연산자 (member access operator)  . 사용
		stu1.age = 15;
		stu1.gender = 'F';

		// 구조체 에 대한 포인터
		struct Student *pStu;
		pStu = &stu1;

		printf("age : %d, gender : %c \n", stu1.age, stu1.gender);
		printf("age : %d, gender : %c \n", (*pStu).age, (*pStu).gender);
		printf("age : %d, gender : %c \n", pStu->age, pStu->gender);
		   // 구조체 포인터는 -> 를 사용해서 멤버 사용 ㅊㅊ!
	}

	{
		typedef unsigned int UINT;  // typdef 를 사용해서 새로운 타입이름 정의
		UINT a, b, c;

		// typdef 구조체정의 새이름;
		typedef struct _Student
		{
			int age;
			char gender;
		} Student;

		Student stu1;   // typdef 으로 정의된 타입이름으로 편리하게 사용



	}



	printf("\n아무키나 입력하시면 프로그램 종료됩니다\n");
	_getch();
	return 0;
} // end main()