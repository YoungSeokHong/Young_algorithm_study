#include <iostream>
#include <algorithm>
using namespace std;

int snack[1000000];

bool isPossible(int m, int n, int x)
{
	int cnt = 0;
	for(int i=0; i<n; i++)
	{
		if(snack[i] >= x){
			cnt += snack[i]/x;
		}
	}
	if(cnt >= m) return true;
	else return false;
}

int binarySearch(int m, int n)
{
	int min = 1;
	int max = snack[n - 1];

	while(min <= max)
	{
		int mid = (min + max) / 2;
		if(isPossible(m, n, mid)){
			min = mid + 1;
		}else{
			max = mid - 1;
		}
	}
	
	return max;
}

int main(void)
{
	int m, n, i;
	
	cin >> m >> n;
	for(i=0; i<n; i++)
	{
		scanf("%d", &snack[i]);
	}
	
	sort(snack, snack + n);
	
	cout << binarySearch(m, n);
	
	
	return 0;
}
