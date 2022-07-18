#include<assert.h>

int counter  = 0;

int arr[2] = {0,0};

int count(int i)
{
	counter = counter + 1;
	arr[i-1] = counter;
	
	return 0;
}

int main()
{
	int j = count(1) + count(2);


	assert(arr[0] == 2);
	assert(arr[1] == 1);
	
	j++;

	

	return 0;
}
