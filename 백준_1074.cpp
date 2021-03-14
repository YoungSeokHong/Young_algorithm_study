#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int n, r, c, i;
	int x[16];
	int y[16];
	
	cin >> n >> r >> c;
	
	for(i=1; i<=n; i++)
	{
		x[i] = c % (int)pow(2, i) / (int)pow(2, i - 1);
		y[i] = r % (int)pow(2, i) / (int)pow(2, i - 1);
	}
	
	int result = 0;
	for(i=n; i>0; i--)
	{
		if(x[i] && !y[i]){
			result += (int)pow(4, i - 1);
		} else if(!x[i] && y[i]){
			result += 2 * (int)pow(4, i - 1);
		} else if(x[i] && y[i]){
			result += 3 * (int)pow(4, i - 1);
		}
	}
	
	cout << result; 
	
	return 0;
}
