#include <stdio.h>
#include <stdlib.h>

struct  Node
{
	int a;
	struct Node* pNext;  // ָ����һ���ṹ���ָ��
};
//  ��ʼ��ͷ�ڵ�ָ���β�ڵ�ָ��
struct  Node *  headNode=NULL; 
struct  Node *  tailNode=NULL;
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
	system("pause");
	return 0;
}