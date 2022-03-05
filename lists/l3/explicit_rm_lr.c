#include<assert.h>

int count = 0;

int counter()
{
	count++;
	return count;
}


int main()
{
	int c1 = counter();
	int c2 = counter();
	int c3 = counter();
	int c4 = counter();
	int c5 = counter();
	int c6 = counter();

	int arrayOfArrays[3][2] = {
		{c1, c2},
		{c3, c4},
		{c5, c6}
	};

	assert(arrayOfArrays[0][0] == 1);
	assert(arrayOfArrays[0][1] == 2);

	assert(arrayOfArrays[1][0] == 3);
	assert(arrayOfArrays[1][1] == 4);

	assert(arrayOfArrays[2][0] == 5);
	assert(arrayOfArrays[2][1] == 6);

	return 0;
}
