#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
lld cnt[200004];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int tmp;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		cnt[tmp]++;
	}
	lld ans = 0, res = 0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]>0)
		{
			res += cnt[i]-1;
			ans += i;
		}
		else if(res>0 && cnt[i]==0)
		{
			res--;
			ans += i;
		}
		//cout<<ans<<' '<<res<<' '<<i<<endl;
	}
	cout<<ans<<endl;
	return 0;
}