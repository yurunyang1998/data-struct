// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include  <iostream>

using  namespace std;

class jiedian
{
private:
	int num;
	int value;
	jiedian*   next;

public:
	// 初始化成员的时候更应该用, '初始化成员列表'
	jiedian(int num1, int value1, jiedian* next1 = nullptr)
		:num(num1),
		value(value1),
		next(next1)
	{  }

	jiedian*   getnext()
	{
		return next;
	}
	jiedian*  getthis()
	{
		return this;
	}
	void  setnext(jiedian*   nextt)
	{
		next = nextt;
	}
	int   getnum()
	{
		return  num;
	}

	int getvalue()
	{
		return  value;
	}
	/*
	~jiedian()
	{
	delete next;
	}
	*/
};

// 我想你大概想要的就是这种效果....

int main(void)
{
	jiedian node0(1, 2);
	jiedian*  node0_fuben = &node0;
	int i;
	jiedian*   node0_zhizheng = &node0;
	for (i = 0; i < 10; i++)
	{
		//jiedian node_new(i, 2, node0_zhizheng);
		jiedian *node_new = new jiedian(i, 2, node0_zhizheng);
		node0_zhizheng = node_new;
		//cout << i<<endl;
	}
	//node0_fuben;
	//int k = 10;

	for (int k = 0; k < 10; k++)
	{
		//node_temp = node0.getthis();

		//cout << 1;
		std::cout << node0_zhizheng->getnum() << endl;
		// ...node_fuben 这个对象他的`next`是nullptr, 然后下面的语句刚好获取了nullptr的地址
		// 对nullptr 调用getnum()方法, 程序发生异常....
		// 你上面的循环用的是`'变形的'头插法`制造出来的链表...


		// nullptr 等价于 NULL, 根据c++11标准, 指针最好用nullptr... 

		node0_zhizheng = node0_zhizheng->getnext();
	}

	// 记得自己析构...

	//getchar();

	return 0;

}