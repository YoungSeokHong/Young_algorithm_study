#include <iostream>
#include <queue>

using namespace std;

int a[1001];
int n, w, l, t, i;

int main(){
	
    scanf("%d %d %d", &n, &w, &l);
    for(i = 0; i < n; i++)scanf("%d", &a[i]);
    
    queue<int> q;
    int sum = 0;
    
    for(i = 0; i < n; i++){
        while(true){ 
            if(q.size() == w){
                sum -= q.front();
                q.pop();
            }
            if(sum + a[i] <= l) break;
            q.push(0);
            t ++;
        }
        q.push(a[i]);
        sum += a[i];
        t ++;
    }
    t += w;
    printf("%d", t); 
}
