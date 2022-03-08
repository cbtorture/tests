
#include<assert.h>
#include<stdio.h>

int global = 0;

int f(int x1)
{
	global = x1;
	return 0;
}

int main()
{
	int result1 = f(2);
	int result2 = f(1);
	int result = result2+result1;

	/**
	* right to left
	*/
  	assert(global == 1);
	
	return 0;
}
