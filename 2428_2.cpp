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
	int l = 0, r = 1;
	while(r<n)
	{
		lld stand = (lld)ceil(v[r]*0.9);
		while (stand>v[l] && l<r) l++;
		ans += r-l;
		r++;
	}
	cout<<ans;
	return 0;
}