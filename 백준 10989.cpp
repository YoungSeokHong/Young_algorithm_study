#include <iostream>

int n;
int count[10001];

int main(void)
{
	scanf("%d", &n);
	int temp;
	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &temp);
		count[temp]++;
	}
	for(int i=0; i<10001; i++)
	{
		for(int j=0; j<count[i]; j++)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
