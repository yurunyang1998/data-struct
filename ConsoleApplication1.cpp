// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
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
		jiedian(int num1, int value1,jiedian* next1 = NULL)
		{
			num = num1;
			value = value1;
			next = next1;
		}

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

void main()
{

	jiedian node0(1, 2);
	jiedian*  node0_fuben = node0.getthis();
	int i;
	jiedian*   node0_zhizheng = node0.getthis();
	for(i=0;i<10;i++)
	{
		jiedian node_new(i, 2, node0_zhizheng);
		node0_zhizheng = node_new.getthis();
		//cout << i<<endl;
	}
	node0_fuben.

	int k = 10;
	
	for (k = 0; k < 10; k++)
	{
		//node_temp = node0.getthis();
	
		//cout << 1;
		std::cout <<node0_fuben->getnum() << endl;

		node0_fuben = node0_fuben->getnext();
	}
	
	

}