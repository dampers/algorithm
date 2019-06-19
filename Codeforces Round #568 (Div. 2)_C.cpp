#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int num[200001];
int nnum[200001];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, d, sum = 0;
	cin>>n>>d;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			nnum[j] = num[j];
		}
		sort(nnum, nnum+i);
		sum += num[i];
		if(sum>d)
		{
			int ssum = sum, cnt = 0;
			for(int j=i-1;j>=0;j--)
			{
				cnt++;
				ssum -= nnum[j];
				if(ssum<=d)
				{
					printf("%d ", cnt);
					break;
				}
			}
		}
		else
			printf("0 ");
	}

	return 0;
}