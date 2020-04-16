#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
// 函数声明
void  init(struct DynamicArray*  dynamicArray);
void  addElement(struct DynamicArray*  dynamicArray,int element);
void  output(struct DynamicArray*  dynamicArray);
void  addElementByIndex(struct DynamicArray*  dynamicArray,int  index,int element);
void  isFull(struct DynamicArray*  dynamicArray);
//  结构体声明
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
//  对应的是在尾部增加元素的。
void   addElement(struct DynamicArray*  dynamicArray,int element)
{
	int i=0;
	//if (dynamicArray==NULL)  //  有指针的话，所有的都是需要进行判断的。
	//{
	//	printf("传入的数据为空,请检查");
	//	return ;
	//}
	isFull(dynamicArray);
	*(dynamicArray->pHead+dynamicArray->storage)=element;
	dynamicArray->storage=dynamicArray->storage+1;
	//  判断元素是否满了
	//if (dynamicArray->capacity==dynamicArray->storage)
	//{
	//	// 数组的容量已经满了。需要进行扩容的。
	//	 int * pHead=(int*)malloc(sizeof(int)*((dynamicArray->capacity)+10));
	//	//  需要将原来数组的内容拷贝到现在的数组中的
	//	for(i=0;i<(int)dynamicArray->capacity;i++)
	//	{
	//		*(pHead+i)=(dynamicArray->pHead)[i];
	//	}
	//	*(pHead+i)=element;
	//	dynamicArray->storage=dynamicArray->storage+1;
	//	free(dynamicArray->pHead); //  释放原来的数组空间。
	//	dynamicArray->pHead=pHead;
	//	dynamicArray->capacity=dynamicArray->capacity+10;
	//}else
	//{
	//	//  需要给指针中增加元素的
	//	*(dynamicArray->pHead+dynamicArray->storage)=element;
	//	dynamicArray->storage=dynamicArray->storage+1;
	//}
}
void  output(struct DynamicArray*  dynamicArray)
{
	int i=0;
	//  需要进行空的判断的，可以减少bug
	if (dynamicArray==NULL)
	{
		printf("传入的数据为空,请检查");
		return ;
	}
	printf("%d,%d\n",dynamicArray->storage,dynamicArray->capacity);  //7 和15
	for(i=0;i<(int)dynamicArray->storage;i++)
	{
		printf("%d\n",*(dynamicArray->pHead+i));
	}
}
// 在指定的索引位置增加元素
void  addElementByIndex(struct DynamicArray*  dynamicArray,int  index,int element)
{
	int i=0;
	int storage=dynamicArray->storage;
	int capacity=dynamicArray->capacity;
	if (dynamicArray==NULL)
	{
		printf("传入的数据为空,请检查");
		return ;
	}
	if (index<0)
	{
		printf("请检查索引信息，索引不能为负数");
		return ;
	}
	//  在指定的索引位置增加元素，该索引后面的元素执行后移操作
	
	//  下标太大了，对应的提示错误进行处理的。
	if (index>(int)dynamicArray->capacity)
	{
		printf("索引下标越界了，请检查索引下标");
	}
	//  下面执行元素的移动操作的。
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
		printf("传入的数据为空,请检查");
		return ;
	}
	if (storage==capacity)
	{
		// 数组的容量已经满了。需要进行扩容的。
		int * pHead=(int*)malloc(sizeof(int)*((dynamicArray->capacity)+10));
		memset(pHead,0,(dynamicArray->capacity)+10);  //  数组元素初始化操作
		//  需要将原来数组的内容拷贝到现在的数组中的
		for(i=0;i<(int)dynamicArray->capacity;i++)
		{
			*(pHead+i)=(dynamicArray->pHead)[i];
		}
		/**(pHead+i)=element;
		dynamicArray->storage=dynamicArray->storage+1;*/
		free(dynamicArray->pHead); //  释放原来的数组空间。
		dynamicArray->pHead=pHead;
		dynamicArray->capacity=dynamicArray->capacity+10;
	}
}
int main(void)
{
	int i=0;
	// 初始化容量的大小
	struct DynamicArray  dynamicArray;
	init(&dynamicArray);  //  初始化结构体。
	addElement(&dynamicArray,1);
	addElement(&dynamicArray,2);
	addElement(&dynamicArray,3);
	addElement(&dynamicArray,4);
	addElement(&dynamicArray,5);
	addElement(&dynamicArray,6);
	addElement(&dynamicArray,7);
	addElementByIndex(&dynamicArray,5,35);
	addElementByIndex(&dynamicArray,6,78);
	//  输出容量和数量
	output(&dynamicArray);
	// 这里面对应的是一个普通的变量的
	free(dynamicArray.pHead);  // 释放元素空间
	system("pause");
	return 0;
}