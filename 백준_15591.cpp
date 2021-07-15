#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> > map[5001];
int c[5001];

int bfs(int strt, int k){
    int cnt = 0;
    queue<int> q;
    q.push(strt);
    c[strt] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<map[x].size(); i++){
            int y = map[x][i].first;
            if(!c[y]){
                if(map[x][i].second >= k){
                    q.push(y);
                    c[y] = true;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main(void){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i=0; i < n - 1; i++){
        int a, b, x;
        scanf("%d %d %d", &a, &b, &x);
        map[a].push_back(pair<int, int>(b, x));
        map[b].push_back(pair<int, int>(a, x));
    }
    for(int i=0; i<q ; i++){
        int k, v;
        scanf("%d %d", &k, &v);
        printf("%d\n", bfs(v, k));
        for(int j=0; j<=n; j++){
            c[j] = false;
        }
    }

    return 0;
}