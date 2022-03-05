#include<assert.h>
#include<stdio.h>

/* Global data */
int count = 0;

/* Counting function */
int counter()
{
	count++;
	return count;
}

int main()
{
	/**
	* Calculate the array
	*
	* Ex1: {1, 2}
	* Ex2: {2, 1}
	*/
	int result[2] = {counter(), counter()};

	assert(result[0] == 2);
	assert(result[1] == 1);

	return 0;
}
