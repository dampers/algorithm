#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int coincnt[100040];
int coin[103];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>coin[i];
		coincnt[coin[i]] = 1;

	}
	int tmp;
	for(int i=0;i<k;i++)
	{
		if(coincnt[i])
		{
			int ctmp = coincnt[i]+1;
			for(int j=0;j<n;j++)
			{
				tmp = i+coin[j];
				if(tmp>k) continue;
				if(coincnt[tmp]>ctmp || coincnt[tmp]==0)
				{
					coincnt[tmp] = ctmp;
					//printf("coincnt[%d] = %d\n", tmp, ctmp);
				}
			}
		}
	}
	if(coincnt[k])
	{
		printf("%d", coincnt[k]);
	}
	else
		printf("-1");
	return 0;
}
