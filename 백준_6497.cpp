#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[200000];

class Edge{
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge &edge) {
		return this->distance < edge.distance;
	}
};

int getParent(int x)
{
	if(x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if(a < b) parent[b] = getParent(a);
	else parent[a] = getParent(b);
}

int unionFind(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if(a == b) return 1;
	return 0;
}

int main(void)
{
	int m, n, i;
	vector<Edge> v;
	int worst = 0;
	int sum = 0;
	
	while(true)
	{
		worst = 0;
		scanf("%d %d", &m, &n);
		if(!m && !n) break;
	
		int a, b, c;
		for(i=0; i<n; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			v.push_back(Edge(a, b, c));
			worst += c;
		}
			
		sort(v.begin(), v.end());
		
		for(i=0; i<m; i++)
		{
			parent[i] = i;
		}

		sum = 0;
		for(i=0; i<n; i++)
		{
			if(!unionFind(v[i].node[0], v[i].node[1])){
			sum += v[i].distance;
			unionParent(v[i].node[0], v[i].node[1]);
			}
		}
		v.clear();
	
		printf("%d\n", worst - sum);
	}
	
	return 0;
}
