# include <stdio.h>

typedef struct coordi
{
	int x, y;
}crd;


crd coord[100001], tmp[100001];

void merge(crd a[], int p, int q, int r)
{
	int posa = p, posb = q+1, pos = p;
	while(posa<=q && posb<=r)
	{
		if(a[posa].x<a[posb].x) tmp[pos++] = a[posa++];
		else if(a[posa].x>a[posb].x)tmp[pos++] = a[posb++];
		else
		{
			if(a[posa].y<a[posb].y) tmp[pos++] = a[posa++];
			else tmp[pos++] = a[posb++];
		}
	}
	while(posa<=q) tmp[pos++] = a[posa++];
	while(posb<=r) tmp[pos++] = a[posb++];
	int i;
	for(i=p;i<=r;i++)
		a[i] = tmp[i];
}

void mergesort(crd a[], int p, int r)
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
	int n, i, j;
	crd tmp;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf(" %d %d", &coord[i].x, &coord[i].y);
	}
	mergesort(coord, 0, n-1);
	for(i=0;i<n;i++)
	{
		printf("%d %d\n", coord[i].x, coord[i].y);
	}
	return 0;
}
