#include<assert.h>
#include<stdio.h>

int globalCounter = 0;

int counter()
{
	globalCounter++;
	return globalCounter;
}

int f(int x1, int x2, int x3)
{
	return (x1*2)+x2+x3*3;
}

int main()
{
	/**
	* 1,2,3 => (1*2)+2+3*3 => 13
	* 3,2,1 => (3*2)+2+1*3 => 11
	*/
	int result = f(counter(), counter(), counter());

	assert(result == 13);

	return 0;
}
