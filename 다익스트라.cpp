#include <iostream>
#define INF 1000000000
using namespace std;

int number = 6;

int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};
bool v[6];
int d[6];

int getSmallIndex() {
	int min = INF;
	int index = 0;
	for(int i=0; i<number; i++)
	{
		if(!v[i] && d[i] < min){
			min = d[i];
			index = i;
		}
	}
	v[index] = 1;
	return index;
}

void dijkstra(int start) {
	
	for(int i=0; i<number; i++)
	{
		d[i] = a[start - 1][i];
	}
	
	for(int i=0; i<number; i++)
	{
		int x = getSmallIndex();
		for(int j=0; j<number; j++)
		{
			if(d[j] > d[x] + a[x][j]) d[j] = d[x] + a[x][j];
		}
		
	}
	
}

int main(void)
{
	int i;
	dijkstra(1);
	for(i=0; i<number; i++)
	{
		cout << d[i] << ' ';
	}
	
	return 0;
} 
