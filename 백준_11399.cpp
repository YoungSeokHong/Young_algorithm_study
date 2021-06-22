#include <iostream>
#include <algorithm>

int main(void){
	int n;
	int people[1000];
	int result = 0;
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &people[i]);
	}
	
	std::sort(people, people + n);
	
	for(int i=0; i<n; i++){
		result += (n - i) * people[i];
	}
	printf("%d", result);
	return 0;
}
