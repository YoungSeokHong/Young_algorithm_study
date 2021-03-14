#include <iostream>
#include <algorithm>

using namespace std; 

bool binarySearch(int arr[], int n, int x)
{
	int strt = 0;
	int end = n - 1;
	int mid;
	
	while(strt <= end)
	{
		mid = (strt + end) / 2;
		
		if(arr[mid] == x){
			return true;
		} else if(arr[mid] > x){
			end = mid - 1;
		} else {
			strt = mid + 1;
		}
	}
	return false;
}

int main(void)
{
	int arr[500000];
	
	int n, m, x, i, j;
	int mid = n / 2;
	
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr + n);
	
	scanf("%d", &m);
	for(i=0; i<m; i++)
	{
		scanf("%d", &x);
		if(!binarySearch(arr, n, x)) printf("0 ");
		else printf("1 ");
	}
	
	
	return 0;
}
