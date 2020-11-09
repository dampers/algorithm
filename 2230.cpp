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
	lld m;
	cin>>n>>m;
	vector<lld> v(n, 0LL);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(), v.end());
	int l = 0, r = 0;
	lld ans = LLONG_MAX;
	while(r<n && l<n)
	{
		if(v[r]-v[l]>m)
		{
			ans = min(ans, v[r]-v[l]);
			l++;
		}
		else if(v[r]-v[l]==m)
		{
			ans = m;
			break;
		}
		else r++;
	}
	cout<<ans;
	return 0;
}