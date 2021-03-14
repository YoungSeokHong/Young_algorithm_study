#include <iostream>
#include <vector>
#define INF 11
using namespace std;

vector<pair<int, int> > list[20001];
int arr[20001];
int c[20001];

int getMin(int v)
{
	int min = INF;
	int index;
	for(int i=1; i<=v; i++)
	{
		if(!c[i]){
			if(arr[i] < min){
				min = arr[i];
				index = i;
			}
		}
	}
	return index;
}

void dijkstra(int v, int k)
{
	int current = k;
	
	int a;
	for(int i=0; i<v; i++)
	{
		c[current] = 1;
		for(int j=0; j<list[current].size(); j++)
		{
			if(!c[list[current][j].first]){
				a = arr[current] + list[current][j].second;
				if(a < arr[list[current][j].first]) arr[list[current][j].first] = a;
			}
		}
		current = getMin(v);
	}
}

int main(void)
{
	int v, e, k, i, j;
	cin >> v >> e >> k;
	
	int a, b, c;
	for(i=0; i<e; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		list[a].push_back(pair<int, int>(b, c));
	}
	
	for(i=1; i<=v; i++)
	{
		arr[i] = INF;
	}
	
	arr[k] = 0;
	for(i=0; i<list[k].size(); i++)
	{
		arr[list[k][i].first] = list[k][i].second;
	}
	
	dijkstra(v, k);
	
	for(i=1; i<=v; i++)
	{
		if(arr[i] < INF){
			printf("%d\n", arr[i]);
		} else{
			printf("INF\n");
		}
	}	
	
	
	
	return 0;
}
