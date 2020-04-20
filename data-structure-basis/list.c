#include <stdio.h>
#include <stdlib.h>

struct  Node
{
	int a;
	struct Node* pNext;  // 指向下一个结构体的指针
};
//  初始化头节点指针和尾节点指针
struct  Node *  headNode=NULL; 
struct  Node *  tailNode=NULL;
//  初始化链表,创建链表的方式包括头部添加和尾部添加的
void  tailInsertToList(int a )
{
	//  创建一个节点,作为头指针指向的第一个节点的
	struct  Node* node = (struct  Node*)malloc(sizeof(struct  Node));
	node->a = a;
	node->pNext = NULL;  // 一定要赋值为NULL，否则的话，对应的会出现越界的情况的。
	//  链表增加节点的操作，需要进行逻辑判断
	if (!headNode && !tailNode)  //  什么都没有的空链表的,头指针和尾指针都指向这个节点的
	{
		// 对用的需要初始化相关的node节点的,头节点和尾节点对应的都是第一个节点的
		headNode = node;
		tailNode = node;
	}
	else  //  新的节点对应的加入到尾节点上的,对应的指向的是尾节点的。
	{
		//  对应的采用的是尾部添加的，对应的是队列的。
		tailNode->pNext = node;
		tailNode = node;
	}
}
//头部添加元素
void  headInsertToList(int a)
{
	//  创建一个节点,作为头指针指向的第一个节点的
	struct  Node* node = (struct  Node*)malloc(sizeof(struct  Node));
	node->a = a;
	node->pNext = NULL;  // 一定要赋值为NULL，否则的话，对应的会出现越界的情况的。
	//  链表增加节点的操作，需要进行逻辑判断
	if (!headNode && !tailNode)  //  什么都没有的空链表的,头指针和尾指针都指向这个节点的
	{
		// 对用的需要初始化相关的node节点的,头节点和尾节点对应的都是第一个节点的
		headNode = node;
		tailNode = node;
	}
	else  //  新的节点对应的加入到尾节点上的,对应的指向的是尾节点的。
	{
		//  对应的采用的是头部添加的，对应的是栈操作的。
		node->pNext = headNode;
		headNode = node;
	}
}

int  main(void)
{
	//initList(1);
	//initList(2);
	//initList(3);
	//initList(4);
	//initList(5);
	//  下面使用数组数据来测试链表数据
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		headInsertToList(a[i]);
	}
	system("pause");
	return 0;
}