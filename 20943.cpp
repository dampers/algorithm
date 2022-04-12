#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int gcd(int a, int b)
{
	if(a < b) return gcd(b, a);
	if(b == 0) return a;
	return gcd(b, a%b);
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<pii, int>> v(n);
	map<pii, int> mp;
	int vgcd;
	for(int i=0;i<n;i++)
	{
		cin >> v[i].first.first >> v[i].first.second >> v[i].second;
		vgcd = 1;
		if(v[i].first.first == 0) mp[{0, 1}]++;
		else if(v[i].first.second == 0) mp[{1, 0}]++;
		else
		{
			vgcd = gcd(abs(v[i].first.first), abs(v[i].first.second));
			if(v[i].first.first * v[i].first.second > 0)
				mp[{abs(v[i].first.first/vgcd), abs(v[i].first.second/vgcd)}]++;
			else if(v[i].first.first * v[i].first.second < 0)
				mp[{-abs(v[i].first.first/vgcd), abs(v[i].first.second/vgcd)}]++;
		}
	}

	int ans = n * (n-1) / 2;
	for(auto &K : mp)
	{
		if(K.second > 1)
		{
			ans -= K.second * (K.second-1) / 2;
		}
	}
	cout << ans;


	return 0;
}
