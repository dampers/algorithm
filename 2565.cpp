#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int LIS(vector<int>& lines)
{
	vector<int> v(1, 0);
	for(size_t i=0;i<lines.size();i++)
	{
		if(v.back() < lines[i]) v.push_back(lines[i]);
		else *lower_bound(v.begin(), v.end(), lines[i]) = lines[i];
	}
	int ret = v.size();
	return ret-1;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pii> v(n, {0, 0});
	int a, b;
	for(int i=0;i<n;i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	vector<int> ltor(n, 0), rtol(n, 0);
	for(int i=0;i<n;i++)
	{
		ltor[i] = v[i].second;
		rtol[n-i-1] = v[i].first;
	}
	//cout << LIS(ltor) << ' ' << LIS(rtol) << endl;
	cout << n-max(LIS(ltor), LIS(rtol));

	return 0;
}
