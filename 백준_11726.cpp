#include <iostream>

int d[1001];

int dp(int x)
{
	if(x == 1) return 1;
	if(x == 2) return 2;
	if(d[x] != 0) return d[x];
	return d[x] = dp(x - 2) + dp(x - 1);
}

int main(void)
{
	int n;
	std::cin >> n;
	printf("%d", dp(n)%10007);
	return 0;
 } 
