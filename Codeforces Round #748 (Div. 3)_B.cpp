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
		string s;
		cin >> s;
		int finds = -1, zinds = -1;
		for(size_t i=0;i<s.length();i++)
		{
			if(s[i] == '5') finds = i;
			if(s[i] == '0') zinds = i;
		}
		int atmp = -1, btmp = -1;
		int aans = -1, bans = -1;
		if(finds >= 0)
		{
			for(int i=0;i<finds;i++)
			{
				if(s[i] == '2' || s[i] == '7')
				{
					atmp = i;
				}
			}
			if(atmp >= 0)
				aans = (s.length()-finds-1) + (finds-atmp-1);
		}
		if(zinds >= 0)
		{
			for(int i=0;i<zinds;i++)
			{
				if(s[i] == '5' || s[i] == '0')
				{
					btmp = i;
				}
			}
			if(btmp >= 0)
				bans = (s.length()-zinds-1) + (zinds-btmp-1);
		}
		if(aans == -1) cout << bans << endl;
		else if(bans == -1) cout << aans << endl;
		else cout << min(aans, bans) << endl;

	}

	return 0;
}