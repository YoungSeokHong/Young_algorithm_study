#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(void)
{
	int n, x;
	vector<int> v;

	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &x);
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0; i<n; i++)
	{
		printf("%d\n", v[i]);
	}
	
	return 0;
}
