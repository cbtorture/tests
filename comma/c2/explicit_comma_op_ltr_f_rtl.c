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
		int res1 = updateX(1);
		int res2 = updateX(3);
		int res3 = updateX(2);
		int result = (res1, f)(res3, res2);

		/* 1, f(3, 2) with result=f(3,2) */
		assert(map[0] == 1);
		assert(map[1] == 3);
		assert(map[2] == 2);
		assert(result == 7);		

		return 0;
}
