#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int dp[100005];


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int a, b;
		cin>>a>>b;
		string s;
		cin>>s;
		vector<pair<int, int>> v;
		
		bool flag = false;
		pair<int, int> tmp;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='1' && !flag)
			{
				tmp.first = i;
				flag = true;
			}
			if(s[i]=='0' && flag)
			{
				tmp.second = i-1;
				flag = false;
				v.push_back({tmp});
			}
		}
		if(s[s.size()-1]=='1')
		{
			v.push_back({tmp.first, s.size()-1});
		}
		int ans = a;
		flag = false;
		if(v.size()>=2)
		{
			for(int i=0;i<v.size()-1;i++)
			{
				int tmp = v[i+1].first-v[i].second-1;
				if(tmp*b<a) ans += tmp*b;
				else ans += a;
			}
			cout<<ans<<endl;
		}
		else if(v.size()==1) cout<<a<<endl;
		else cout<<0<<endl;
	}
	return 0;
}