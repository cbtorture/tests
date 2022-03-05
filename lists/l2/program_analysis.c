#include<assert.h>

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
	* Ex1: {1, 2, 3}
	*/
	int result[3] = {counter(), counter(), counter()};

	assert(result[0] == 1);
	assert(result[1] == 2);
  	assert(result[2] == 3);

  	return 0;
}
