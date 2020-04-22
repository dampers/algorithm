#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int num[200005];

bool comp(pair<int, int> a, pair<int, int> b)
{
	if(a.second==b.second) return a.first<b.first;
	else return a.second>b.second;
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
		int n, k;
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			cin>>num[i];
		}
		map<int, int> mp;
		mp.clear();
		int l = -5e5, r = 5e5;
		for(int i=0;i<n/2;i++)
		{
			int key = num[i]+num[n-i-1];
			mp[key]++;
			l = max(l, 1+min(num[i], num[n-i-1]));
			r = min(r, k+max(num[i], num[n-i-1]));
		}
		vector<pair<int, int>> v;
		v.clear();
		for(map<int, int>::iterator it=mp.begin();it!=mp.end();it++)
		{
			v.push_back({(*it).first, (*it).second});
		}
		sort(v.begin(), v.end(), comp);
		//cout<<l<<" <= x <= "<<r<<endl;
		bool flag = false;
		for(int i=0;i<v.size();i++)
		{
			if(v[i].first>=l && v[i].first<=r)
			{
				flag = true;
				cout<<n/2-v[i].second<<endl;
				break;
			}
		}
		if(!flag) cout<<n/2<<endl;
	}
	
	return 0;
}