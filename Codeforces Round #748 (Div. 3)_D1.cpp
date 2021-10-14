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
	if(b > a) return gcd(b, a);
	if(b == 0) return a;
	return gcd(b, a%b);
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
		vector<int> v(n, 0);
		for(int i=0;i<n;i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		int mx = v.back(), mn = v.front();
		if(mx - mn == 0)
		{
			cout << -1 << endl;
			continue;
		}
		set<int> st;
		for(int i=0;i<n;i++)
		{
			if(v[i]-mn > 0) st.insert(v[i]-mn);
		}
		int ans = *st.begin();
		for(auto &K : st)
		{
			ans = gcd(ans, K);
		}
		cout << ans << endl;
	}

	return 0;
}