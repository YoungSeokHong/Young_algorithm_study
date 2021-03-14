#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, v;
int c[1001];
vector<int> a[1001];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	c[start] = true;
	
	int x = start;
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		printf("%d ", x);
		
		for(int i=0; i<a[x].size(); i++)
		{
			int y = a[x][i];
			if(!c[y])
			{
				q.push(y);
				c[y] = true;
			}
		}
	}
}

void dfs(int x)
{
	if(c[x])
	{
		return;
	}
	
	c[x] = true;
	printf("%d ", x);
	
	for(int i=0; i<a[x].size(); i++)
	{
		int y = a[x][i];
		dfs(y);
	}
	
}

int main(void)
{
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &v);
	
	for(int i=0; i<m; i++)
	{
		int x, y;
		scanf("%d", &x);
		scanf("%d", &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	dfs(v);
	printf("\n");
	for(int i=0; i<n+1; i++)
	{
		c[i] = false;
	}
	bfs(v);
	
	
	return 0;
}
