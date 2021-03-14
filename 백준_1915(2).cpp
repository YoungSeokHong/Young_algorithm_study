#include <iostream>
#include <algorithm>
using namespace std;

int map[1000][1000];

int main(void)
{
	int n, m, i, j;
	
	scanf("%d %d", &n, &m);
	
	int big = 0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			scanf("%1d", &map[i][j]);
			if(i && j && map[i-1][j-1] && map[i-1][j] && map[i][j-1] && map[i][j]) map[i][j] = min(min(map[i-1][j], map[i][j-1]), map[i-1][j-1]) + 1;
			big = max(big, map[i][j]);
		}
	}
	
	printf("%d", big * big);
	
	return 0;
}



