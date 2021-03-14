#include <iostream>

int number = 10000;
int a[10001];

void primeNumberSieve()
{
	for(int i=1; i<=number; i++)
	{
		a[i] = i;
	}
	
	for(int i=2; i<number; i++)
	{
		if(a[i])
		{
			for(int j=2; i*j<number; j++)
			{
				a[i * j] = 0;
			}
		}
	}
	
}

int main(void)
{
	primeNumberSieve();
	for(int i=2; i<number; i++)
	{
		if(a[i]) printf("%d ", i);
	}
	
	return 0;
}
