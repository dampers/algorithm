#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		double x, y, xx, yy;
		cin>>x>>y>>xx>>yy;
		int n, cnt = 0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			double a, b, r;
			cin>>a>>b>>r;
			if((r*r>(a-x)*(a-x)+(b-y)*(b-y)) ^ (r*r>(a-xx)*(a-xx)+(b-yy)*(b-yy))) cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}