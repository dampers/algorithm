#include <stdio.h>


int a[100001];
int b[100001];

void merge(int a[], int p, int q, int r)
{
	int posa = p, posb = q+1, pos = 0, i;
	
	while(posa<=q && posb<=r)
	{
		if(a[posa]>a[posb])
		{
			b[pos++] = a[posa++];
		}
		else
		{
			b[pos++] = a[posb++];
		}
	}
	while(posa<=q) b[pos++] = a[posa++];
	while(posb<=r) b[pos++] = a[posb++];
	pos = 0;
	for(i=p;i<=r;i++)
		{
			a[i] = b[pos++];
		}
}

void mergesort(int a[], int p, int r)
{
	if(p<r)
	{
		int q = (p+r)/2;
		mergesort(a, p, q);
		mergesort(a, q+1, r);
		merge(a, p, q, r);
	}
}
int main()
{
	int n, i, tmp, j, max;
	scanf("%d", &n);
	for(i=1;i<=n;i++) scanf(" %d", &a[i]);
	mergesort(a, 1, n);
	max = a[1];
	for(i=1;i<=n;i++)
	{
		if(max < i*a[i]) max = i*a[i];
	}
	printf("%d", max);
	return 0;
}
