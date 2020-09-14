#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
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
		lld x, y, k;
		cin>>x>>y>>k;
		lld sticks = y*k + k-1;
		cout<<sticks/(x-1)<<' '<<sticks%(x-1)<<endl;
		lld ans = sticks/(x-1)+k+(sticks%(x-1)?1:0);
		cout<<ans<<endl;
	}
	return 0;
}