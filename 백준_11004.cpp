#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
	int n, k, i;
	int a;
	std::vector<int> v;
	
	scanf("%d", &n);
	scanf("%d", &k);
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &a);
		v.push_back(a);
	}
	
	sort(v.begin(), v.end());
	
	printf("%d", v[k-1]);
	
	return 0;
} 
