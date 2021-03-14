#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int n, w, l, x, i;
	int t = 0, sum = 0;
	queue<int> q;
	
	scanf("%d %d %d", &n, &w, &l);
	for(i=0; i<n; i++) 
	{
		scanf("%d", &x);
		
		if(q.empty()){
			sum = x;
			q.push(x);
		}else{
			if((sum + x) > l){
				while(!q.empty()) {
					sum -= q.front();
					q.pop();
					if((sum + x) <= l) break;
					q.push(0);
					t++;
					
					printf("0t : %d\n", t);
				}
				sum += x;
				q.push(x);
			}else{
				sum += x;
				q.push(x);
			}
		}
		t++;
		printf("1t : %d\n", t);
	}
	
	while(q.size() < w){
		q.push(0);
	}
	while(!q.empty()){
		q.pop();
		t++;
		printf("2t : %d\n", t);
	}
	
	printf("%d", t);
	
	
	return 0;
}
