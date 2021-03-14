#include <iostream>
using namespace std;

int main(void)
{
	int m, n, i, j;
	int arr[1000001];
	
	cin >> m >> n;
	
	for(i=2; i<=n; i++)
	{
		arr[i] = i;
	}
	
	for(i=2; i<=n; i++)
	{
		if(arr[i]){
			for(j=2*i; j<=n; j+=i)
			{
				arr[j] = 0;
			}
		}
	}
	
	for(i=m; i<=n; i++)
	{
		if(arr[i]) printf("%d\n", i);
	}
	
	
	return 0;
}
