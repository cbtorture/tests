#include<assert.h>

int map[3] = {0,0,0};
int x = 0;
int id = 0;

int f(int x1, int x2)
{
	return (x1*2)+x2;
}

int updateX(int sig)
{
	map[id] = sig;
	id++;
	
	x++;
	return x;
}

int main()
{
		int result = (updateX(1), f)(updateX(2), updateX(3));

		/* 1, f(2, 3) with result=f(2,3) */
		assert(map[0] == 1);
		assert(map[1] == 2);
		assert(map[2] == 3);
		assert(result == 7);		

		return 0;
}
