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

	string a, b, c, d;
	cin >> a >> b >> c >> d;
	a += b;
	c += d;
	string ans = "";
	reverse(a.begin(), a.end());
	reverse(c.begin(), c.end());
	size_t mn = min(a.length(), c.length());
	int carry = 0;
	for(size_t i=0;i<mn;i++)
	{
		int tmp = (a[i]-'0') + (c[i]-'0') + carry;
		if(tmp >= 10) carry = 1;
		else carry = 0;
		ans.push_back('0'+tmp%10);
	}
	for(size_t i=mn;i<a.length();i++)
	{
		int tmp = (a[i]-'0') + carry;
		if(tmp >= 10) carry = 1;
		else carry = 0;
		ans.push_back('0'+tmp%10);
	}
	for(size_t i=mn;i<c.length();i++)
	{
		int tmp = (c[i]-'0') + carry;
		if(tmp >= 10) carry = 1;
		else carry = 0;
		ans.push_back('0'+tmp%10);
	}
	if(carry) ans.push_back('1');
	reverse(ans.begin(), ans.end());
	cout << ans;

	return 0;
}
