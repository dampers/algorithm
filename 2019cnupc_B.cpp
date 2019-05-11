#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int c[100001];
int main()
{
	int n;
	scanf(" %d", &n);
	int sum = 0;
	int mx = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf(" %d", &a[i][j]);
			sum+=a[i][j];
			c[a[i][j]]++;
			if(mx<a[i][j]) mx = a[i][j];
		}
		if(sum%2==0) sum = sum/2;
		else if(sum%2==1) sum=sum/2+1;
	int k = n*n;
	int ssum = 0;
	int cnt = 0;
	for(int i=0;i<=mx;i++)
	{
		if(sum<=ssum) break;
		k -= c[i];
		ssum += k;
		cnt++;
		//printf("sum = %d, ssum = %d\n", sum , ssum);
	}
	printf("%d", cnt);
	return 0;
}
