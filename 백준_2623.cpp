#include <iostream>
#include <queue>

using namespace std; 

int map[100][100];
int c[100][100];

void bfs(int n, int m){
	queue<pair<int, int> > q;
	q.push(make_pair(0,0));
	c[0][0] = true;
	while(!q.empty()){
		pair<int, int> tmpt = q.front();
		int x = tmpt.first;
		int y = tmpt.second;
		q.pop();
		if(!c[x + 1][y] && x + 1 < m){
			if(map[x + 1][y] == 1){
				map[x + 1][y] = 2;
			}else if(map[x + 1][y] == 0){
				q.push(make_pair(x + 1, y));
				c[x + 1][y] = true;
			}
		}
		if(!c[x][y + 1] && y + 1 < n){
			if(map[x][y + 1] == 1){
				map[x][y + 1] = 2;
			}else if(map[x][y + 1] == 0 && y + 1 < n){
				q.push(make_pair(x, y + 1));
				c[x][y + 1] = true;
			}
		}
		if(!c[x - 1][y] && x - 1 >= 0){
			if(map[x - 1][y] == 1){
				map[x - 1][y] = 2;
			}else if(map[x - 1][y] == 0){
				q.push(make_pair(x - 1, y));
				c[x - 1][y] = true;
			}
		}
		if(!c[x][y - 1] && y - 1 >= 0){
			if(map[x][y - 1] == 1){
				map[x][y - 1] = 2;
			}else if(map[x][y - 1] == 0 && y - 1 < n){
				q.push(make_pair(x, y - 1));
				c[x][y - 1] = true;
			}
		}
	}
}

int main(void){
	int n,m;
	scanf("%d %d", &m, &n);
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]);
		}
	}
		
	int cnt = 0;
	int result;
	bool done = false;
	while(!done){
		done = true;
		cnt++;
		bfs(n, m);
		
		result = 0;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				c[i][j] = false;
				if(map[i][j] == 2){
					result++;
					map[i][j] = 0;
				}else if(map[i][j] == 1){
					done = false;
				}
			}
		}
	}
	printf("%d\n%d", cnt, result);
	
	return 0;
}
