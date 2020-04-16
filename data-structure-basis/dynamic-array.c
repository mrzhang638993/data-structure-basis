#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
// ��������
void  init(struct DynamicArray*  dynamicArray);
void  addElement(struct DynamicArray*  dynamicArray,int element);
void  output(struct DynamicArray*  dynamicArray);
void  addElementByIndex(struct DynamicArray*  dynamicArray,int  index,int element);
void  isFull(struct DynamicArray*  dynamicArray);
//  �ṹ������
struct DynamicArray
{
	int *pHead;  // ��¼��̬�������λ�ã��������ָ����׵�ַ�ģ������ƶ��ġ�
	unsigned  int capacity ;  //  ���������
	unsigned  int   storage ;  //  �Ѵ洢��Ԫ�ص�����
};
// ���нṹ��ĳ�ʼ������:struct DynamicArray* ��Ӧ���ǽṹ���ָ��ġ�
void  init(struct DynamicArray*  dynamicArray)
{
	dynamicArray->capacity=5;
	dynamicArray->storage=0;
	dynamicArray->pHead=(int*)malloc(sizeof(int)*(dynamicArray->capacity));
}
//  Ԫ����ӵĹ���,��Ҫ���ص��ǽṹ��ģ���������Ĳ�����ôʵ�ֵġ�ֻ��Ҫ�л���Ӧ����λָ���Լ���ص��������ɵġ�
//  ��Ӧ������β������Ԫ�صġ�
void   addElement(struct DynamicArray*  dynamicArray,int element)
{
	int i=0;
	//if (dynamicArray==NULL)  //  ��ָ��Ļ������еĶ�����Ҫ�����жϵġ�
	//{
	//	printf("���������Ϊ��,����");
	//	return ;
	//}
	isFull(dynamicArray);
	*(dynamicArray->pHead+dynamicArray->storage)=element;
	dynamicArray->storage=dynamicArray->storage+1;
	//  �ж�Ԫ���Ƿ�����
	//if (dynamicArray->capacity==dynamicArray->storage)
	//{
	//	// ����������Ѿ����ˡ���Ҫ�������ݵġ�
	//	 int * pHead=(int*)malloc(sizeof(int)*((dynamicArray->capacity)+10));
	//	//  ��Ҫ��ԭ����������ݿ��������ڵ������е�
	//	for(i=0;i<(int)dynamicArray->capacity;i++)
	//	{
	//		*(pHead+i)=(dynamicArray->pHead)[i];
	//	}
	//	*(pHead+i)=element;
	//	dynamicArray->storage=dynamicArray->storage+1;
	//	free(dynamicArray->pHead); //  �ͷ�ԭ��������ռ䡣
	//	dynamicArray->pHead=pHead;
	//	dynamicArray->capacity=dynamicArray->capacity+10;
	//}else
	//{
	//	//  ��Ҫ��ָ��������Ԫ�ص�
	//	*(dynamicArray->pHead+dynamicArray->storage)=element;
	//	dynamicArray->storage=dynamicArray->storage+1;
	//}
}
void  output(struct DynamicArray*  dynamicArray)
{
	int i=0;
	//  ��Ҫ���пյ��жϵģ����Լ���bug
	if (dynamicArray==NULL)
	{
		printf("���������Ϊ��,����");
		return ;
	}
	printf("%d,%d\n",dynamicArray->storage,dynamicArray->capacity);  //7 ��15
	for(i=0;i<(int)dynamicArray->storage;i++)
	{
		printf("%d\n",*(dynamicArray->pHead+i));
	}
}
// ��ָ��������λ������Ԫ��
void  addElementByIndex(struct DynamicArray*  dynamicArray,int  index,int element)
{
	int i=0;
	int storage=dynamicArray->storage;
	int capacity=dynamicArray->capacity;
	if (dynamicArray==NULL)
	{
		printf("���������Ϊ��,����");
		return ;
	}
	if (index<0)
	{
		printf("����������Ϣ����������Ϊ����");
		return ;
	}
	//  ��ָ��������λ������Ԫ�أ������������Ԫ��ִ�к��Ʋ���
	
	//  �±�̫���ˣ���Ӧ����ʾ������д���ġ�
	if (index>(int)dynamicArray->capacity)
	{
		printf("�����±�Խ���ˣ����������±�");
	}
	//  ����ִ��Ԫ�ص��ƶ������ġ�
	isFull(dynamicArray);
	for (i=(int)dynamicArray->capacity-2;i>=index;i--)
	{
		*((dynamicArray->pHead)+i+1)=*((dynamicArray->pHead)+i);
	}
	*((dynamicArray->pHead)+index)=element;
	dynamicArray->storage=dynamicArray->storage+1;
}

void   isFull(struct DynamicArray*  dynamicArray)
{
	int i=0;
	int storage=dynamicArray->storage;
	int capacity=dynamicArray->capacity;
	if (dynamicArray==NULL)
	{
		printf("���������Ϊ��,����");
		return ;
	}
	if (storage==capacity)
	{
		// ����������Ѿ����ˡ���Ҫ�������ݵġ�
		int * pHead=(int*)malloc(sizeof(int)*((dynamicArray->capacity)+10));
		memset(pHead,0,(dynamicArray->capacity)+10);  //  ����Ԫ�س�ʼ������
		//  ��Ҫ��ԭ����������ݿ��������ڵ������е�
		for(i=0;i<(int)dynamicArray->capacity;i++)
		{
			*(pHead+i)=(dynamicArray->pHead)[i];
		}
		/**(pHead+i)=element;
		dynamicArray->storage=dynamicArray->storage+1;*/
		free(dynamicArray->pHead); //  �ͷ�ԭ��������ռ䡣
		dynamicArray->pHead=pHead;
		dynamicArray->capacity=dynamicArray->capacity+10;
	}
}
int main(void)
{
	int i=0;
	// ��ʼ�������Ĵ�С
	struct DynamicArray  dynamicArray;
	init(&dynamicArray);  //  ��ʼ���ṹ�塣
	addElement(&dynamicArray,1);
	addElement(&dynamicArray,2);
	addElement(&dynamicArray,3);
	addElement(&dynamicArray,4);
	addElement(&dynamicArray,5);
	addElement(&dynamicArray,6);
	addElement(&dynamicArray,7);
	addElementByIndex(&dynamicArray,5,35);
	addElementByIndex(&dynamicArray,6,78);
	//  �������������
	output(&dynamicArray);
	// �������Ӧ����һ����ͨ�ı�����
	free(dynamicArray.pHead);  // �ͷ�Ԫ�ؿռ�
	system("pause");
	return 0;
}