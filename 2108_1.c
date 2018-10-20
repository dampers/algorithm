#include <stdio.h>

int b[500001], a[500001];
int plus[4001], minus[4001];
int mode[8001];

void merge(int a[], int p, int q, int r)
{
	int posa = p, posb = q+1, pos = 0, i;
	while(posa<=q && posb<=r)
	{
		if(a[posa]<a[posb]) b[pos++] = a[posa++];
		else b[pos++] = a[posb++];
	}
	while(posa<=q) b[pos++] = a[posa++];
	while(posb<=r) b[pos++] = a[posb++];
	pos = 0;
	for(i=p;i<=r;i++) a[i] = b[pos++];
}

void mergesort(int a[], int p, int r)
{
	int q;
	if(p<r)
	{
		q = (p+r)/2;
		mergesort(a, p, q);
		mergesort(a, q+1, r);
		merge(a, p, q, r);
	}
}

int main()
{
	int n, j, center, range, max = 0, modep, k = 0;
	double p = 0;
	scanf("%d", &n);
	for(j=0;j<n;j++)
	{
		scanf(" %d", &a[j]);
		p += a[j];
		if(a[j]<0)
		{
			 minus[-1*a[j]]++;
			 if(max < minus[-1*a[j]])  max = minus[-1*a[j]];
		}
		else
		{
			plus[a[j]]++;
			if(max < plus[a[j]]) max = plus[a[j]];
		}
	}
	for(j=1;j<4001;j++)
		if(max == minus[j]) mode[k++] = j*-1;
	for(j=0;j<4001;j++)
		if(max == plus[j]) mode[k++] = j;
	mergesort(a, 0, n-1);
	if(k<2) modep = mode[0];
	else if(k>=2)
	{
		mergesort(mode, 0, k-1);
		modep = mode[1];
	}
	center = a[(n-1)/2];
	range = a[n-1] - a[0];
	printf("%.0f\n%d\n%d\n%d", p/n, center, modep, range);
	return 0;
}
