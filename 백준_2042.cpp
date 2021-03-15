#include <iostream>
typedef long long ll;

ll arr[1000000] = {0,};
ll tree[4000000] = {0,};

ll init(int start, int end, int node)
{
	if(start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right)
{
	if(left > end || right < start) return 0;
	if(left <= start && end <= right) 	return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, ll dif)
{
	if(index < start || index > end) return;
	if(start == end) {
		arr[index] = dif;
		tree[node] = arr[index];
		return;
	}
	tree[node] += dif - arr[index];
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main(void)
{
	int n, m, k, i;
	
	scanf("%d %d %d", &n, &m, &k);
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	init(0, n - 1, 1);
	
	int a, b;
	ll c;
	for(i=0; i<m + k; i++){
		scanf("%d %d %lld", &a, &b, &c);
		if(a == 1){
			update(0, n - 1, 1, b - 1, c);
		}else if(a == 2){
			printf("%lld\n", sum(0, n -1, 1, b - 1, c - 1));
		}
	}
	
	
	return 0;
}
