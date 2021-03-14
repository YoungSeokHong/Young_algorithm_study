#include <iostream>
#include <algorithm>
using namespace std;

bool getResult(int arr[], int d, int n, int c)
{
	int cnt = 1;
	int temp = arr[0];
	
	for(int i=1; i<n; i++)
	{
		if(arr[i] >= temp + d) {
			temp = arr[i];
			cnt++;
		}
	}
	if(cnt >= c)return true;
	else return false;
}

int binarySearch(int arr[], int n, int c)
{	
	int min = 1;
	int max = arr[n - 1] - arr[0];
	
	while(min <= max)
	{
		int mid = (min + max) / 2;
		
		if(getResult(arr, mid, n, c)) min = mid + 1;
		else max = mid - 1;
	}
	return max;
}

int main(void)
{
	int n, c, i;
	int house[200000];
	
	scanf("%d %d", &n, &c);
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &house[i]);
	}
	
	sort(house, house + n);
	
	cout << binarySearch(house, n, c);
	
	return 0;
}
