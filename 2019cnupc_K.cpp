#include <bits/stdc++.h>
using namespace std;
int a[101][101];

struct Key
{
	int s;
	int num;
	char b;
} key[1001];

bool cmp(struct Key &a, struct Key &b)
{
	if(a.s==b.s)
	{
		return a.num<b.num;
	}
	return a.s<b.s;
}

int main()
{
	int n, m;
	scanf(" %d %d", &n, &m);
	for(int i=0;i<m;i++)
	{
		scanf(" %d %d %c", &key[i].num, &key[i].s, &key[i].b);	
	}
	sort(key, key+m, cmp);
	for(int i=0;i<m;i++)
		printf("%c", key[i].b);
	return 0;
}
