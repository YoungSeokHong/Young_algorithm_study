#include <iostream>

int INF = 1000000;
int number = 6;

int c[6]; // 방문확인 배열 
int d[6]; // 거리저장 배열 

int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};

int getMinIndex()
{
	int min = INF;
	int index = 0;
	for(int i=0; i<number; i++)
	{
		if(!c[i])
		{
			if(d[i] < min) min = d[i];
		}
	}
	return index;
}

void dijkstra()
{
	for
	
}


int main(void)
{
	
	return 0;
}
