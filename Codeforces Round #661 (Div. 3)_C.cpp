#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
 
int num[55], sum[505];
 
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int ntmp;
		memset(num, 0, sizeof(num));
		memset(sum, 0, sizeof(sum));
		for(int i=0;i<n;i++)
		{
			cin>>ntmp;
			num[ntmp]++;
		}
		int mxcnt = 0;
		for(int i=1;i<=n;i++)
		{
			sum[2*i] += num[i]/2;
			for(int j=i+1;j<=n;j++)
			{
				sum[i+j] += min(num[i], num[j]);
			}
		}
		for(int i=2;i<=101;i++)
		{
			if(mxcnt<sum[i]) mxcnt = sum[i];
		}
		cout<<mxcnt<<endl;
	}
 
	return 0;
}