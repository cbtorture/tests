#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

/**
* Address of table of function addresses
*/
void (**funcPtr)(int, int) = NULL;

int global = 0;

/**
* Function handle to be called
* (just a dummy)
*/
void dummyFunc(int dummyInput, int dummyInput2)
{
        /* I LIVE IN YOUR WALLS */
        /* printf("dummyFunc(%d, %d)\n", dummyInput, dummyInput2); */
}

int store[4] = {0,0,0,0};

int f(int x)
{
        store[global] = x;
        /* printf("f(%d): global=%d\n", x, global); */
        global++;
        return 0;
}



int g(int x, int y)
{
        return 0;
}

int main()
{
        funcPtr = malloc(sizeof(char*)*4);

	if(funcPtr)
	{

        *(funcPtr) = dummyFunc;
        *(funcPtr+1) = &dummyFunc;
        *(funcPtr+2) = &dummyFunc;
        *(funcPtr+3) = &dummyFunc;

        /**
        * Sequence between func[] and func args 
        * But within func determination (then[])
        * is undetermined as a function can occur
        * there in the form of g(arg1, arg2)
        * and arg1 and arg2 can be in any order
	*
	* left to right sequencing between these two sections though
        */
	 (funcPtr[ g( f(1), f(2) ) ])( f(3), f(4) );
	
	
	assert(store[0] == 1);
	assert(store[1] == 2);
	assert(store[2] == 3);
	assert(store[3] == 4);
	
	}

        return 0;
}
