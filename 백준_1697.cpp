#include <iostream>
#include <queue>

using namespace std;

bool c[100001];

int bfs(int n, int k)
{
	queue<pair<int, int> > q;
	q.push(make_pair(n, 0));
	c[n] = true;
	
	while (!q.empty())
	{
		int x = q.front().first;
		int t = q.front().second;
		q.pop();
		
		if (x == k)
		return t;
		
		if (x + 1 < 100001 && !c[x + 1]){
			q.push(make_pair(x + 1, t + 1));
			c[x + 1] = true;
		}
		if (x - 1 >= 0 && !c[x - 1]){
			q.push(make_pair(x - 1, t + 1));
			c[x - 1] = true;
		}
		if (x * 2 < 100001 && !c[x * 2]){
			q.push(make_pair(x * 2, t + 1));
			c[x * 2] = true;
		}
		}
}

int main(void)
{
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k) << "\n";
	return 0;

}

