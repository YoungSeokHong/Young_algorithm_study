#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int t, n, i, j;
	int arr[10000];
	
	cin >> t;
	for(i=0; i<t; i++)
	{
		scanf("%d", &n);
		for(j=0; j<n; j++)
		{
			scanf("%d", &arr[j]);
		}
		
		sort(arr, arr + n);
		
		int max = 0;
		for(j=2; j<n; j++)
		{
			if(arr[j] - arr[j - 2] > max) max = arr[j] - arr[j - 2];
		}
		printf("%d\n", max);
	}
	
	return 0;
}
