#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

lld hd[3][300005];
int posk[300005];
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
		int kill = 0;
		for(int i=0;i<n;i++)
		{
			cin>>hd[0][i]>>hd[1][i];
		}
		lld sum = 0LL;
		for(int i=1;i<n;i++)
		{
			hd[2][i] = hd[0][i]-hd[1][i-1]>0?hd[0][i]-hd[1][i-1]:0;
			sum += hd[2][i];
		}
		hd[2][0] = hd[0][0]-hd[1][n-1]>0?hd[0][0]-hd[1][n-1]:0;
		sum += hd[2][0];
		lld mn = sum + hd[0][0];
		for(int i=0;i<n;i++)
		{
			if(mn>sum-hd[2][i]+hd[0][i])
			{
				mn = sum-hd[2][i]+hd[0][i];
			}
		}
		cout<<mn<<endl;
	}
	return 0;
}