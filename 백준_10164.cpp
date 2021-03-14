#include <iostream>

int main(void)
{
	int n, m, k, i, j;
	int map[16][16] = {0,};
	
	scanf("%d %d %d", &n, &m, &k);
	if(n == 1 || m == 1){
		printf("1");
		return 0;
	}
	
	int x, y;
	if(k % m){
		x = k / m + 1;
		y = k % m;
	} else{
		x = k / m;
		y = m;
	}
	
	for(i=1; i<=n; i++) map[i][1] = 1;
	for(i=1; i<=m; i++) map[1][i] = 1;
	
	if(k){
		for(i=2; i<=x; i++)
		{
			for(j=2; j<=y; j++)
			{
				map[i][j] = map[i - 1][j] + map[i][j - 1];
			}
		}
	
		for(i=x; i<=n; i++) map[i][y] = map[x][y];
		for(i=y; i<=m; i++) map[x][i] = map[x][y];
	}
	else x = 1, y = 1;
	
	for(i=x+1; i<=n; i++)
	{
		for(j=y+1; j<=m; j++)
		{
			map[i][j] = map[i - 1][j] + map[i][j - 1];
		}
	}

	printf("%d", map[n][m]);
	
	
	return 0;
}
