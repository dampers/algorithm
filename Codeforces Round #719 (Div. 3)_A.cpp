#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
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
		string s;
		cin >> s;
		vector<bool> check(26, false);
		bool flag = false;
		check[s[0]-'A'] = true;
		for(size_t i=1;i<s.size();i++)
		{
			//cout << s[i] << ' ' << s[i-1] << endl;
			if(check[s[i]-'A'] && s[i] != s[i-1])
			{
				flag = true;
				break;
			}
			check[s[i]-'A'] = true;
		}
		if(!flag) cout << "YES" <<endl;
		else cout << "NO" <<endl;
	}

	return 0;
}