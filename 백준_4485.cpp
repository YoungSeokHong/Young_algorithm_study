#include <iostream>
#include <queue>
#define INF 200000
using namespace std;

int map[125][125];
int cost[125][125];

void dijkstra(int x, int y, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cost[i][j] = INF;
		}
	}
	
	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
	pq.push(pair<int, pair<int, int> >(map[x][y], make_pair(x, y)));
	cost[0][0] = map[0][0];
	
	while(!pq.empty())
	{
		pair<int, int> current = make_pair(pq.top().second.first, pq.top().second.second);
		int distance = pq.top().first;
		pq.pop();
		
		if(current.first - 1 >= 0){
			int nextCost = cost[current.first][current.second] + map[current.first - 1][current.second];
			if(nextCost < cost[current.first - 1][current.second]) {
				cost[current.first - 1][current.second] = nextCost;
				pq.push(pair<int, pair<int, int> >(nextCost, make_pair(current.first - 1, current.second)));
			}
		}
		if(current.second - 1 >= 0){
			int nextCost = cost[current.first][current.second] + map[current.first][current.second - 1];
			if(nextCost < cost[current.first][current.second - 1]) {
				cost[current.first][current.second - 1] = nextCost;
				pq.push(pair<int, pair<int, int> >(nextCost, make_pair(current.first, current.second - 1)));
			}
		}
		if(current.first + 1 < n){
			int nextCost = cost[current.first][current.second] + map[current.first + 1][current.second];
			if(nextCost < cost[current.first + 1][current.second]) {
				cost[current.first + 1][current.second] = nextCost;
				pq.push(pair<int, pair<int, int> >(nextCost, make_pair(current.first + 1, current.second)));
			}
		}
		if(current.second + 1 < n){
			int nextCost = cost[current.first][current.second] + map[current.first][current.second + 1];
			if(nextCost < cost[current.first][current.second + 1]) {
				cost[current.first][current.second + 1] = nextCost;
				pq.push(pair<int, pair<int, int> >(nextCost, make_pair(current.first, current.second + 1)));
			}
		}
	}
}


int main(void)
{
	int n, i, j;
	
	int cnt = 0;
	while(true)
	{
		cnt++;
		scanf("%d", &n);
		if(!n) break;
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		
		dijkstra(0, 0, n);
		
		printf("Problem %d: %d\n", cnt, cost[n - 1][n - 1]);
	}
	
	
	
	
	return 0;
}
