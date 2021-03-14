#include <iostream>

int c[30][30];

int dp(int m, int n)
{
	if(c[m][n]) return c[m][n];
	if(n == 0 || m == n) return c[m][n] = 1;
	return c[m][n] = dp(m - 1, n - 1) + dp(m - 1, n);
}

int main(void)
{
	int t, n, m, i;
	scanf("%d", &t);
	
	for(i=0; i<t; i++)
	{
		scanf("%d %d", &n, &m);
		printf("%d\n", dp(m, n));
	}
	
	return 0;
}



