#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[100001];

class Edge
{
	public:
		int node[2];
		int distance;	
		Edge(int a, int b, int distance)
		{
			this->node[0] = a;
			this->node[1] = b;
			this->distance = distance;
		}
		bool operator < (Edge &edge)
		{
			return this->distance < edge.distance;
		}
};

int getParent(int x)
{
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if(a < b) parent[b] = a;
	else parent[a] = b;
}

int find(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if(a == b) return 1;
	return 0;
}

int main(void)
{
	int n, m, i;
	scanf("%d %d", &n, &m);
	
	vector<Edge> v;
	
	int a, b, c;
	for(i=0; i<m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		v.push_back(Edge(a, b, c));
	}
	
	sort(v.begin(), v.end());

	for(i=0; i<=n; i++)
	{
		parent[i] = i;
	}
	
	int max = 0;
	int sum = 0;
	for(i=0; i<m; i++)
	{
		if(!find(v[i].node[0], v[i].node[1])){
			max = v[i].distance;
			sum += max;
			unionParent(v[i].node[0], v[i].node[1]);
		}
	}
	
	printf("%d", sum - max);
	return 0;
}
