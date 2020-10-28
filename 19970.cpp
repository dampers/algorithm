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
	int n;
	cin>>n;
	vector<int> v(n), orgin(n);
	for(int i=0;i<n;i++)
	{
		cin>>orgin[i];
		v[i] = orgin[i];
	}
	sort(v.begin(), v.end());
	map<int, int> mp;
	int cnt = 1;
	for(int i=0;i<n;i++)
		if(mp[v[i]]==0) mp[v[i]] = cnt++;
	for(int i=0;i<n;i++)
		cout<<mp[orgin[i]]-1<<' ';
	return 0;
}