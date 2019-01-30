#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

struct member
{
	char name[101];
	int age;
	int ord;
};

struct member mem[100000], tmp[100000];

void merge(struct member *a, int p, int q, int r)
{
	int pos = p, posa = p, posb = q+1;
	while(posa<=q&&posb<=r)
	{
		if(a[posa].age<a[posb].age) tmp[pos++] = a[posa++];
		else if(a[posa].age>a[posb].age) tmp[pos++] = a[posb++];
		else
		{
			if(a[posa].ord<a[posb].ord) tmp[pos++] = a[posa++];
			else tmp[pos++] = a[posb++];
		}
	}
	while(posa<=q)
		tmp[pos++] = a[posa++];
	while(posb<=r)
		tmp[pos++] = a[posb++];
	for(int i=p;i<=r;i++)
		a[i] = tmp[i];
}

void mergesort(struct member *a, int p, int r)
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
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %d %s", &mem[i].age, &mem[i].name);
		mem[i].ord = i;
	}
	mergesort(mem, 0, n-1);
	for(int i=0;i<n;i++)
		printf("%d %s\n", mem[i].age, mem[i].name);
	return 0;
}