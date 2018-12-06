#include <stdio.h>

int a[5000001], tmp[5000001];

void merge(int a[], int p, int q, int r)
{
	int posa = p, posb = q+1, pos = p;
	while(posa<=q && posb<=r)
	{
		if(a[posa]<a[posb]) tmp[pos++] = a[posa++];
		else tmp[pos++] = a[posb++];
	}
	while(posa<=q) tmp[pos++] = a[posa++];
	while(posb<=r) tmp[pos++] = a[posb++];
	int i;
	for(i=p;i<=r;i++)
		a[i] = tmp[i];
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
	int n, k;
	scanf("%d %d", &n, &k);
	int i;
	for(i=0;i<n;i++)
		scanf(" %d", &a[i]);
	mergesort(a, 0, n-1);
	printf("%d", a[k-1]);
	
	return 0;
}
