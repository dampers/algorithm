#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

char check(string  &s)
{
	int ret = 0;
	for(char &C : s)
	{
		ret += C-'0';
	}
	if(ret % 9) return (9-ret%9)+'0';
	return '0';
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for(int t=1;t<=tc;t++)
	{
		cout << "Case #" << t << ": ";
		string s;
		cin >> s;
		char ic = check(s);
		if(ic == '0')
		{
			cout << s[0] << ic << s.substr(1) << endl;
			continue;
		}
		else if(s[0] > ic)
		{
			cout << ic << s << endl;
			continue;
		}
		else if(s.length() == 1)
		{
			int a = (s[0]-'0') * 10 + (ic-'0');
			int b = (ic-'0') * 10 + (s[0]-'0');
			if(a < b) cout << a << endl;
			else cout << b << endl;
			continue;

		}
		else if(s.length() == 2)
		{

			int a = (s[0]-'0') * 100 + (ic-'0') * 10 + (s[1]-'0');
			int b = (s[0]-'0') * 100 + (s[1]-'0') * 10 + (ic-'0');
			if(a < b) cout << a << endl;
			else cout << b << endl;
			continue;
		}
		bool flag = false;
		for(size_t i=1;i<s.length()-1;i++)
		{
			int origin = (s[i-1]-'0') * 100 + (s[i]-'0') * 10 + (s[i+1]-'0');
			int curr = (s[i-1]-'0') * 100 + (ic-'0') * 10 + (s[i+1]-'0');
			if(origin > curr)
			{
				flag = true;
				cout << s.substr(0, i) + ic << s.substr(i, s.length()) << endl;
				break;
			}
		}
		if(!flag)
		{
			int a = (s[s.length()-2]-'0') * 100 + (s.back()-'0') * 10 + (ic-'0');
			int b = (s[s.length()-2]-'0') * 100 + (ic-'0') * 10 + (s.back()-'0');
			if(a < b) cout << s << ic << endl;
			else cout << s.substr(0, s.length()-1) << ic << s.back() << endl;
		}
	}

	return 0;
}