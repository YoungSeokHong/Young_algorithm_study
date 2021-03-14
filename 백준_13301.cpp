#include <iostream>

using namespace std;

int main(void)
{
	long long n, i;
	long long r[80];
	long long sum = 0;
	
	r[0] = 1;
	r[1] = 1;
	
	scanf("%d", &n); 
	
	for(i=2; i<n; i++)
	{
		r[i] = r[i - 1] + r[i - 2];
	}
	
	if(n == 1){
		printf("4");
		return 0;
	}
	
	sum = 4 * r[n - 1] + 2 * r[n - 2];
	printf("%u", sum);
	
	
	
	
	return 0;
}
