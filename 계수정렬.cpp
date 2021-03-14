#include <iostream>

using namespace std;

int main(void)
{
	int count[5];
	int array[30] = {
		2, 3, 4, 2, 5, 4, 2, 2, 5, 3,
		2, 3, 2, 5, 4, 3, 2, 4, 4, 3,
		3, 2, 2, 5, 5, 4, 4, 4, 2, 4
	};
	
	for(int i=0; i<5; i++)
	{
		count[i] = 0;
	}
	
	for(int i=0; i<30; i++)
	{
		count[array[i]-1]++;
	}
	
	for(int i=0; i<5; i++)
	{
			for(int j=0; j<count[i]; j++)
			{
				cout << i+1 << ' ';
			}
	}
}
