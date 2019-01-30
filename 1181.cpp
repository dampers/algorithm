#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

struct words
{
	char word[51];
	int len;
};

struct words w[20000], tmp[20000];
bool dic(char *a, char *b)
{
	int lenk = strlen(a);
	for(int i=0;i<lenk;i++)
	{
		if(a[i]<b[i]) return true;
		else if(a[i]>b[i]) return false;
		else continue;
	}
}

void merge(struct words *a, int p, int q, int r)
{
	int pos = p, posa = p, posb = q+1;
	while(posa<=q&&posb<=r)
	{
		if (a[posa].len<a[posb].len) tmp[pos++] = a[posa++];
		else if (a[posa].len>a[posb].len) tmp[pos++] = a[posb++];
		else
		{
			if(dic(a[posa].word, a[posb].word)) tmp[pos++] = a[posa++];
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

void mergesort(struct words *a, int p, int r)
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
		scanf(" %s", w[i].word);
		w[i].len = strlen(w[i].word);
	}
	mergesort(w, 0, n-1);
	for(int i=0;i<n;i++)
	{
		if(strcmp(w[i].word, w[i+1].word))
			printf("%s\n", w[i].word);
		else continue;
	}
	return 0;
}