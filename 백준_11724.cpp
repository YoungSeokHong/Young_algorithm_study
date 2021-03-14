#include <iostream>

int getParent(int parent[], int x)
{
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a < b) parent[b] = a;
	else parent[a] = b;
}

void findParent()
{
	
}



int main(void)
{
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	
	int parent[n];
	
	for(int i=1; i<=n; i++)
	{
		parent[i] = i;
	}
	
	for(int i=0; i<m; i++)
	{
		scanf("%d %d", &a, &b);
		unionParent(parent, a, b);
	}
	
	return 0;
}
