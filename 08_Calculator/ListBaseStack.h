#ifndef __STACK_H__
#define __STACK_H__

#define SUCCESS 1
#define FAIL 0

/* 스택의 Adt */

/* 스택의 데이터 */
#ifndef __NODE_DATA__
#define __NODE_DATA__
typedef char Data;     

typedef struct _node
{
	Data *str;   // 문자열 (동적메모리)
	struct _node *pNext;
} Node;
#endif

typedef struct _listStack
{
	Node *pTop; // ※ 이번예제에서는 numData 유지 안함
} ListStack;

typedef ListStack Stack;

/* 스택의 동작 */
void stack_init(Stack *pStack);    // 스택 초기화
void stack_destroy(Stack *pStack);  // 스택 제거

int stack_is_empty(Stack *pStack);// 스택이 비었는지 확인

int stack_push(Stack *pStack, Data *pData);// top 에 데이터 추가 (push)
int stack_pop(Stack *pStack, Data *pData);// top 의 데이터 꺼내기 (pop)
int stack_peek(Stack *pStack, Data *pData);// top 의 데이터 미리보기 (peek)

#endif
