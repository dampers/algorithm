#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.first<b.first;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<pair<int, int>> v;
	for(int i=0;i<11;i++)
	{
		int d, a;
		cin>>d>>a;
		v.push_back({d, 20*a});
	}
	sort(v.begin(), v.end(), comp);
	int ans = 0, t = 0;
	for(int i=0;i<11;i++)
	{
		ans += t+v[i].first+v[i].second;
		t += v[i].first;
	}
	cout<<ans;
	return 0;
}