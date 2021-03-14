#include <iostream>
#include <algorithm>

using namespace std;

int getMid(int arr[], int k, int i)
{
	sort(arr + i, arr + i + k);
	return arr[(2 * i + k)/2];
}

int main(void)
{
	int n, k, i;
	int arr[250000];
	cin >> n >> k;
	
	for(i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	
	int sum = 0;
	
	for(i=0; i<n-k+1; i++)
	{
		sum += getMid(arr, i, k);
	}
	
	cout << sum;
	
	return 0;
}
