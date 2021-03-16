#include <iostream>

int main(void)
{
	int t, i;
	scanf("%d", &t);
	
	int a, b;
	for(i=0; i<t; i++){
		scanf("%d %d", &a, &b);
		int sum = 0;
		
		if(a == 1){
			sum += 5000000;
		} else if(1 < a && a < 4){
			sum += 3000000;
		} else if(3 < a && a < 7){
			sum += 2000000;
		} else if(6 < a && a < 11){
			sum += 500000;
		} else if(10 < a && a < 16){
			sum += 300000;
		} else if(15 < a && a < 22){
			sum += 100000;
		}
		
		if(b == 1){
			sum += 5120000;
		} else if(1 < b && b < 4){
			sum += 2560000;
		} else if(3 < b && b < 8){
			sum += 1280000;
		} else if(7 < b && b < 16){
			sum += 640000;
		} else if(15 < b && b < 32){
			sum += 320000;
		}
		
		printf("%d\n", sum);
	}
	
	return 0;
}
