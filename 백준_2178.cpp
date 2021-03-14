#include <iostream>
#include <cmath>

using namespace std;

int n, m;
int c[100][100];
int a[100][100];

void dfs(int x, int y, int cnt)
{
	cout << y+1 << x+1 << " " << cnt << " -> ";
	if(x<0 || y<0){
		cout << "a" << endl;
		return;
	} else if(x == m-1 && y == n-1){
		cout << "b" << endl;
		return;
	} else if(c[x][y] || !a[x][y]){
		cout << "c" << endl;
		return;
	} else {
		cnt++;
		c[x][y] += cnt;
		cout << "d" << endl;
		dfs(x + 1, y, cnt);
		dfs(x - 1, y, cnt);
		dfs(x, y + 1, cnt);
		dfs(x, y - 1, cnt);
	}
}


int main(void)
{
	int i, j, k;
	
	cin >> n >> m;
	for(i=0; i<n; i++)
	{
		int line;
		cin >> line;
		for(j=m-1; j>=0; j--)
		{	
			a[i][j] = line % 10;
			line /= 10;
		}
	}
	dfs(0,0,0);
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			printf("%2d ", c[i][j]);
		}
		cout << "\n";
	}
	
	return 0;
}
