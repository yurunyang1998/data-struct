// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
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
		~jiedian()
		{
			delete next;
		}
};

void main()
{
	jiedian node0(10, 2);
	jiedian*  head = node0.getthis();
	int i;
	for (i = 9; i > 0; i--)
	{
		jiedian node1(i, 2, head);
		jiedian*   temp = node1.getthis();
		head = temp;
	}
	node0.setnext (head);

	


}