#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int m, n;
	cin >> n >> m;
	vector<pii> v(n, {0, 0});
	for(int i=0;i<n;i++)
	{
		v[i].second = i+1;
		cin >> v[i].first;
		for(int j=0;j<i;j++)
		{
			if(v[i].first <= v[j].first) v[j].first++;
		}
	}
	sort(v.begin(), v.end());
	vector<pii> race(v.begin(), v.begin()+m);
	for(int i=m-1;i>=0;i--)
	{
		cin >> race[i].first;
		for(int j=i+1;j<m;j++)
		{
			if(race[i].first <= race[j].first) race[j].first++;
		}
	}
	sort(race.begin(), race.end());
	for(int i=0;i<3;i++) cout << race[i].second << endl;

	return 0;
}
