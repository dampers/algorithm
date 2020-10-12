#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int makedist(pair<int, int> a, pair<int, int> b)
{return abs(a.first-b.first)+abs(a.second-b.second);}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	vector<pair<int, int>> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i].first>>v[i].second;
	int x = v[0].first, y = v[0].second;
	vector<int> dist(n-1);
	lld mn = LLONG_MAX, origin = 0LL;
	for(int i=0;i<n-1;i++)
	{
		dist[i] = makedist(v[i], v[i+1]);
		origin += dist[i];
	}
	mn = origin;
	for(int i=1;i<n-1;i++)
	{
		lld tmp = origin-dist[i]-dist[i-1]+makedist(v[i-1], v[i+1]);
		mn = min(tmp, mn);
	}
	cout<<mn;

	return 0;
}