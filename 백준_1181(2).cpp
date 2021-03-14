#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b)
{
	if(a.length() == b.length()){
		return a < b;
	} else {
		return a.length() < b.length();
	}
}

int main(void)
{
	int n, i;
	string words[20000];
	
	cin >> n;
	for(i=0; i<n; i++)
	{
		cin >> words[i];
	}
	
	sort(words, words + n, compare);
	
	for(i=0; i<n; i++)
	{
		if(i>0 && words[i] == words[i - 1]) continue;
		cout << words[i] << endl;
	}	
	
	return 0;
}
