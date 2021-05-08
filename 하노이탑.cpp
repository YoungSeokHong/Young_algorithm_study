#include <stdio.h>
#include <math.h>


void move(int n, int str, int mid, int dst)
{
	if(n == 0){
		return;
	}
	
	move(n-1, str, dst, mid);
	printf("%d %d\n", str, dst);
	move(n-1, mid, str, dst);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%.0f\n", pow(2, n)-1);
	move(n, 1, 2, 3);
	return 0; 
}


