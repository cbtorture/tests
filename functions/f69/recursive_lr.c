#include<assert.h>

char order[5] = {0,0,0,0,0};

int counter = 0;

int getCount()
{
	counter = counter + 1;
	return counter;
}

int func(int x1, int x2)
{
	order[4] = getCount();
	return 0;
}

int gunc(int x1, int x2)
{
	order[2] = getCount();
	return 144;
}

int f1()
{
	order[0] = getCount();
	return 4;
}

int f2()
{
	order[1] = getCount();
	return 55;
}

int f3()
{
	order[3] = getCount();
	return 67;
}

int main()
{
	func(gunc(f1(), f2()), f3());

	/* Left to right  */
	assert(order[0] == 1);
	assert(order[1] == 2);
	assert(order[2] == 3);
	assert(order[3] == 4);
	assert(order[4] == 5);
	
	return 0;
}