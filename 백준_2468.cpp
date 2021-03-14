#include <iostream>
#include <algorithm>

int map[101][101];
int temp[101][101];
int cnt[101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void swap(int n)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			temp[i][j] = map[i][j];
		}
	}
}


void dfs(int x, int y, int n, int h)
{
	if(x < 1 || y < 1 || x > n || y > n || temp[x][y] <= h) return;
	temp[x][y] = 0;
	for(int i=0; i<4; i++)
	{
		dfs(x + dx[i], y + dy[i], n, h);
	}
}

int explorer(int n)
{
	for(int h=0; h<=100; h++)
	{
		swap(n);
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(temp[i][j] > h)
				{
					dfs(i, j, n, h);
					cnt[h]++;
				}
			}
		}
		if(!cnt[h]) return h;
	}
	return 0;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	
	int max = 0;
	int k = explorer(n);
	
	for(int h=0; h<k; h++)
	{
		if(max < cnt[h])
		{
			max = cnt[h];
		}
	}
	
	printf("%d", max);
	
	return 0;
}
