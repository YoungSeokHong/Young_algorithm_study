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
			t += w;
			sum = x;
			q.push(x);
		}else{
			if((sum + x) > l){
				while(!q.empty()) {
					sum -= q.front();
					q.pop();
					if((sum + x) <= l){
						printf("-----%d\n", q.size());
						t -= q.size();
						break;
					}
					t++;
				}
				t += w;
				sum += x;
				q.push(x);
			}else{
				if(q.size() >= w){
					sum -= q.front();
					q.pop();
					t++;
				}
				sum += x;
				q.push(x);
			}
		}
		printf("%d %d\n", x, t);
	}
//	while(!q.empty()){
//		printf("p\n");
//		q.pop();
//		t++;
//	}
	
	printf("%d", t);
	
	
	return 0;
}
