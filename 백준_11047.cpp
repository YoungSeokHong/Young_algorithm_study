#include <iostream>

using namespace std;

int coins[10];

int main(void){
	int n, k;
	
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++){
		scanf("%d", &coins[i]);
	}
	
	int result = 0;
	for(int i=n-1; i>=0; i--){
		result += k / coins[i];
		k = k % coins[i];
	}
	printf("%d", result);
	
	return 0;
}


