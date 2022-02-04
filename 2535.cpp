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

	int n;
	cin >> n;
	vector<pair<int, pii>> v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i].second.first >> v[i].second.second >> v[i].first;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	vector<int> country(n+1, 0);

	int cnt = 0;
	for(auto& K : v)
	{
		if(cnt < 3)
		{
			if(country[K.second.first] < 2)
			{
				cnt++;
				country[K.second.first]++;
				cout << K.second.first << ' ' << K.second.second << endl;
			}
		}
		else break;
	}
	return 0;
}
