#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if(a.first==b.first) return a.second>b.second;
	return a.first>b.first;
}

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
		vector<pair<lld, lld>> v(n);
		lld ans = 0LL;
		for(int i=0;i<n;i++)
		{
			cin>>v[i].first;
			ans = max(v[i].first, ans);
		}
		for(int i=0;i<n;i++)
			cin>>v[i].second;
		sort(v.begin(), v.end(), compare);
		lld pick = 0LL;
		bool flag = false;
		for(int i=0;i<n-1;i++)
		{
			if(ans>pick+v[i].second)
			{
				ans = max(v[i+1].first, v[i].second+pick);
				pick += v[i].second;
			}
			else
			{
				flag = true;
				break;
			}
		}
		if(!flag && ans>v[n-1].second+pick) ans = v[n-1].second+pick;

		cout<<ans<<endl;
	}
	return 0;
}