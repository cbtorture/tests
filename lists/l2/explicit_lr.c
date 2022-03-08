
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
  int res3_val = counter();
  
	int result[3] = {res1_val, res2_val, res3_val};

	assert(result[0] == 1);
	assert(result[1] == 2);
  assert(result[2] == 3);
}
