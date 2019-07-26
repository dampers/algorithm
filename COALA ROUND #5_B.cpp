#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int num[105];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(num[i]+num[j]==num[k])
				{
					cout<<k+1<<' '<<j+1<<' '<<i+1;
					return 0;
				}
			}
		}
	}
	printf("-1");
	return 0;
}