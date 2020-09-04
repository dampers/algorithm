#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

lld ox, oy;

lld ccw(lld x1, lld y1, lld x2, lld y2, lld x3, lld y3)
{
	return x1*y2 + x2*y3 + x3*y1 - (y1*x2 + y2*x3 + y3*x1);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	cin>>ox>>oy;
	vector<pair<lld, lld>> v(n-1);
	for(int i=0;i<n-1;i++)
	{
		cin>>v[i].first>>v[i].second;
	}
	lld res = 0LL;

	for(int i=0;i<n-2;i++)
	{
		res += ccw(ox, oy, v[i].first, v[i].second, v[i+1].first, v[i+1].second);
	}
	if(res<0) res *= -1;
	if(res%2) cout<<res/2<<".5";
	else cout<<res/2<<".0";

	return 0;
}