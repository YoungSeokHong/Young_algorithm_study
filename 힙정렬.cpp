#include <iostream>

using namespace std;

int number = 9;
int heap[9] = {6, 7, 5, 8, 3, 5, 9, 1, 6};

void swap(int array[], int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

int main()
{
	for(int i=1; i<number; i++)
	{
		int c = i;
		do{
			int root = (c - 1) / 2;
			if(heap[root] < heap[c])
			{
				swap(heap, root, c);
			}
			c = root;
		} while(c != 0);
	}
	
	for(int i=number-1; i>=0; i--)
	{
		swap(heap, i, 0);
		
		int root = 0;
		int c;
		do{
			c = root * 2 + 1;
			if(heap[c] < heap[c + 1] && c < i - 1)
			{
				c++;
			}
			
			if(heap[c] > heap[root] && c < i)
			{
				swap(heap, c, root);
			}
			root = c;
		} while(c < i);
	}
	
	for(int i=0; i<number; i++)
	{
		cout << heap[i] << ' ';
	}
	return 0;
} 
