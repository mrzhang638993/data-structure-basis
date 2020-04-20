#include <stdio.h>
#include <stdlib.h>
//  0xcdcdcdcd  ��Ӧ����Ұָ��ģ���Ҫ�ر�����У��Ƿ����ǳ�ʼ��Ԫ����
struct  Node
{
	int a;
	struct Node* pNext;  // ָ����һ���ṹ���ָ��
};
//  ��ʼ��ͷ�ڵ�ָ���β�ڵ�ָ��
struct  Node *  headNode=NULL; 
struct  Node *  tailNode=NULL;

//  ��������
void  tailInsertToList(int a);
void  headInsertToList(int a);
void  scanList();
struct  Node* selectNode(int a);
void  freeList();
void  freePartialList(int a);
void insertElementByIndexBefore(int index, int a);
void insertElementByIndexAfter(int index, int a);


//  ��ʼ������,��������ķ�ʽ����ͷ����Ӻ�β����ӵ�
void  tailInsertToList(int a )
{
	//  ����һ���ڵ�,��Ϊͷָ��ָ��ĵ�һ���ڵ��
	struct  Node* node = (struct  Node*)malloc(sizeof(struct  Node));
	node->a = a;
	node->pNext = NULL;  // һ��Ҫ��ֵΪNULL������Ļ�����Ӧ�Ļ����Խ�������ġ�
	//  �������ӽڵ�Ĳ�������Ҫ�����߼��ж�
	if (!headNode && !tailNode)  //  ʲô��û�еĿ������,ͷָ���βָ�붼ָ������ڵ��
	{
		// ���õ���Ҫ��ʼ����ص�node�ڵ��,ͷ�ڵ��β�ڵ��Ӧ�Ķ��ǵ�һ���ڵ��
		headNode = node;
		tailNode = node;
	}
	else  //  �µĽڵ��Ӧ�ļ��뵽β�ڵ��ϵ�,��Ӧ��ָ�����β�ڵ�ġ�
	{
		//  ��Ӧ�Ĳ��õ���β����ӵģ���Ӧ���Ƕ��еġ�
		tailNode->pNext = node;
		tailNode = node;
	}
}
//ͷ�����Ԫ��
void  headInsertToList(int a)
{
	//  ����һ���ڵ�,��Ϊͷָ��ָ��ĵ�һ���ڵ��
	struct  Node* node = (struct  Node*)malloc(sizeof(struct  Node));
	node->a = a;
	node->pNext = NULL;  // һ��Ҫ��ֵΪNULL������Ļ�����Ӧ�Ļ����Խ�������ġ�
	//  �������ӽڵ�Ĳ�������Ҫ�����߼��ж�
	if (!headNode && !tailNode)  //  ʲô��û�еĿ������,ͷָ���βָ�붼ָ������ڵ��
	{
		// ���õ���Ҫ��ʼ����ص�node�ڵ��,ͷ�ڵ��β�ڵ��Ӧ�Ķ��ǵ�һ���ڵ��
		headNode = node;
		tailNode = node;
	}
	else  //  �µĽڵ��Ӧ�ļ��뵽β�ڵ��ϵ�,��Ӧ��ָ�����β�ڵ�ġ�
	{
		//  ��Ӧ�Ĳ��õ���ͷ����ӵģ���Ӧ����ջ�����ġ�
		node->pNext = headNode;
		headNode = node;
	}
}
//����ı�������,ȫ��ı�������
void  scanList()
{
	struct  Node* node = headNode; // ��Ӧ����ͷ�ڵ��ָ��ġ�
	//  �����Ĺ����У�ͷָ���ǲ��ܱ仯��
	while (node)  // ����һ���ڵ��βָ���Ӧ����NULL��
	{
		printf("%d\n", node->a);
		node = node->pNext;
	}
}
//  ��ѯָ���Ľڵ�,��ѯ���ݴ���Ϊa
struct  Node* selectNode(int a)
{
	struct  Node* node = headNode; // ��Ӧ����ͷ�ڵ��ָ��ġ�
	while (node)  // ����һ���ڵ��βָ���Ӧ����NULL��
	{
		if (a==node->a)
		{
			return node;
		}
		node = node->pNext;
	}
	return NULL;
}
//  ����ɾ�����ͷ�:�����ͷŵ���ȫ��������
void  freeList()
{
	struct  Node* node = headNode;
	struct  Node* node1 = NULL;
	while (node)
	{
		//  �ͷŵ�ǰ�Ľڵ㣬�ڵ������ƶ�
		node1 = node->pNext;
		free(node);
		node = node1;
	}
	//  ͷ�ڵ��β�ڵ�ȫ������ΪNULL
	headNode = NULL;
	tailNode = NULL;
}
//  �ͷŲ����������������ͷ�
void  freePartialList(int a)
{
	struct  Node* node = headNode; // ��Ӧ����ͷ�ڵ��ָ��ġ�
	while (node)  // ����һ���ڵ��βָ���Ӧ����NULL��
	{
		if (a == node->a)
		{
			//  �ڵ��Ⱥ��һ���ڵ�֮���������Ľڵ�ģ���Ҫ�ж�λ��
			if (node == headNode)
			{
				//  ͷ�ڵ�ָ��
				headNode = node->pNext;
				free(node);
				return;
			}
			else if (node == tailNode)
			{
				//  �ͷ�β�ڵ㣬��Ҫ��ǰ�ƶ�β��ָ��
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
		// �ڵ��Ѿ��ͷ��ˣ�������pNext��ûʲô������
		node = node->pNext;
	}
}
//  ��ָ����λ��ǰ�����Ԫ��
void insertElementByIndexBefore(int index, int a)
{
	if (headNode==NULL) //  ��������׽ڵ����Ϣ
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
		printf("��Ӧ�Ľڵ㲻����");
	}
	//  �ڵ���ڣ���Ҫ�����ڵ㣬���ҵ���λ������һ���ڵ�
	struct  Node*  newNode= (struct  Node*)malloc(sizeof(struct  Node));
	newNode->a = a;
	//  ���⣺�ҵ����ǵ�һ���ڵ�Ļ�����Ӧ����Ҫ����
	if (nodeResult == headNode)
	{
		newNode->pNext = nodeResult;
		headNode = newNode;
	}
	else
	{
		//  ����Ĵ洢�ռ��������
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
//  ��ָ����λ�ú������Ԫ��
void insertElementByIndexAfter(int index, int a)
{
	if (headNode == NULL) //  ��������׽ڵ����Ϣ
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
		printf("��Ӧ�Ľڵ㲻����");
	}
	//  �ڵ���ڣ���Ҫ�����ڵ㣬���ҵ���λ������һ���ڵ�
	struct  Node* newNode = (struct  Node*)malloc(sizeof(struct  Node));
	newNode->a = a;
	//  ���⣺�ҵ�����β�ڵ�Ļ�����ô����
	if (nodeResult == tailNode)
	{
		nodeResult->pNext = newNode;
		tailNode = newNode;
	}
	else
	{
		//  ����β�ڵ�Ļ���ֱ���ڽڵ�������Ӽ��ɵ�
		struct  Node*   beforeNode=nodeResult->pNext;
		nodeResult->pNext = newNode;
		newNode->pNext = beforeNode;
	}
}

int  main(void)
{
	//initList(1);
	//initList(2);
	//initList(3);
	//initList(4);
	//initList(5);
	//  ����ʹ������������������������
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
		printf("�ýڵ㲻����");
	}*/
	//  �ռ��ͷŲ���
	//freeList();
	//freePartialList(8);
	//insertElementByIndex(8, 12);
	insertElementByIndexAfter(8, 12);
	system("pause");
	return 0;
}