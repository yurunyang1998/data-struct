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
	// ��ʼ����Ա��ʱ���Ӧ����, '��ʼ����Ա�б�'
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

// ����������Ҫ�ľ�������Ч��....

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
		// ...node_fuben �����������`next`��nullptr, Ȼ����������պû�ȡ��nullptr�ĵ�ַ
		// ��nullptr ����getnum()����, �������쳣....
		// �������ѭ���õ���`'���ε�'ͷ�巨`�������������...


		// nullptr �ȼ��� NULL, ����c++11��׼, ָ�������nullptr... 

		node0_zhizheng = node0_zhizheng->getnext();
	}

	// �ǵ��Լ�����...

	//getchar();

	return 0;

}