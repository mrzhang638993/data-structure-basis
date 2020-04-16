#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct DynamicArray
{
	int *pHead;  // 记录动态数组的首位置，代表的是指针的首地址的，不能移动的。
	unsigned  int capacity ;  //  数组的容量
	unsigned  int   storage ;  //  已存储的元素的数量
};
// 进行结构体的初始化操作:struct DynamicArray* 对应的是结构体的指针的。
void  init(struct DynamicArray*  dynamicArray)
{
	dynamicArray->capacity=5;
	dynamicArray->storage=0;
	dynamicArray->pHead=(int*)malloc(sizeof(int)*(dynamicArray->capacity));
}
//  元素添加的过程,需要返回的是结构体的，否则后续的操作怎么实现的。只需要切换对应的首位指针以及相关的容量即可的。
void   addElement(struct DynamicArray*  dynamicArray,int element)
{
	int i=0;
	//  判断元素是否满了
	if (dynamicArray->capacity==dynamicArray->storage)
	{
		// 数组的容量已经满了。需要进行扩容的。
		 int * pHead=(int*)malloc(sizeof(int)*((dynamicArray->capacity)+10));
		//  需要将原来数组的内容拷贝到现在的数组中的
		for(i=0;i<(int)dynamicArray->capacity;i++)
		{
			*(pHead+i)=(dynamicArray->pHead)[i];
		}
		*(pHead+i)=element;
		dynamicArray->storage=dynamicArray->storage+1;
		free(dynamicArray->pHead); //  释放原来的数组空间。
		dynamicArray->pHead=pHead;
		dynamicArray->capacity=dynamicArray->capacity+10;
	}else
	{
		//  需要给指针中增加元素的
		*(dynamicArray->pHead+dynamicArray->storage)=element;
		dynamicArray->storage=dynamicArray->storage+1;
	}
}
void  output(struct DynamicArray*  dynamicArray)
{
	int i=0;
	printf("%d,%d\n",dynamicArray->storage,dynamicArray->capacity);  //7 和15
	for(i=0;i<(int)dynamicArray->storage;i++)
	{
		printf("%d\n",*(dynamicArray->pHead+i));
	}
}
int main(void)
{
	int i=0;
	// 初始化容量的大小
	struct DynamicArray  dynamicArray;
	init(&dynamicArray);  //  初始化结构体。
	// 
	addElement(&dynamicArray,1);
	addElement(&dynamicArray,2);
	addElement(&dynamicArray,3);
	addElement(&dynamicArray,4);
	addElement(&dynamicArray,5);
	addElement(&dynamicArray,6);
	addElement(&dynamicArray,7);
	//  输出容量和数量
	output(&dynamicArray);
	// 这里面对应的是一个普通的变量的
	free(dynamicArray.pHead);  // 释放元素空间
	system("pause");
	return 0;
}