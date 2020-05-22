#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int list[], int p, int r)
{
	int x = list[r], i = p-1;
	for(int j=p;j<r;j++)
	{
		if(list[j]<=x)
		{
			swap(&list[++i], &list[j]);
		}
	}
	swap(&list[++i], &list[r]);
	return i;
}

void quickSort(int list[], int p, int r)
{
	if(p<r)
	{
		int q = partition(list, p, r);
		quickSort(list, p, q-1);
		quickSort(list, q+1, r);
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	int *list = new int[n];
	for(int i=0;i<n;i++)
	{
		list[i] = rand()%5000;
	}
	printf("Before sort : ");
	for(int i=0;i<n;i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
	quickSort(list, 0, n-1);
	printf("Sorted : \t");
	for(int i=0;i<n;i++)
	{
		printf("%d ", list[i]);
	}
	return 0;
}
