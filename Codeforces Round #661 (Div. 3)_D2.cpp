#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int res[200005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		set<int> zero, one;
		memset(res, 0, sizeof(res));
		bool flag = false;
		int cnt = 0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='0')
			{
				if(one.empty())
				{
					zero.insert(++cnt);
					res[i] = cnt;
				}
				else
				{
					res[i] = *one.begin();
					zero.insert(res[i]);
					one.erase(res[i]);
				}
			}
			else
			{
				if(zero.empty())
				{
					one.insert(++cnt);
					res[i] = cnt;
				}
				else
				{
					res[i] = *zero.begin();
					one.insert(res[i]);
					zero.erase(res[i]);
				}
			}
		}
		cout<<cnt<<endl;
		for(int i=0;i<n;i++)
			cout<<res[i]<<' ';
		cout<<endl;
	}

	return 0;
}