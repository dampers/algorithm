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
	vector<lld> v(n, 0LL);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(), v.end());
	lld ans = 0LL;
	for(vector<lld>::iterator it=v.begin();it!=v.end();it++)
	{
		if(it==v.begin()) continue;
		lld target = (lld)ceil((*it)*0.9);
		vector<lld>::iterator lower = lower_bound(v.begin(), it, target);
		ans +=  it-lower;
	}
	cout<<ans;
	return 0;
}