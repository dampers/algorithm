#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	map<pair<int, int>, int> mp;
	int cnt = 0, n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j*i<=n;j++)
		{
			if(mp[make_pair(i, j)]==0)
			{
				mp[make_pair(i,j)] = 1;
				mp[make_pair(j, i)] = 1;
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}