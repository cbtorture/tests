#include<assert.h>
#include<stdio.h>

int globalCounter = 0;

int counter()
{
	globalCounter++;
	return globalCounter;
}

char orderArray[3] = {0,0,0};

void f(int x1, int x2, int x3)
{
	orderArray[0] = x1;
	orderArray[1] = x2;
	orderArray[2] = x3;
}

int main()
{
	f(counter(), counter(), counter());

	assert(orderArray[0] == 3);
	assert(orderArray[1] == 2);
	assert(orderArray[2] == 1);

	
	return 0;
}
