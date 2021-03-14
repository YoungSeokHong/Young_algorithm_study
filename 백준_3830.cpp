#include <iostream>

int getParent(int parent[][2], int x)
{
	if(x == parent[x][0]) return x;
	return parent[x][0] = getParent(parent, parent[x][0]);
}

void unionParent(int parent[][2], int a, int b, int w, int n)
{
	int x = a;
	int y = b;
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a < b){
		for(int i=b; i<=n; i++)
		{
			if(parent[i][0] == b) parent[i][1] += parent[x][1] + w;
		}
		parent[b][0] = a;
	} else {
		for(int i=a; i<=n; i++)
		{
			if(parent[i][0] == a) parent[i][1] += parent[y][1] - w;
		}
		parent[a][0] = b;
	}
	
}

int findParent(int parent[][2], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a == b) return 1;
	return 0;
}

int main(void)
{
	int n, m, i, a, b, w;
	char order;
	while(true)
	{
		scanf("%d %d", &n, &m);
		if(!n && !m) break;
		int parent[n + 1][2];
		
		for(i=1; i<=n; i++)
		{
			parent[i][0] = i;
			parent[i][1] = 0;
		}
		
		for(i=0; i<m; i++)
		{
			scanf(" %c %d %d", &order, &a, &b);
			if(order == '!'){
				scanf("%d", &w);
				unionParent(parent, a, b, w, n);
			}else{
				if(findParent(parent, a, b)){
					printf("%d\n", parent[b][1] - parent[a][1]);
				}else{
					printf("UNKNOWN\n");
				}
			}
		}
	}
	return 0;
}
