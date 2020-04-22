#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int a;
	struct Node* pNext;
};
//  ͷָ���β��ָ��Ķ���
struct Node* g_pHead=NULL;
struct Node* g_pEnd=NULL;

//  ��������
struct Node* createNode(int a);
void   addListTail(int a);
void   initListHeader();
void   scanForList();
struct Node* queryNodesByValue(int value);
void   randomAddElement(int index, int a);
void   deleteHeadNode();
void   deleteRandomNode(int a);
void   deleteTailNode();

// β�����,�������β������Ԫ��
void  addListTail(int a)
{
	struct Node* newNode = createNode(a);
	if (NULL==newNode)
	{
		printf("�ڴ�����ʧ�ܣ��ڴ治��");
		return;
	}
	g_pEnd->pNext = newNode;
   g_pEnd = newNode;
   //if (g_pEnd==NULL)  //  û��β��Ԫ�صĻ�������β��Ԫ��
   //{
	  // g_pEnd = newNode;
	  // g_pHead->pNext = newNode;
   //}
   //else  //�Ѿ�����β��Ԫ�صĻ�
   //{
	  //
   //}
}
//  ͷ��Ԫ�����
void addListHead(int a )
{
	 //  ����ͷ���ڵ㣬��Ӧ�����ӵ���ͷ������һ���ڵ�ġ�
	struct Node* newNode = createNode(a);
	if (NULL == newNode)
	{
		printf("�ڴ�����ʧ�ܣ��ڴ治��");
		return;
	}
	newNode->pNext = g_pHead->pNext;
	g_pHead->pNext = newNode;
}
//  ��ʼ��ͷ������
void initListHeader()
{
	//  �����ͷ,ʲô���ݶ�û�е�
	g_pHead = (struct Node*)malloc(sizeof(struct Node));  //  ͷ���ĳ�ʼ������Ҫ��
	if (NULL == g_pHead)
	{
		printf("�ڴ�����ʧ�ܣ��ڴ治��");
		return;
	}
	g_pHead->pNext = NULL;
	// ����ֱ�Ӷ�β���ڵ���г�ʼ����
	g_pEnd = g_pHead;
}
struct Node*  createNode(int a)
{
	//  �ڴ����룬��Ӧ������Ҫ�ж��Ƿ�ɹ���
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (NULL==newNode)  //  �����Ŀռ�����ʧ�ܴ����
	{
		printf("�ռ�����ʧ��");
	}
	newNode->a = a;
	newNode->pNext = NULL;  //  �����ʼ����������ʼ������Ҫ�ġ�
	return newNode;
}
//  ����ı���,��Ҫע����ǲ�Ҫ��ͷָ���
void  scanForList()
{
	struct Node* newNode = g_pHead->pNext;  // �����Ĳ��Ǳ��������ģ���Ҫʹ��g_pHead
	while (NULL!= newNode)
	{
		printf("%d\n", newNode->a);
		newNode = newNode->pNext;
	}
}
//   ����λ������Ԫ��
void   randomAddElement(int index,int a)
{
	if (g_pHead->pNext == NULL)  //  ��Ӧ����һ���յ�����û����������
	{
		struct Node* newNode=createNode(a);
		if (NULL==newNode)
		{
		   printf("�����ڴ�ռ�ʧ�ܣ��ڴ治��");
		   return;
		}
		g_pHead->pNext = newNode;
		g_pEnd = newNode;
	}
	else
	{
		//  ��ѯԪ��index�Ƿ����
		struct Node* nodeValues = queryNodesByValue(index);
		if (NULL == nodeValues)
		{
			printf("���޴˽ڵ�");
			return;
		}
		//  �ҵ�Ԫ�صĻ�����Ҫ�漰��Ԫ�ص�λ�õġ�
		if (nodeValues == g_pEnd)
		{
			// β���ڵ㣬��Ӧ��ִ��β���ڵ�Ĳ����ġ�
			addListTail(a);  //  
		}
		else
		{
			//  �м�Ԫ�ص����Ӳ���,��Ӧ����ԭ����Ԫ�غ�������Ԫ�صġ�
			struct Node* newNode = createNode(a);
			if (NULL == newNode)
			{
				printf("�����ڴ�ռ�ʧ�ܣ��ڴ治��");
				return;
			}
			newNode->pNext = nodeValues->pNext;
			nodeValues->pNext = newNode;
		}
	}
}
//  ����Ԫ�ص�λ��,û�еĻ�����Ӧ�ķ��ص���NULL�ռ�ĵ�ַ��
struct Node* queryNodesByValue(int value)
{
	if (g_pHead==g_pEnd) //  ������Ļ��Ͳ��ó�����
	{
		printf("�յ��������ò�����");
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
//  ɾ��ͷ���
void  deleteHeadNode()
{
	//  ɾ���ڵ��ʱ��һ��Ҫ����ڵ�ģ���Ҫֱ��ɾ���ڵ�ġ�
	//  ɾ��ͷ���
	struct Node* newNode = g_pHead->pNext; //  ͷ���Ԫ��
	//  ��Ҫ�ж��Ƿ���ֻ��һ��Ԫ�صġ�
	//  ֻ��һ��ͷ���ģ��϶����Ҳ���Ԫ�صġ�
	if (g_pHead==g_pEnd)  //  ֻ��һ��Ԫ��
	{
		printf("����Ϊ�գ�����Ҫɾ��ͷԪ�ص�");
		return;
	}
	else if (g_pHead->pNext==g_pEnd) //  ��Ӧ��ֻ��һ��Ԫ�ؽڵ�
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
//  ɾ������ڵ�
void deleteRandomNode(int a)
{
	//  �ж��������ڽڵ�Ļ�������Ҫ����ɾ����
	if (g_pHead == g_pEnd)  //  ֻ��һ��Ԫ��
	{
		printf("����Ϊ�գ�����Ҫɾ��ͷԪ�ص�");
		return;
	}
	struct Node*  node=queryNodesByValue(a);
	if (!node)
	{
		printf("�ڵ㲻����,����Ҫɾ����");
		return;
	}
	//  �ڵ���ڣ���Ҫ�жϡ�
	//  �����ͷ���Ļ����������µ�
	if (g_pHead->pNext == node)
	{
		deleteHeadNode();
	}
	else if(node->pNext==NULL)  //  β���Ļ���ɾ��β���ڵ��
	{
		deleteTailNode(node);
	}
	else  //  ���ڵ��Ƕ���ڵ��,ɾ���м�Ľڵ�ġ�
	{
		struct Node* newNode = g_pHead->pNext;
		while (newNode)  // ���������Ԫ�ص�
		{
			if (newNode->pNext == node)  //  ǰ���һ���ڵ��
			{
				newNode->pNext = node->pNext;
				free(node);
				return;
			}
			newNode = newNode->pNext;
		}
	}
}
//  ɾ��β���ڵ�
void deleteTailNode(struct Node* newNode1)
{
	// ��Ӧ���ǿ����Ĳ�����
	if (!g_pHead->pNext && !g_pEnd->pNext)
	{
		printf("����,����Ҫɾ��");
		return;
	}
	//  ֻ��һ���ڵ�������Ҫ�������µĴ���ġ�ɾ���˽ڵ�Ļ�����Ӧ�ľ�ֻʣ��ͷ�����
	if (g_pHead->pNext== newNode1)
	{
		g_pHead->pNext = NULL;
		g_pEnd = g_pHead;
		free(newNode1);
		return;
	}
	//  ���ڶ���ڵ������¡�
	struct Node* newNode = g_pHead->pNext;
	while (newNode)  // ���������Ԫ�ص�
	{
		if (newNode->pNext==g_pEnd)  //  ǰ���һ���ڵ��
		{
			free(g_pEnd);
			newNode->pNext = NULL;
			g_pEnd = newNode;
			return;
		}
		newNode = newNode->pNext;
	}
}
//  �ͷ����е�����
void   freeAllList()
{
	// �ڵ�ֻ��һ��ͷԪ�ص�������ͷŵ�
	if (g_pHead->pNext==NULL)
	{
		free(g_pHead);
	}
	struct Node* node = g_pHead->pNext;
	while (node)  //  �ڵ㲻Ϊ�յ�����£�����ɾ���ڵ�Ԫ��
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
	deleteHeadNode();  //  ɾ��ͷ���
	deleteRandomNode(10);
	freeAllList();
	system("pause");
	return 0;
}