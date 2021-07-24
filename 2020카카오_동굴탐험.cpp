#include <string>
#include <vector>

using namespace std;

bool c[200001] = {0,};
bool d[200001];
vector<int> v[200001];
int w[200001];
int cnt = 0;

int dfs(int x){
    if(c[x]) return 0;
    if(d[x]) return -1;
    c[x] = true;
    printf("%d ", x);
    if(w[x]){
        cnt++;
        int o = w[x];
        d[o] = false;
    }
    
    bool tmpt = false;
    for(int i=0; i<v[x].size(); i++){
        printf("%d\n", i);
        int y = v[x][i];
        if(dfs(y) == -1){
            c[x] = false;
            tmpt = true;
        }
    }
    if(tmpt) return -1;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for(int i=0; i<path.size(); i++){
        v[path[i][0]].push_back(path[i][1]);
        v[path[i][1]].push_back(path[i][0]);
    }
    for(int i=0; i<n; i++){
        printf("%d : ", i);
        for(int j=0; j<v[i].size(); j++){
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<order.size(); i++){
        w[order[i][0]] = order[i][1];
        d[order[i][1]] = true;
    }
    
    do{
        dfs(0);
        printf("\n");
    }while(cnt > 0);

    bool answer = true;    
    for(int i=0; i<order.size(); i++){
        if(d[order[i][1]]) answer = false;
    }

    return answer;
}

int main(void){
    solution(9, [[0,1],[0,3],[0,7],[8,1],[3,6],[1,2],[4,7],[7,5]], [[8,5],[6,7],[4,1]]);
}