#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

lld num[100005];

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
		lld x;
		cin>>n>>x;
		lld sum = 0LL;
		for(int i=0;i<n;i++)
		{
			cin>>num[i];
			sum += num[i];
		}
		sort(num, num+n);
		lld evg = sum/n;
		int ind = -1;
		if(evg>=x)
		{
			cout<<n<<endl;
			continue;
		}
		for(int i=0;i<n-1;i++)
		{
			sum -= num[i];
			evg = sum/(n-i-1);
			ind = i;
			if(evg>=x)
			{
				break;
			}
		}
		if(ind==n-2)
		{
			if(num[n-2]>=x) cout<<2<<endl;
			else if(num[n-1]>=x) cout<<1<<endl;
			else cout<<0<<endl;
		}
		else cout<<n-ind-1<<endl;
	}
	return 0;
}