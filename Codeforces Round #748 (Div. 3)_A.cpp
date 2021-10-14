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
 
	int tc;
	cin >> tc;
	while(tc--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int mx = max({a, b, c});
		int cnt = 0;
		if(a == mx) cnt++;
		if(b == mx) cnt++;
		if(c == mx) cnt++;
		if(mx == a && cnt == 1) cout << 0 << ' ';
		else cout << mx+1-a << ' ';
		if(mx == b && cnt == 1) cout << 0 << ' ';
		else cout << mx+1-b << ' ';
		if(mx == c && cnt == 1) cout << 0 << ' ';
		else cout << mx+1-c << ' ';
		cout << endl;
	}

	return 0;
}