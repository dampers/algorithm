#include<bits/stdc++.h>

using namespace std;

int num[9], check[9];
int n, m;

void sf(int pos)
{
	if(pos==m)
	{
		for(int i=0;i<m;i++) printf("%d ", num[i]);
		printf("\n");
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(check[i]==0)
		{
			check[i] = 1;
			num[pos] = i+1;
			sf(pos+1);
			check[i] = 0;
		}
	}
	
}

int main()
{
	scanf("%d %d", &n, &m);
	sf(0);
	return 0;
}
