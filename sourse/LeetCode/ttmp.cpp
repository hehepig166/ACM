#include <cstdio>


class ha
{
	static int test;
	
public:
	void chg(int x)
	{
		test=x;
	}
	void prt()
	{
		printf("%d\n",test);
	}
};


int main()
{
	ha a,b,c;
	a.chg(2);
	b.chg(3);
	
	a.prt();
	b.prt();
	c.prt();
	return 0;
}
