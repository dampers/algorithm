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
		vector<lld> v(n, 0LL);
		for(int i=0;i<n;i++)
			cin>>v[i];
		lld ans = 0LL;
		for(int i=0;i<n-1;i++)
			ans += abs(v[i+1]-v[i]);
		lld sum = ans;
		ans = min(ans-abs(v[1]-v[0]), ans-abs(v[n-1]-v[n-2]));
		for(int i=1;i<n-1;i++)
			ans = min(ans, sum-abs(v[i]-v[i-1])-abs(v[i+1]-v[i])+abs(v[i+1]-v[i-1]));
		cout<<ans<<endl;
	}
	return 0;
}