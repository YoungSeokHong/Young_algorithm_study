#include <iostream>
#include <vector>
#include <queue>
#define MAX 10000
using namespace std;

vector<pair<int, pair<int, int> > > cost[100];
int d[101];

void dijkstra(int start){
	d[start] = 0;
	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, less<pair<int, pair<int, int> > > > pq;
	pq.push(pair<int, pair<int, int> >(0, make_pair(start, 0)));
	while(!pq.empty){
		int current = pq.top().second.first;
		int distance = pq.top().first;
		pq.pop();
		if(d[current] < distance) continue;
		for(int i=0; i<cost[current].size(); i++){
//			if(sum + cost[current][i].second.second > m) continue;
			pq.push(pair<int, pair<int, int> >(cost[current][i].first, make_pair(cost[current][i].second.first, cost[current][i].second.second)));
		}
	}
}

int main(void)
{
	int n, t, m, l, i, k;
	cin >> n >> t >> m >> l;
	
	int a, b, c, d;
	for(i=0; i<l; i++){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		// pair<시간, pair<다음건물, 비용>>
		cost[a].push_back(pair<int, pair<int, int> >(c, make_pair(b, d)));
	}
	
	for(i=1; i<=n; i++){
		d[i] = MAX;
	}
	
	return 0;
}
