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
 
	string s;
	cin >> s;
	string ans(s);
	for(int i=0;i<4;i++)
		ans.push_back('0');
	reverse(s.begin(), s.end());
	reverse(ans.begin(), ans.end());
	int carry = 0;
	for(size_t i=0;i<ans.length();i++)
	{
		int ansi = ans[i]=='1'?1:0;
		int si = s[i]=='1'?1:0;
		int tmp = ansi + si + carry;
		if(tmp == 1 || tmp == 3) ans[i] = '1';
		if(tmp == 0 || tmp == 2) ans[i] = '0';
		if(tmp >= 2) carry = 1;
		else carry = 0;
	}
	if(carry) ans.push_back('1');
	reverse(ans.begin(), ans.end());
	cout << ans;

	return 0;
}