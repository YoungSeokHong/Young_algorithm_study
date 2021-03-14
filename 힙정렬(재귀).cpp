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

void heapMaker(int array[], int root, int range)
{
	
	if(root >= range) 
	{
		return;
	}
	
	int c = root * 2 + 1;
	
	if(heap[c] < heap[c + 1] && c < range-1)
	{
		c++;
	}
	
	if(heap[c] > heap[root] && c < range)
	{
		swap(heap, c, root);
	}
	
	heapMaker(array, c, range);
}

int main()
{
	for(int i=number-1; i>=0; i--)
	{
		heapMaker(heap, i, number);
	}
	
	for(int i=number-1; i>=0; i--)
	{
		swap(heap, i, 0);
		
		heapMaker(heap, 0, i);
	}
	
	for(int i=0; i<number; i++)
	{
		cout << heap[i] << ' ';
	}
	return 0;
} 
