#include <iostream>

using namespace std;

int arr[2][100000];
int temp[2][100000];

int dp(int n)
{
	int a, b, c, d;
	
	for(int i=0; i<n; i++){
		temp[0][i] = 0;
		temp[1][i] = 0;
	}
	
	temp[0][0] = arr[0][0];
	temp[1][0] = arr[1][0];
	
	for(int i=0; i<n; i++)
	{
		a = arr[1][i + 1] + temp[0][i];
		if(a > temp[1][i + 1]) temp[1][i + 1] = a;
		b = arr[1][i + 2] + temp[0][i];
		if(b > temp[1][i + 2]) temp[1][i + 2] = b;
		c = arr[0][i + 1] + temp[1][i];
		if(c > temp[0][i + 1]) temp[0][i + 1] = c;
		d = arr[0][i + 2] + temp[1][i];
		if(d > temp[0][i + 2]) temp[0][i + 2] = d;
	}
	
	if(temp[0][n-1] > temp[1][n-1]){
		return temp[0][n-1];
	} else{
		return temp[1][n-1];
	}
}

int main(void)
{
	int t, n, i, j, k, x;
	
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		scanf("%d", &n);
		for(j=0; j<2; j++)
		{
			for(k=0; k<n; k++)
			{
				scanf("%d", &arr[j][k]);
			}
		}
		printf("%d\n", dp(n));
	}
	
	return 0;
}
