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
		lld x, y, a, b;
		cin>>x>>y>>a>>b;
		if(x==0LL && y==0LL)
		{
			cout<<0<<endl;
			continue;
		}
		lld sum = 0LL;
		if(x*y>0)
		{
			x = abs(x);
			y = abs(y);
			sum = min((x+y)*a, min(x, y)*b+abs(x-y)*a);
		}
		else
		{
			sum = (abs(x)+abs(y))*a;
		}
		cout<<sum<<endl;
	}
	
	return 0;
}