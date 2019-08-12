#include <stdio.h>
#include <stdlib.h>   // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ�Լ�..
#include <string.h>   // memcpy, strcpy  �޸𸮺���, ���ڿ� �Լ�
#include <conio.h>    // _getch, putch  .. MS��� C ��ǥ�� �Լ�
#include <time.h>     // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() ��  ���� C �Լ� ���� 
#pragma warning(disable:4477)   // unsigned <--> signed ���� ����
#include "ArrayList.h"

/*
	ArrayList �� ����
		: �˻� �ӵ� ������.  ex) n��° ������ ����!

	ArrayList �� ����
		: ���� �ӵ� ����.
		: ���� �ӵ� ����.
*/


// ����Ʈ ��� ����� �Լ�
void printList(List *pList)
{
	list_init_iter(pList);   // iteration �ʱ�ȭ
	printf("[");
	while (list_hasNext(pList))
	{
		printf("%d ", list_next(pList));
	}

	printf("]\n");
}

int main(int argc, char** argv)
{
	List myList;   // ArrayList ���� ����

	list_init(&myList);  // ����Ʈ �ʱ�ȭ
	printList(&myList);
	
	list_add(&myList, 100);  // ������ �߰�
	printList(&myList);
	list_add(&myList, 50);  // ������ �߰�
	printList(&myList);
	list_add(&myList, 100);  // ������ �߰�
	printList(&myList);
	list_add(&myList, 20);  // ������ �߰�
	printList(&myList);
	
	list_add(&myList, 45);  // ������ �߰� - ����

	// ������ ����
	list_set(&myList, 0, 40);
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 30);  // ����
	printList(&myList);

	// ������ ����
	printf("������ ������ %d\n", list_length(&myList));

	// ������ ��ȸ
	Data data;
	if (list_get(&myList, 0, &data)) printf("0��°: %d\n", data);
	if (list_get(&myList, 6, &data)) printf("6��°: %d\n", data);
	if (list_get(&myList, 2, &data)) printf("2��°: %d\n", data);

	// ������ ����
	list_remove(&myList, 2);
	printList(&myList);
	list_remove(&myList, 2);
	printList(&myList);
	list_remove(&myList, 0);
	printList(&myList);
	list_remove(&myList, 0);
	printList(&myList);
	list_remove(&myList, 0);
	printList(&myList);

	// insert �׽�Ʈ
	printf("\n");
	list_add(&myList, 10);
	list_add(&myList, 20);
	printList(&myList);
	list_insert(&myList, 1, 40);
	printList(&myList);   // 10 40 20
	list_insert(&myList, 0, 5);
	printList(&myList);   // 5 10 40 20
	list_insert(&myList, 0, 5);  // ����

	list_destroy(&myList);  // ����Ʈ ����


	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
} // end main()