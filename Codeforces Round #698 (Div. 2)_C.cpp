#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin>>tc;
	while(tc--)
	{
		lld n;
		cin>>n;
		vector<lld> v(n*2, 0LL);
		vector<lld> ansv;
		bool flag = true;
		map<lld, int> mp;
		for(size_t i=0;i<v.size();i++)
		{
			cin>>v[i];
			if(v[i] % 2LL) flag = false;
			mp[v[i]]++;
		}
		for(auto &k : mp)
		{
			if(k.second != 2) flag = false;
			ansv.push_back(k.first/2);
		}
		if(!flag)
		{
			cout<<"NO"<<endl;
			continue;
		}

		sort(ansv.rbegin(), ansv.rend());
		
		lld subs = 0LL;
		for(size_t i=0;i<ansv.size();i++)
		{
			ansv[i] -= subs;
			if(ansv[i] <= 0 || ansv[i] % (ansv.size()-i))
			{
				flag = false;
				break;
			}
			subs += ansv[i] / (ansv.size()-i);
			
			//cout<<subs<<endl;
		}
		if(!flag)
		{
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
	}

	return 0;
}

