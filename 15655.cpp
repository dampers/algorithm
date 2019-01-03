#include<bits/stdc++.h>
using namespace std;
int num[9], check[9], tab[9];
int n, m;

void sf(int pos)
{
	if(pos==m)
	{
		int flag = 1;
		for(int i=1;i<m;i++)
		{
			if(num[i-1]<num[i]) flag++;
		}
		for(int i=0;i<m;i++)
		{
			if(flag == m) printf("%d ", num[i]);
		}
		if(flag == m) printf("\n");
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(check[i]==0)
		{
			check[i] = 1;
			num[pos] = tab[i];
			sf(pos+1);
			check[i] = 0;
		}
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
