#include <iostream>
#define NUMBER 12

int arr[] = {1, 9, 3, 8, 4, 5, 5, 9, 10, 3, 4, 5};
int tree[4 * NUMBER];

int init(int start, int end, int node){
	if(start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right){
	if(left > end || right < start) return 0;
	if(left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
	
int main(void)
{
	init(0, NUMBER - 1, 1);
	
	for(int i=0; i<4*NUMBER; i++){
		if(tree[i]) std::cout << i << " " << tree[i] << '\n';
	}
	
	std::cout << "0부터 10까지의 구간 합 : " << sum(0, NUMBER - 1, 1, 0, 9) << '\n';
	
	
	
	return 0;
}
