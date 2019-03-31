#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 101
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t)) // swap
void sort(int a[], int size); // selection sort

int main()
{
	int i, n = 20; // n = 수의 개수
	int list[MAX_SIZE];
	printf("Unsorted array\n");
	for(i=0;i<n;i++)
	{
		list[i] = rand()%100; // rand()에서 추출된 수를 두 자리 수로 제한
		printf("%d ", list[i]); // 추출된 수 출력
	}
	sort(list, n); // 선택 정렬 수행
	printf("\nSorted array\n");
	for(i=0;i<n;i++)
	{
		printf("%d ", list[i]); // 	
	}
	printf("\n");
	return 0;
}

void sort(int list[], int size) //selection sort
{
	int i, j, min, temp;
	for(i=0;i<size-1;i++)
	{
		min = i;
		for(j=i+1;j<size;j++)
		{
			if(list[j]<list[min])
				min = j;
		}
		SWAP(list[i],list[min],temp);
	}
}