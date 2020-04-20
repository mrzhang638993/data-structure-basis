#include <stdio.h>
#include <stdlib.h>
//  0xcdcdcdcd  对应的是野指针的，需要特别的敏感，是否忘记初始化元素了
struct  Node
{
	int a;
	struct Node* pNext;  // 指向下一个结构体的指针
};
//  初始化头节点指针和尾节点指针
struct  Node *  headNode=NULL; 
struct  Node *  tailNode=NULL;

//  函数声明
void  tailInsertToList(int a);
void  headInsertToList(int a);
void  scanList();
struct  Node* selectNode(int a);
void  freeList();
void  freePartialList(int a);
void  insertElementByIndexBefore(int index, int a);
void  insertElementByIndexAfter(int index, int a);
void  deleteListHead();
void  deleteTailList();
void  deleteElementsByValue(int value);


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
//链表的遍历操作,全表的遍历操作
void  scanList()
{
	struct  Node* node = headNode; // 对应的是头节点的指针的。
	//  遍历的过程中，头指针是不能变化的
	while (node)  // 最后的一个节点的尾指针对应的是NULL的
	{
		printf("%d\n", node->a);
		node = node->pNext;
	}
}
//  查询指定的节点,查询数据传递为a
struct  Node* selectNode(int a)
{
	struct  Node* node = headNode; // 对应的是头节点的指针的。
	while (node)  // 最后的一个节点的尾指针对应的是NULL的
	{
		if (a==node->a)
		{
			return node;
		}
		node = node->pNext;
	}
	return NULL;
}
//  链表删除和释放:下面释放的是全部的链表
void  freeList()
{
	struct  Node* node = headNode;
	struct  Node* node1 = NULL;
	while (node)
	{
		//  释放当前的节点，节点往后移动
		node1 = node->pNext;
		free(node);
		node = node1;
	}
	//  头节点和尾节点全部设置为NULL
	headNode = NULL;
	tailNode = NULL;
}
//  释放部分链表，根据条件释放
void  freePartialList(int a)
{
	struct  Node* node = headNode; // 对应的是头节点的指针的。
	while (node)  // 最后的一个节点的尾指针对应的是NULL的
	{
		if (a == node->a)
		{
			//  节点的群面一个节点之后他后续的节点的，需要判断位置
			if (node == headNode)
			{
				//  头节点指针
				headNode = node->pNext;
				free(node);
				return;
			}
			else if (node == tailNode)
			{
				//  释放尾节点，需要向前移动尾部指针
				tailNode = (--node);
				free(node);
				return;
			}
			else
			{
				struct  Node* node2 = headNode;
				while (node2)
				{
					if (node2->pNext == node) {
						node2->pNext = node->pNext;
						free(node);
						return;
					}
					node2 = node2->pNext;
				}
			}
		}
		// 节点已经释放了，后续的pNext就没什么意义了
		node = node->pNext;
	}
}
//  在指定的位置前面插入元素
void insertElementByIndexBefore(int index, int a)
{
	if (headNode==NULL) //  插入的是首节点的信息
	{
		struct  Node* node = (struct  Node*)malloc(sizeof(struct  Node));
		node->a = a;
		node->pNext = NULL;
		headNode = node;
		tailNode = node;
	}
	struct  Node*  nodeResult=selectNode(index);
	if (!nodeResult)
	{
		printf("对应的节点不存在");
	}
	//  节点存在，需要创建节点，在找到的位置增加一个节点
	struct  Node*  newNode= (struct  Node*)malloc(sizeof(struct  Node));
	newNode->a = a;
	//  问题：找到的是第一个节点的话，对应的需要处理
	if (nodeResult == headNode)
	{
		newNode->pNext = nodeResult;
		headNode = newNode;
	}
	else
	{
		//  链表的存储空间是随机的
		struct  Node* node2 = headNode;
		while (node2)
		{
			if (node2->pNext == nodeResult) {
				node2->pNext = newNode;
				newNode->pNext = nodeResult;
				return;
			}
			node2 = node2->pNext;
		}
	}
}
//  在指定的位置后面插入元素
void insertElementByIndexAfter(int index, int a)
{
	if (headNode == NULL) //  插入的是首节点的信息
	{
		struct  Node* node = (struct  Node*)malloc(sizeof(struct  Node));
		node->a = a;
		node->pNext = NULL;
		headNode = node;
		tailNode = node;
	}
	struct  Node* nodeResult = selectNode(index);
	if (!nodeResult)
	{
		printf("对应的节点不存在");
	}
	//  节点存在，需要创建节点，在找到的位置增加一个节点
	struct  Node* newNode = (struct  Node*)malloc(sizeof(struct  Node));
	newNode->a = a;
	//  问题：找到的是尾节点的话，怎么处理
	if (nodeResult == tailNode)
	{
		nodeResult->pNext = newNode;
		tailNode = newNode;
	}
	else
	{
		//  不是尾节点的话，直接在节点后面增加即可的
		struct  Node*   beforeNode=nodeResult->pNext;
		nodeResult->pNext = newNode;
		newNode->pNext = beforeNode;
	}
}
//头节点删除操作
void   deleteListHead()
{
	//  释放头节点，需要判断，假设只有一个节点，头节点对应的也是尾节点。
	if (!headNode)
	{
		printf("链表为空，不需要进行释放");
		return;
	}
	if (!headNode->pNext) //  只有一个节点
	{
		free(headNode);
		return;
	}
	struct  Node* node = headNode;
	headNode = node->pNext;
	free(node);
}
//  执行尾删除操作
void deleteTailList()
{
	if (!tailNode)  // 对应的尾节点不存在
	{
		printf("链表为空，不需要进行删除操作");
		return;
	}
	if (headNode == tailNode) //  链表只存在一个元素的话，可以直接删除的
	{
		free(tailNode);
		headNode = NULL;
		tailNode = NULL;
		return;
	}
	//  链表存在多个节点的话，尾节点的前面一个节点作为尾节点的。
	struct  Node* node2 = headNode; 
	while (node2)
	{
		if (node2->pNext == tailNode)
		{
			struct  Node* endNode = tailNode;
			tailNode = node2;
			free(endNode);
			tailNode->pNext = NULL; //  需要注意的，这个很关键
			return;
		}
		node2 = node2->pNext;
	}
}
//  删除指定的节点,根据value实现删除操作
void  deleteElementsByValue(int value)
{
	if (!headNode)
	{
		printf("链表为空，不需要进行删除");
		return;
	}
	struct  Node* nodeResult = selectNode(value);
	if (!nodeResult)
	{
		printf("元素不存在,请勿删除");
		return;
	}
	//  元素存在，执行删除操作
	//  只有一个元素的话，
	if (headNode==tailNode)

	{
		free(nodeResult);
		headNode = NULL;
		tailNode = NULL;
		return;
	}
	// 有两个节点的,一个头节点,一个尾部节点
	if (headNode->pNext== tailNode)
	{
		//  需要判断,找到的是头结点还是尾部节点的
		if (nodeResult== headNode)
		{
			deleteListHead();
			return;
		}
		else
		{
			deleteTailList();
			return;
		}
	}
	//  存在多个元素的话，执行的是如下的操作的.假设找到的是头节点还是尾部节点的
	if (nodeResult == headNode)
	{
		deleteListHead();
		return;
	}
	if (nodeResult==tailNode)
	{
		deleteTailList();
		return;
	}
	struct  Node* node2 = headNode;
	while (node2)
	{
		if (node2->pNext == nodeResult)
		{
			node2->pNext = nodeResult->pNext;
			free(nodeResult);
			return;
		}
		node2 = node2->pNext;
	}
}
//栈:头添加+头删除
//队列:头添加+尾删除，尾添加+头删除
//删除指定节点
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
	//scanList();
	/*struct  Node*  resultNode=selectNode(20);
	if (resultNode)
	{
		printf("%d\n", resultNode->a);
	}
	else
	{
		printf("该节点不存在");
	}*/
	//  空间释放操作
	//freeList();
	//freePartialList(8);
	//insertElementByIndex(8, 12);
	//insertElementByIndexAfter(8, 12);
	/*deleteListHead();
	deleteListHead();
	deleteListHead();
	deleteTailList();
	deleteTailList();
	deleteTailList();
	deleteTailList();
	deleteTailList();*/
	//deleteElementsByValue(8);
	//deleteElementsByValue(1);
	deleteElementsByValue(10);
	system("pause");
	return 0;
}