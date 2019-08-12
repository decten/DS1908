#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
/*
	ArrayList �� ADT
*/

#define SUCCESS 1
#define FAIL 0

/* ArrayList �� ������ ���� */
#define LIST_LEN  4

typedef int Data;    // �����ʹ� int

typedef struct _ArrayList
{
	Data arr[LIST_LEN];  // ������(��), �迭�� ����
	int numData;        // ����Ʈ ���� ������ ����
	int curPosition;    // iteration
} ArrayList;

typedef ArrayList List;


/* ArrayList �� ���� */
void list_init(List *pList);   // ����Ʈ �ʱ�ȭ
void list_destroy(List *pList);// ����Ʈ ����

int list_add(List *pList, Data data);// ������ �߰�
int list_remove(List *pList, int n);// ������ ���� : n��° ������
int list_set(List *pList, int n, Data data);// ������ ����
int list_length(List *pList);// ������ ����

int list_get(List *pList, int n, Data *pData);// ������ ��ȸ : n��° ������

void list_init_iter(List *pList);// iteration : �ʱ�ȭ
Data list_next(List *pList);// iteration : ���� ������ ����
int list_hasNext(List *pList);// iteration : ���� ������ ����


int list_insert(List* pList, int n, Data data);   // ������ ����: n��° ��ġ�� ������ ����

#endif