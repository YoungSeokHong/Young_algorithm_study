#include <iostream>

int map[50][50];
int temp[50][50];

void spread(int x, int y, int r, int c, int ax, int ay)
{
	int k = 0;
	int s = map[x][y] / 5;
	if(x + 1 < r && !(x + 2 == ax && y == 0)){
		temp[x + 1][y] += s;
		k += s;
	}
	if(x - 1 >= 0 && !(x - 1 == ax && y == 0)){
		temp[x - 1][y] += s;
		k += s;
	}
	if(y + 1 < c){
		temp[x][y + 1] += s;
		k += s;
	}
	if(y - 1 >= 0 && !((x == ax || x == ax - 1)&& y - 1 == ay)){
		temp[x][y - 1] += s;
		k += s;
	}
	map[x][y] -= k;
}

void linearX(int ay, int x, int i, int c)
{
	for(int j=0; j<c; j++)
	{
		if(j + i >= 0 && j + i < c)temp[x][j + i] = map[x][j];
	}
	for(int j=0; j<c; j++)
	{
		if(temp[x][j] != -1) map[x][j] = temp[x][j];
		else map[x][j] = 0;
		temp[x][j] = 0;
	}
}

void linearY(int ax, int y, int i, int r)
{
	for(int j=0; j<r; j++)
	{
		if(j < ax && j + i >= 0 && j + i < r) temp[j + i][y] = map[j][y];
		else if(j >= ax && j + i >= 0 && j + i < r) temp[j - i][y] = map[j][y];
	}
	for(int j=0; j<r; j++)
	{
		if(map[j][y] != -1) map[j][y] = temp[j][y];
		temp[j][y] = 0;
	}
}

int main(void)
{
	int r, c, t, ax, ay;
	int i, j, k;
	int sum = 0;
	
	scanf("%d %d %d", &r, &c, &t);
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j] < 0) ax = i, ay = j;
		}
	}
	
	printf("\n");
	
	for(i=0; i<t; i++)
	{
		for(j=0; j<r; j++)
		{
			for(k=0; k<c; k++)
			{
				if(map[j][k] > 0){
					spread(j, k, r, c, ax, ay);
				}
			}
		}
		
		for(j=0; j<r; j++)
		{
			for(k=0; k<c; k++)
			{
				if(temp[j][k] > 0){
					map[j][k] += temp[j][k];
					temp[j][k] = 0;
				}
			}
		}
		
		linearY(ax, 0, 1, r);
		linearX(ay, 0, -1, c);
		linearX(ay, r - 1, -1, c);
		linearY(ax, c -1, -1, r);
		linearX(ay, ax, 1, c);
		linearX(ay, ax - 1, 1, c);
		map[ax][ay] = -1, map[ax - 1][ay] = -1;		
	}
	
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("%d ", map[i][j]);
			if(map[i][j] > 0) sum += map[i][j];
		}
		printf("\n");
	}
	
	printf("\n");
	printf("%d", sum);
	
	return 0;
}
