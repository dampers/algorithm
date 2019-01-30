#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

struct member
{
	char name[14];
	int k, e, m;
};

struct member stu[100000], tmp[100000];

bool dic(char *a, char *b)
{
	int lenk = strlen(a)<strlen(b)?strlen(a):strlen(b);
	char atmp = a[0], btmp = b[0];
	if(a[0]>='a') atmp -= 32;
	if(b[0]>='a') btmp -= 32;
	if(atmp<btmp) return true;
	else if(atmp>btmp) return false;
	for(int i=1;i<lenk;i++)
	{
		if(a[i]<b[i]) return true;
		else if(a[i]>b[i]) return false;
		else if(i == lenk-1)
		{
			if(lenk==strlen(a)) return true;
			else if(lenk==strlen(b)) return false;
		}
	}
}

void merge(struct member *a, int p, int q, int r)
{
	int pos = p, posa = p, posb = q+1;
	while(posa<=q&&posb<=r)
	{
		if (a[posa].k>a[posb].k) tmp[pos++] = a[posa++];
		else if (a[posa].k<a[posb].k) tmp[pos++] = a[posb++];
		else
		{
			if (a[posa].e<a[posb].e) tmp[pos++] = a[posa++];
			else if (a[posa].e>a[posb].e) tmp[pos++] = a[posb++];
			else
			{
				if (a[posa].m>a[posb].m) tmp[pos++] = a[posa++];
				else if (a[posa].m<a[posb].m) tmp[pos++] = a[posb++];
				else
				{
					if(dic(a[posa].name, a[posb].name))
						tmp[pos++] = a[posa++];
					else tmp[pos++] = a[posb++];
				}
			}
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
		scanf(" %s %d %d %d", stu[i].name, &stu[i].k, &stu[i].e, &stu[i].m);
	mergesort(stu, 0, n-1);
	for(int i=0;i<n;i++)
		printf("%s\n", stu[i].name);
	return 0;
}