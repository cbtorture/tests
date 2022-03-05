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
	int res1_val = counter();
	int res2_val = counter();
	int res3_val = counter();
  
	int result[3] = {res3_val, res2_val, res1_val};

	assert(result[0] == 3);
	assert(result[1] == 2);
  	assert(result[2] == 1);

  	return 0;
}
