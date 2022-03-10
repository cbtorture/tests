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
	int result1 = counter();
	int result2 = counter2();
	int result = f(result1, result2);

	assert(result == 4);

	return 0;
}
