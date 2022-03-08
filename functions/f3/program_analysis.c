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
	int result = f(1)+f(2);

	/**
	* left to right
	*/
  	assert(global == 2);
	
	return 0;
}
