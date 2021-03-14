#include <iostream>

int mod(int a, int b, int c)
{
	if(b == 1) return a % c;
	long long x = mod(a, b / 2, c);
	if(b % 2 == 1){
		return ((x*x)%c*a) % c;
	} else{
		return (x*x) % c;
	}
}

int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", mod(a, b, c));
	
	return 0;
}
