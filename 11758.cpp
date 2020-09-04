#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

lld ccw(lld x1, lld y1, lld x2, lld y2, lld x3, lld y3)
{
	return x1*y2 + x2*y3 + x3*y1 - (y1*x2 + y2*x3 + y3*x1);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<pair<lld, lld>> v(3);
	for(int i=0;i<3;i++)
	{
		cin>>v[i].first>>v[i].second;
	}
	lld res = ccw(v[0].first, v[0].second, v[1].first, v[1].second, v[2].first, v[2].second);
	if(res>0) cout<<1;
	else if(res<0) cout<<-1;
	else cout<<0;
	return 0;
}