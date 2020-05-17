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
		lld a, b, c, d;
		cin>>a>>b>>c>>d;
		if(b>=a)
		{
			cout<<b<<endl;
			continue;
		}
		if(d>=c)
		{
			cout<<-1<<endl;
			continue;
		}
		lld res = a-b, ans = b, real = c-d;
		ans += c*(res/real)+(res%real?c:0);
		cout<<ans<<endl;
	}
	
	return 0;
}