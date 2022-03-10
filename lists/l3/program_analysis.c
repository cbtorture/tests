#include<assert.h>

int count = 0;

int counter()
{
	count++;
	return count;
}


int main()
{
	int arrayOfArrays[3][2] = {
		{counter(), counter()},
		{counter(), counter()},
		{counter(), counter()}
	};

	assert(arrayOfArrays[0][0] == 1);
	assert(arrayOfArrays[0][1] == 2);

	assert(arrayOfArrays[1][0] == 3);
	assert(arrayOfArrays[1][1] == 4);
	
	assert(arrayOfArrays[2][0] == 5);
	assert(arrayOfArrays[2][1] == 6);
	
	
	
	return 0;
}