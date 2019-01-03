#include<bits/stdc++.h>
using namespace std;
int num[9], check[9], tab[9];
int n, m;

void sf(int pos)
{
	if(pos==m)
	{
		for(int i=0;i<m;i++)
		{
			printf("%d ", num[i]);
		}
		printf("\n");
		return;
	}
	for(int i=0;i<n;i++)
	{
		check[i] = 1;
		num[pos] = tab[i];
		sf(pos+1);
		check[i] = 0;
	}
	
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++) scanf(" %d", &tab[i]);
	sort(tab, tab+n);
	sf(0);
	return 0;
}
