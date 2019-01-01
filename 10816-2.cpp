# include <bits/stdc++.h>

using namespace std;

int cnt[20000005];

int main()
{
	int n, tmp;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %d", &tmp);
		if(tmp>0) tmp += 10000000;
		else tmp*=-1;
		cnt[tmp]++;
	}
	int m;
	scanf(" %d", &m);
	for(int i=0;i<m;i++)
	{
		scanf(" %d", &tmp);
		if(tmp>0) tmp += 10000000;
		else tmp*=-1;
		printf("%d ", cnt[tmp]);
		
	}
	return 0;
}
