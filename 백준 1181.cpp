#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
string arr[20000];

bool compare(string a, string b)
{
	if(a.length() < b.length())
	{
		return 1;
	} else if (a.length() > b.length())
	{
		return 0;
	} else
	{
		return a < b;
	}
}

int main(void)
{
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	
	sort(arr, arr + n, compare);
	
	for(int i=0; i<n; i++)
	{
		if(arr[i] == arr[i+1])
		{
			continue;
		} else
		{
			cout << arr[i] << endl;	
		}
	}
	
	return 0;
}
