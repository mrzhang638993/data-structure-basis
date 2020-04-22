#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int a;
	struct Node* pNext;
};
//  头指针和尾部指针的定义
struct Node* g_pHead=NULL;
struct Node* g_pEnd=NULL;

//  函数声明
struct Node* createNode(int a);
void   addListTail(int a);
void   initListHeader();
void   scanForList();
struct Node* queryNodesByValue(int value);
void   randomAddElement(int index, int a);
void   deleteHeadNode();
void   deleteRandomNode(int a);
void   deleteTailNode();

// 尾部添加,给链表的尾部增加元素
void  addListTail(int a)
{
	struct Node* newNode = createNode(a);
	if (NULL==newNode)
	{
		printf("内存申请失败，内存不足");
		return;
	}
	g_pEnd->pNext = newNode;
   g_pEnd = newNode;
   //if (g_pEnd==NULL)  //  没有尾部元素的话，增加尾部元素
   //{
	  // g_pEnd = newNode;
	  // g_pHead->pNext = newNode;
   //}
   //else  //已经有了尾部元素的话
   //{
	  //
   //}
}
//  头部元素添加
void addListHead(int a )
{
	 //  增加头部节点，对应的链接的是头结点的下一个节点的。
	struct Node* newNode = createNode(a);
	if (NULL == newNode)
	{
		printf("内存申请失败，内存不足");
		return;
	}
	newNode->pNext = g_pHead->pNext;
	g_pHead->pNext = newNode;
}
//  初始化头部操作
void initListHeader()
{
	//  链表空头,什么数据都没有的
	g_pHead = (struct Node*)malloc(sizeof(struct Node));  //  头部的初始化很重要的
	if (NULL == g_pHead)
	{
		printf("内存申请失败，内存不足");
		return;
	}
	g_pHead->pNext = NULL;
	// 可以直接对尾部节点进行初始化的
	g_pEnd = g_pHead;
}
struct Node*  createNode(int a)
{
	//  内存申请，对应的是需要判断是否成功的
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (NULL==newNode)  //  后续的空间申请失败处理的
	{
		printf("空间申请失败");
	}
	newNode->a = a;
	newNode->pNext = NULL;  //  建议初始化操作，初始化很重要的。
	return newNode;
}
//  链表的遍历,需要注意的是不要动头指针的
void  scanForList()
{
	struct Node* newNode = g_pHead->pNext;  // 这样的才是遍历的起点的，不要使用g_pHead
	while (NULL!= newNode)
	{
		printf("%d\n", newNode->a);
		newNode = newNode->pNext;
	}
}
//   任意位置增加元素
void   randomAddElement(int index,int a)
{
	if (g_pHead->pNext == NULL)  //  对应的是一个空的链表，没有链表数据
	{
		struct Node* newNode=createNode(a);
		if (NULL==newNode)
		{
		   printf("分配内存空间失败，内存不足");
		   return;
		}
		g_pHead->pNext = newNode;
		g_pEnd = newNode;
	}
	else
	{
		//  查询元素index是否存在
		struct Node* nodeValues = queryNodesByValue(index);
		if (NULL == nodeValues)
		{
			printf("查无此节点");
			return;
		}
		//  找到元素的话，需要涉及到元素的位置的。
		if (nodeValues == g_pEnd)
		{
			// 尾部节点，对应的执行尾部节点的操作的。
			addListTail(a);  //  
		}
		else
		{
			//  中间元素的增加操作,对应的在原来的元素后面增加元素的。
			struct Node* newNode = createNode(a);
			if (NULL == newNode)
			{
				printf("分配内存空间失败，内存不足");
				return;
			}
			newNode->pNext = nodeValues->pNext;
			nodeValues->pNext = newNode;
		}
	}
}
//  查找元素的位置,没有的话，对应的返回的是NULL空间的地址的
struct Node* queryNodesByValue(int value)
{
	if (g_pHead==g_pEnd) //  空链表的话就不用吃找了
	{
		printf("空的链表，不用查找了");
		return NULL;
	}
	struct Node* newNode = g_pHead->pNext;
	while (newNode!=NULL)
	{
		if (newNode->a == value)
		{
			return newNode;
		}
		newNode = newNode->pNext;
	}
	return NULL;
}
//  删除头结点
void  deleteHeadNode()
{
	//  删除节点的时候，一定要记忆节点的，不要直接删除节点的。
	//  删除头结点
	struct Node* newNode = g_pHead->pNext; //  头结点元素
	//  需要判断是否是只有一个元素的。
	//  只有一个头结点的，肯定是找不到元素的。
	if (g_pHead==g_pEnd)  //  只有一个元素
	{
		printf("链表为空，不需要删除头元素的");
		return;
	}
	else if (g_pHead->pNext==g_pEnd) //  对应的只有一个元素节点
	{
		free(newNode);
		g_pHead->pNext = NULL;
		g_pEnd = g_pHead;
		return;
	}
	else
	{
		g_pHead->pNext = newNode->pNext;
		free(newNode);
		return;
	}
}
//  删除任意节点
void deleteRandomNode(int a)
{
	//  判断链表不存在节点的话，不需要进行删除的
	if (g_pHead == g_pEnd)  //  只有一个元素
	{
		printf("链表为空，不需要删除头元素的");
		return;
	}
	struct Node*  node=queryNodesByValue(a);
	if (!node)
	{
		printf("节点不存在,不需要删除的");
		return;
	}
	//  节点存在，需要判断。
	//  如果是头结点的话，处理如下的
	if (g_pHead->pNext == node)
	{
		deleteHeadNode();
	}
	else if(node->pNext==NULL)  //  尾结点的话，删除尾部节点的
	{
		deleteTailNode(node);
	}
	else  //  存在的是多个节点的,删除中间的节点的。
	{
		struct Node* newNode = g_pHead->pNext;
		while (newNode)  // 查找链表的元素的
		{
			if (newNode->pNext == node)  //  前面的一个节点的
			{
				newNode->pNext = node->pNext;
				free(node);
				return;
			}
			newNode = newNode->pNext;
		}
	}
}
//  删除尾部节点
void deleteTailNode(struct Node* newNode1)
{
	// 对应的是空链的操作的
	if (!g_pHead->pNext && !g_pEnd->pNext)
	{
		printf("空链,不需要删除");
		return;
	}
	//  只有一个节点的情况需要进行如下的处理的。删除了节点的话，对应的就只剩下头结点了
	if (g_pHead->pNext== newNode1)
	{
		g_pHead->pNext = NULL;
		g_pEnd = g_pHead;
		free(newNode1);
		return;
	}
	//  存在多个节点的情况下。
	struct Node* newNode = g_pHead->pNext;
	while (newNode)  // 查找链表的元素的
	{
		if (newNode->pNext==g_pEnd)  //  前面的一个节点的
		{
			free(g_pEnd);
			newNode->pNext = NULL;
			g_pEnd = newNode;
			return;
		}
		newNode = newNode->pNext;
	}
}
//  释放所有的链表
void   freeAllList()
{
	// 节点只有一个头元素的情况下释放的
	if (g_pHead->pNext==NULL)
	{
		free(g_pHead);
	}
	struct Node* node = g_pHead->pNext;
	while (node)  //  节点不为空的情况下，可以删除节点元素
	{
		struct Node*  node1=node->pNext;
		free(node);
		g_pHead->pNext = node1;
		node = node1;
	}
	free(g_pHead);
}

int  main(void)
{
	initListHeader();
	addListTail(10);
	addListTail(20);
	addListTail(30);
	addListTail(40);
	scanForList();
	randomAddElement(20,100);
	deleteHeadNode();  //  删除头结点
	deleteRandomNode(10);
	freeAllList();
	system("pause");
	return 0;
}