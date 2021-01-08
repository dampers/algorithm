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
		int k, num;
		map<int, int> mp;
		cin>>k;
		char order;
		for(int i=0;i<k;i++)
		{
			cin>>order>>num;
			if(order=='I') mp[num] += 1;
			if(order=='D')
			{
				map<int, int>::iterator it;
				if(mp.empty()) continue;
				if(num==1)
				{
					it = mp.end();
					it--;
					it->second -= 1;
					if(it->second==0) mp.erase(it);
				}
				if(num==-1)
				{
					it = mp.begin();
					it->second -= 1;
					if(it->second==0) mp.erase(it);
				}
			}	
		}
		if(mp.empty()) cout<<"EMPTY\n";
		else
		{
			map<int, int>::iterator a = mp.begin(), b = mp.end();
			b--;
			cout<<b->first<<' '<<a->first<<endl;
		}
	}

	return 0;
}