#include<assert.h>
#include<stdio.h>

int globalCounter = 0;

int counter()
{
	globalCounter++;
	return globalCounter;
}

int f(int x1, int x2)
{
	return (x1*2)+x2;
}

int main()
{
	int arg2 = counter();
	int arg1 = counter();
	int result = f(arg1, arg2);

	assert(result == 5);
}
