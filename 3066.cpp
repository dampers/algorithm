#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int LIS(vector<int>& sig)
{
	vector<int> v(1, 0);
	for(size_t i=1;i<sig.size();i++)
	{
		if(v.back() < sig[i]) v.push_back(sig[i]);
		else *lower_bound(v.begin(), v.end(), sig[i]) = sig[i];
	}
	int ret = v.size();
	return ret-1;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		vector<int> ltor(n+1, 0), rtol(n+1, 0);
		for(int i=1;i<=n;i++)
		{
			cin >> ltor[i];
			rtol[ltor[i]] = i+1;
		}
		int ans = max(LIS(ltor), LIS(rtol));
		cout << ans << endl;
	}

	return 0;
}
