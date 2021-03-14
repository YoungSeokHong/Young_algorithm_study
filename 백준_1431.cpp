#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int sum(string str)
{
	int sum = 0;
	for(int i=0; i<str.length(); i++)
	{
		if(str[i] >= '0' && str[i] <= '9'){
			sum += str[i] - '0';
		}
	}
	return sum;
}

bool compare(string a, string b)
{
	if(a.length() == b.length()){
		if(sum(a) == sum(b)){
			return a < b;
		} else {
			return sum(a) < sum(b);
		}
	} else{
		return a.length() < b.length();
	}
}

int main(void)
{
	int n;
	string arr[1000];
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	
	sort(arr, arr + n, compare);
	
	for(int i=0; i<n; i++)
	{
		cout << arr[i] << "\n";
	}
	
	return 0;
}
