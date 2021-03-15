#include <iostream>
#define MAX 1000000000

int arr[100000];
int tree[400000];

int init(int start, int end, int node)
{
	if(start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	int a = init(start, mid, node * 2);
	int b = init(mid + 1, end, node * 2 + 1);
	if(a < b) return tree[node] = tree[node * 2];
	else return tree[node] = tree[node * 2 + 1];
}

int find(int start, int end, int node, int left, int right)
{
	if(left > end || right < start) return MAX;
	if(left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	int a = find(start, mid, node * 2, left, right);
	int b = find(mid + 1, end, node * 2 + 1, left, right);
	if(a < b) return a;
	else return b;
} 

int main(void)
{
	int n, m, i;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	init(0, n - 1, 1);
	
	int a, b;
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", find(0, n - 1, 1, a - 1, b - 1));
	}
	
	return 0;
}
