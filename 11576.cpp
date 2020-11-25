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
	lld a, b;
	cin>>a>>b;
	int m;
	cin>>m;
	vector<int> v(m);
	for(int i=0;i<m;i++)
		cin>>v[i];
	unsigned long long total = v[m-1];
	lld exa = a;
	for(int i=m-2;i>=0;i--)
	{
		total += exa*v[i];
		exa *= a;
	}
	vector<int> ans;
	if(total==0LL) cout<<0;
	else
	{
		while(total)
		{
			ans.push_back(total%b);
			total /= b;
		}
		reverse(ans.begin(), ans.end());
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<' ';
	}
	return 0;
}