#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void recurr(string& s, int pos, vector<bool>& check, string& ps)
{
	if(pos == s.length())
	{
		cout << ps << endl;
		return;
	}
	char pre = 0;
	for(size_t i=0;i<s.length();i++)
	{
		if(check[i] || pre == s[i]) continue;
		check[i] = true;
		ps[pos] = s[i];
		recurr(s, pos+1, check, ps);
		check[i] = false;
		pre = s[i];
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
		string s, ps;
		cin >> s;
		ps = s;
		sort(s.begin(), s.end());
		vector<bool> check(s.length(), false);
		recurr(s, 0, check, ps);
	}

	return 0;
}