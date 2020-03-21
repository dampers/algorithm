#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool comp(pair<int, int> a, pair<int, int> b)
{

	if(a.second==b.second) return a.first>b.first;
	return a.second>b.second;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int l, n, f, b;
	cin>>l>>n>>f>>b;
	vector<pair<int, int>> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first>>v[i].second;
	}
	sort(v.begin(), v.end(), comp);
	lld ans = 0LL, on = 0LL;
	for(int i=0;i<n;i++)
	{
		if(on>=v[i].first) continue;
		lld bt = (v[i].first-on)*b;
		lld ft = (v[i].first-on)*f;
		ans += (ft-bt)*v[i].second;
		on = (lld)v[i].first;
	}
	cout<<ans;
	return 0;
}