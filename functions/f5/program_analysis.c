#include<assert.h>

int map[3] = {0,0,0};
int x = 0;
int id = 0;

int updateX(int sig)
{
	map[id] = sig;
	id++;
	
	x++;
	return x;
}

int main()
{
		int result = (updateX(1), updateX(2), updateX(3));

		/* (1, 2, 3) and returning the last, 3 */
		assert(map[0] == 1);
		assert(map[1] == 2);
		assert(map[2] == 3);
		assert(result == 3);		

		return 0;
}