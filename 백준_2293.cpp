#include <iostream>

int cnt = 0;
int a[100] = {0,};

void dp(int x, int n, int k, int p)
{
	int i = 0;
	while(a[x] * i <= k){
		if(x < n - 1){
			dp(x + 1, n, k, p + a[x] * i);
		}
		if(p + a[x] * i == k && i){
			cnt++;
		}
		i++;
	}
}

int main(void)
{
	int n, k, i;       
	scanf("%d %d", &n, &k);
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	dp(0, n, k, 0);
	printf("%d", cnt);
	return 0;
}
