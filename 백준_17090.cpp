#include <iostream>

char map[500][500];
int set[500][500] = {0,};

int dfs(int i, int j, int n, int m)
{
	if(i >= n || j >= m || i < 0 || j < 0){
		return 1;
	} else if(set[i][j] == -1){
		return -1;
	} else if(set[i][j] == 1){
		return 1;
	}
	set[i][j] = -1;
	int out = 0;
	if(map[i][j] == 'U') out = dfs(i - 1, j, n, m);
	else if(map[i][j] == 'D') out = dfs(i + 1, j, n, m);
	else if(map[i][j] == 'R') out = dfs(i, j + 1, n, m);
	else if(map[i][j] == 'L') out = dfs(i, j - 1, n, m);
	
	if(out == -1){
		set[i][j] = -1;
		return -1;
	} else if(out == 1){
		set[i][j] = 1;
		return 1;
	}
	
}

int main(void)
{
	int n, m, i, j;
	
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			scanf(" %c", &map[i][j]);
		}
	}
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			dfs(i, j, n, m);
		}
	}
	
	int cnt = 0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			if(set[i][j] == 1) cnt++;
		}
	}
	printf("%d", cnt); 
	
	return 0;
}
