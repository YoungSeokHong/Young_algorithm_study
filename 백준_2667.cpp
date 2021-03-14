#include <iostream>
#include <algorithm>

using namespace std;

int a[26][26];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int b[400];
int k = 0;
int cnt = 0;

void dfs(int x, int y, int n)
{
	if(x<1 || y<1 || x>n || y>n || !a[x][y] || a[x][y] == 2) return;
	a[x][y] = 2;
	cnt++;
	for(int i=0; i<4; i++)
	{
		dfs(x + dx[i], y + dy[i], n);
	}
}

void explorer(int n)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(a[i][j] == 1)
			{
				dfs(i, j, n);
				b[k] = cnt;
				k++;
				cnt = 0;
			}
		}
	}
	
}

int main(void)
{
	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}
	
	explorer(n);
	
	printf("%d\n", k);
	
	sort(b, b+k);
	
	int p = 0;
	while(b[p])
	{
		if(b[p])
		{
			printf("%d\n", b[p]);
		}
		p++;
	}
	
	
	
	return 0;
}
