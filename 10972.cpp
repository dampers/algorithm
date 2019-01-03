#include<bits/stdc++.h>
using namespace std;
int num[10001], check[10001];
int n, flag = 0;

void sf(int pos)
{
	if(flag==1) return;
	if(pos==n)
	{
		for(int i=0;i<n;i++) printf("%d ", num[i]);
		printf("\n");
		flag = 1;
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
	int k = 1;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %d", &num[i]);
		check[num[i]] = 1;
		if(i>0)	if(num[i-1]-num[i]==1) k++;
	}
	if(k==n) printf("-1");
	else sf(0);
	return 0;
}
