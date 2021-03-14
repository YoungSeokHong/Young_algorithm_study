#include <iostream>

int map[1000][1000];
int n, m, i, j, k, l;

int main(void)
{
	bool end = false;
	bool c;
	
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	
	int t;
	for(t=1; t<1001; t++)
	{
		end = true;
		
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(map[i][j] == t){
					c = true;
					for(k=i; k<=i+t; k++){
						if(!map[k][j + t]){
							c = false;
							break;
						}
					}
					for(k=j; k<=j+t; k++){
						if(!map[i + t][k]){
							c = false;
							break;
						}
					}
					if(c) {
						map[i][j]++;
						end = false;
					}
				}
			}
		}
		if(end) break;
	}
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	
	printf("%d", t*t);
	
	return 0;
}
