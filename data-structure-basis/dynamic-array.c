#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

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
void   addElement(struct DynamicArray*  dynamicArray,int element)
{
	int i=0;
	//  �ж�Ԫ���Ƿ�����
	if (dynamicArray->capacity==dynamicArray->storage)
	{
		// ����������Ѿ����ˡ���Ҫ�������ݵġ�
		 int * pHead=(int*)malloc(sizeof(int)*((dynamicArray->capacity)+10));
		//  ��Ҫ��ԭ����������ݿ��������ڵ������е�
		for(i=0;i<(int)dynamicArray->capacity;i++)
		{
			*(pHead+i)=(dynamicArray->pHead)[i];
		}
		*(pHead+i)=element;
		dynamicArray->storage=dynamicArray->storage+1;
		free(dynamicArray->pHead); //  �ͷ�ԭ��������ռ䡣
		dynamicArray->pHead=pHead;
		dynamicArray->capacity=dynamicArray->capacity+10;
	}else
	{
		//  ��Ҫ��ָ��������Ԫ�ص�
		*(dynamicArray->pHead+dynamicArray->storage)=element;
		dynamicArray->storage=dynamicArray->storage+1;
	}
}
void  output(struct DynamicArray*  dynamicArray)
{
	int i=0;
	printf("%d,%d\n",dynamicArray->storage,dynamicArray->capacity);  //7 ��15
	for(i=0;i<(int)dynamicArray->storage;i++)
	{
		printf("%d\n",*(dynamicArray->pHead+i));
	}
}
int main(void)
{
	int i=0;
	// ��ʼ�������Ĵ�С
	struct DynamicArray  dynamicArray;
	init(&dynamicArray);  //  ��ʼ���ṹ�塣
	// 
	addElement(&dynamicArray,1);
	addElement(&dynamicArray,2);
	addElement(&dynamicArray,3);
	addElement(&dynamicArray,4);
	addElement(&dynamicArray,5);
	addElement(&dynamicArray,6);
	addElement(&dynamicArray,7);
	//  �������������
	output(&dynamicArray);
	// �������Ӧ����һ����ͨ�ı�����
	free(dynamicArray.pHead);  // �ͷ�Ԫ�ؿռ�
	system("pause");
	return 0;
}