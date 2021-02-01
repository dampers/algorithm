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
		int np, nq, n;
		cin>>n;
		map<int, int> mp;
		int ans = 0;
		for(int i=0;i<n;i++)
		{
			cin>>np>>nq;
			
			auto it = mp.lower_bound(np);
			// can insert
			if(it == mp.begin())
			{
				if(mp.begin() == mp.end() || mp.begin()->second < np) mp[np] = nq;
			}
			else mp[np] = nq;

			// erase
			it = mp.lower_bound(np);
			for(auto k = mp.begin(); k != it;)
			{
				if(k->second > nq) k++;
				else k = mp.erase(k);
			}
			ans += mp.size();
		}
		cout<<ans<<endl;
	}
	return 0;
}