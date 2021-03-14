#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int getMax(string a, string b)
{
	if(a.length() == b.length()){
		return a > b;
	} else{
		return a.length() > b.length();
	}
}

bool compare(string a, string b)
{
	return a + b > b + a;
}

int main(void)
{
	int n, k, i, j;
	string max;
	bool flag = false;
	string nums[1000];
	
	cin >> k >> n;
	
	for(i=0; i<k; i++)
	{
		cin >> nums[i];
	}
	
	sort(nums, nums + k, getMax);
	max = nums[0];
	sort(nums, nums + k, compare);
	
	for(i=0; i<k; i++)
	{
		if(!nums[i].compare(max) && !flag){
			for(j=0; j<n-k; j++)
			{
				cout << nums[i];
			}
			flag = true;
		}
		cout << nums[i];
	}
	
	return 0;
}
