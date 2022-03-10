#include<assert.h>
#include<stdio.h>

int globalCounter = 0;

int counter()
{
	globalCounter++;
	return globalCounter;
}

int counter2()
{
	globalCounter = globalCounter + 1;
	return globalCounter;
}

int f(int x1, int x2)
{
	return (x1*2)+x2;
}

int main()
{
	int result = f(counter(), counter2());

	assert(result == 4);

	return 0;
}
