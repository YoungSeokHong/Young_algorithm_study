#include <iostream>
#include <stack>

using namespace std;

stack<pair<pair<int, int>, int> > horse[11];
int map[12][12];
int horseMap[12][12];
int cnt = 0;
void direction(int x, int y, int i, int n, bool checked);

void go(int x, int y, int i, int n, bool checked){
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    if(x < 0 || y < 0 || x >= n || y >= n || map[x][y] == 2){
        if(checked) return;
        int tmpD;
        switch (horse[i].top().second){
        case 1: tmpD = 2;
        case 2: tmpD = 1;
        case 3: tmpD = 4;
        case 4: tmpD = 3;
        default:
            horse[i].pop();
            horse[i].push(pair<pair<int, int>, int>(make_pair(x, y), tmpD));
            direction(x, y, i, n, true);
            break;
        }
    }else if(map[x][y] == 1){    
        stack<pair<pair<int, int>, int> > tmp;
        while(!horse[i].empty()){
            tmp.push(pair<pair<int, int>, int>(make_pair(x, y), horse[i].top().second));
            horse[i].pop();
        }
        horse[i] = tmp;
    }else if(map[x][y] == 0){
        horse[i].pop();
        horse[i].push(pair<pair<int, int>, int>(make_pair(x, y), horse[i].top().second));
    }
}

void direction(int x, int y, int i, int n, bool checked){
    int tmpX, tmpY;
    switch (horse[i].top().second)
    {
    case 1: tmpX = x + 1; break;
    case 2: tmpX = x - 1; break;
    case 3: tmpY = y + 1; break;
    case 4: tmpY = y - 1; break;
    default: break;
    }
    printf("asdasd\n");
    go(tmpX, tmpY, i, n, checked);
    if(horseMap[tmpX][tmpY]){
        stack<pair<pair<int, int>, int> > tmp;
        while(!horse[horseMap[tmpX][tmpY]].empty()){
            printf("top : %d\n", horse[i].top().second);
            tmp.push(pair<pair<int, int>, int>(make_pair(tmpX, tmpX), horse[horseMap[tmpX][tmpY]].top().second));
            horse[horseMap[tmpX][tmpY]].pop();
        }
        while(!tmp.empty()){
            horse[i].push(pair<pair<int, int>, int>(make_pair(tmpX, tmpX), tmp.top().second));
            tmp.pop();
        }
    }

}

int main(void){
    // input
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
        }
    }
    for(int i=1; i<=k; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        horse[i].push(pair<pair<int, int>, int>(make_pair(a, b), c));
        horseMap[a][b] = i;
    }

    // method
    bool finish = false;
    while(!finish){
        for(int i=0; i<k; i++){
            if(!horse[i].empty()){
            printf("info : %d\n", i);
                if(horse[i].size() >= 4){
                    cnt--;
                    finish = true;
                    break;
                }
                direction(horse[i].top().first.first, horse[i].top().first.second, i, n, false);
            }
        }
        cnt++;
        if(cnt > 1000){
            printf("-1");
            break;
        }
    }
    if(cnt <= 1000) printf("%d", cnt);
    return 0;
}