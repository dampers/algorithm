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
		int n;
		cin>>n;
		map<int, int> mp;
		int ans = 0;
		for(int i=0;i<n;i++)
		{
			int p, q;
			cin>>p>>q;
			auto it = mp.lower_bound(p);
			if(it == mp.end() || q>it->second)
			{
				if(it != mp.begin())
				{
					--it;
					while(1)
					{
						if(it->second > q) break;
						if(it == mp.begin())
						{
							mp.erase(it);
							break;
						}
						else
						{
							auto jt = it;
							--jt;
							mp.erase(it);
							it = jt;
						}
					}
				}
				mp[p] = q;
			}
			ans += mp.size();
		}
		cout<<ans<<endl;

	}

	return 0;
}