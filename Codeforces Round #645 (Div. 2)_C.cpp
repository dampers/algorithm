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
		lld x, y, xx, yy;
		cin>>x>>y>>xx>>yy;
		if(x-xx==0 || y-yy==0)
		{
			cout<<1<<endl;
			continue;
		}
		else if(abs(x-xx)==1 || abs(y-yy)==1)
		{
			cout<<abs(x-xx)+abs(y-yy)<<endl;
			continue;
		}
		lld mx = max(abs(x-xx), abs(y-yy));
		lld mn = min(abs(x-xx), abs(y-yy));
		lld ans = mn*(mn-1)+(mx-mn+1)*mn+1;
		cout<<ans<<endl;

	}
	
	return 0;
}