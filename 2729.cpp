#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void carring(string &a, int &carry, string &ans, int mn)
{
	for(size_t i=mn;i<a.length();i++)
	{
		int at = a[i]-'0';
		if((at+carry) % 2) ans.push_back('1');
		else ans.push_back('0');
		if((at+carry) >= 2) carry = 1;
		else carry = 0;
	}
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
		string a, b;
		cin >> a >> b;
		string ans = "";
		size_t mn = min(a.length(), b.length());
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int carry = 0;
		for(size_t i=0;i<mn;i++)
		{
			int at = a[i]-'0', bt = b[i]-'0';
			if((at+bt+carry) % 2) ans.push_back('1');
			else ans.push_back('0');
			if((at+bt+carry) >= 2) carry = 1;
			else carry = 0;
		}
		carring(a, carry, ans, mn);
		carring(b, carry, ans, mn);
		if(carry) ans.push_back('1');
		while(ans.back() == '0' && ans.length() > 1) ans.pop_back();
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}

	return 0;
}
