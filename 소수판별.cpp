#include <iostream>

bool isPrimeNumber(int x)
{
	for(int i=2; i<x; i++)
	{
		if((x % i) == 0) return false;
	}
	return true;
}

int main(void)
{
	std::cout << isPrimeNumber(12); 
	
	return 0;
}
