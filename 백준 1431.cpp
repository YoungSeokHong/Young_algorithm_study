#include <iostream>
#include <algorithm>

using namespace std;

int n;
string serial[1000];

int getSum(string a)
{
	int sum = 0;
	
	for(int i=0; i<a.length(); i++)
	{
		if(a.at(i) - '0' >= 0 && a.at(i) - '0' <= 9)
		{
			sum += a.at(i) - '0';
		}
	}
	
	return sum;
}

bool compare(string a, string b)
{
	if(a.length() < b.length())
	{
		return 1;
	} else if(a.length() > b.length())
	{
		return 0;
	} else
	{
		if(getSum(a) > getSum(b))
		{
			return 0;
		}else if(getSum(a) < getSum(b))
		{
			return 1;
		}else
		{
			return a < b;
		}
	}
}

int main(void)
{
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		cin >> serial[i];
	}
	
	sort(serial, serial + n, compare);
	
	for(int i=0; i<n; i++)
	{
		cout << serial[i] << endl;
	}
	
	return 0;
}
