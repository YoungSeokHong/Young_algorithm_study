#include <iostream>
#include <string>

using namespace std;

int map[250][250];
int check[250][250];
int sheep, wolf;

void dfs(int x, int y, int r, int c){
	if(x < 0 || y < 0 || x > r || y > c) {
		wolf = 0;
		sheep = 0;
		return;	
	}	
	if(check[x][y] || map[x][y] == 3) return;
	check[x][y] = true;
	
	if(map[x][y] == 2) wolf++;
	else if(map[x][y] == 1) sheep++;
	
	dfs(x - 1, y, r, c);
	dfs(x + 1, y, r, c);
	dfs(x, y - 1, r, c);
	dfs(x, y + 1, r, c);
}

int main(void){
	int r, c;
	scanf("%d %d", &r, &c);
	for(int i=0; i<r; i++){
		char str[250];
		scanf("%s", str);
		
		for(int j=0; j<c; j++){
			if(str[j] == '.')map[i][j] = 0;
			else if(str[j] == '#')map[i][j] = 3;
			else if(str[j] == 'v')map[i][j] = 2;
			else if(str[j] == 'o')map[i][j] = 1;
		}
	}
	
	int result_s = 0;
	int result_w = 0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			sheep = 0;
			wolf = 0;
			dfs(i, j, r, c);
			if(sheep > wolf) result_s += sheep;
			else result_w += wolf;
		}
	}
	
	printf("%d %d", result_s, result_w);
	
	return 0;
}
