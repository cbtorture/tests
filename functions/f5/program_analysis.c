#include<assert.h>
#include<stdio.h>

int f(int x1, int x2)
{
	return (x1*2)+x2;
}


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
		//int result = (counter(), f)(1,1);

		int result = (updateX(1), f)(updateX(2), updateX(3));

		printf("%d\n", result);

		printf("map[0]=%d\n", map[0]);
		printf("map[1]=%d\n", map[1]);
		printf("map[2]=%d\n", map[2]);
}