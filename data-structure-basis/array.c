//#include <stdio.h>
//#include <memory.h>
//#include <stdlib.h>
//
//int main(void)
//{
//	  //问题：空间满了的话，对应的应该怎么处理。数组的空间满了增加节点的问题的。
//	 //方案一：申请足够大的内存空间的
//	 // 动态申请空间的好处：
//	//	1.空间利用率升高了；
////2.速度慢了，对应的存在不断的拷贝和内存复制的。
//
//	int a[10]={1,2,3,4,5,6,7};
//	int  *p=(int*)malloc(sizeof(int)*10);
//	p[1]=12;  // 修改
//	printf("%d\n",p[1]);
//	  *(p+1)=p[1]
//	printf("%d\n",*(p+1));
//	free(p);  //  堆区空间的释放
//	system("pause");
//	return 0;
//}