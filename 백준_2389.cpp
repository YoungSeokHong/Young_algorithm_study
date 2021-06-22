#include <iostream>

int main(void){
	static int MAX = 10000;
	int n;
	int result = MAX;
	
	scanf("%d", &n);
	
	for(int i=0; i*5<=n; i++){
		int tmpt = n - (i * 5);
		if(tmpt % 3 == 0){
			if(i + (tmpt / 3) < result) result = i + (tmpt / 3); 
		}
	}
	
	if(result == MAX) printf("-1");
	else printf("%d", result);
	
	return 0;
}
