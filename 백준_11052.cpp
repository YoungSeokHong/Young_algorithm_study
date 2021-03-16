#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;

int p[1001];
float rp[1001];

int main(void)
{
	int n, i, j;
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		scanf("%d", &p[i]);
		rp[i] = (float)p[i] / i;
	}
	
	int sum = 0;
	int m = n;
	int before = MAX;
	while(m){
		int max = 0;
		int index;
		for(j=1; j<=n; j++){
			if(rp[j] > max && rp[j] < before) {
				max = rp[j];
				index = j;
			}
		}
		sum = p[index] * (m / index);
		m %= max;
		before = max;
		
		
	}
	
	
	
	
	return 0;
}
