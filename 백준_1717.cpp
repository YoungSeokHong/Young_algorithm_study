#include <iostream>

using namespace std;

int getParent(int x, int parent[])
{
	if(x == parent[x]) return x;
	return parent[x] = getParent(parent[x], parent);
}

void unionParent(int a, int b, int parent[])
{
	a = getParent(a, parent);
	b = getParent(b, parent);
	if(a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int a, int b, int parent[])
{
	a = getParent(a, parent);
	b = getParent(b, parent);
	if(a == b) return 1;
	return 0;
}

int main(void)
{
	int n, m, i, c, a, b;
	
	cin >> n >> m;
	
	int parent[n + 1];
	for(i=0; i<n+1; i++)
	{
		parent[i] = i;
	}
	
	for(i=0; i<m; i++)
	{
		scanf("%d %d %d", &c, &a, &b);
		if(!c){
			unionParent(a, b, parent);
		}else{
			if(findParent(a, b, parent)){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	
}
