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
	int res1_val = counter();
	int res2_val = counter();
	int result[2] = {res1_val, res2_val};

	assert(result[0] == 1);
	assert(result[1] == 2);
}
