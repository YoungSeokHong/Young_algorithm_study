#include <iostream>
#include <queue>

using namespace std;

int map[100][100];
bool c[100][100];
long long cnt[100][100];

long long bfs(int n)
{
	cnt[0][0] = 1;
	c[0][0] = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	
	while(!q.empty())
	{
		pair<int, int> p(q.front().first, q.front().second);
		q.pop();
		if(p.first == n - 1 && p.second == n - 1) break;
		
		if(cnt[p.first][p.second]){
			cnt[p.first + map[p.first][p.second]][p.second] += cnt[p.first][p.second];
			cnt[p.first][p.second + map[p.first][p.second]] += cnt[p.first][p.second];
		}
		
		if(p.first + 1 < n && !c[p.first + 1][p.second]){
			q.push(make_pair(p.first + 1, p.second));
			c[p.first + 1][p.second] = 1;
		}
		if(p.second + 1 < n && !c[p.first][p.second + 1]){
			q.push(make_pair(p.first, p.second + 1));
			c[p.first][p.second + 1] = 1;
		}
	}
	
	return cnt[n - 1][n - 1];
}

int main(void)
{
	int n, i, j;
	
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	
	cout << bfs(n);
	
	return 0;
}
