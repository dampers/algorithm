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
		lld x;
		cin>>n>>x;
		vector<lld> d(n, 0LL), h(n, 0LL);
		int ind = 0;
		lld ans = -1;
		lld mx = 0;
		for(int i=0;i<n;i++)
		{
			cin>>d[i]>>h[i];
			mx = max(d[i], mx);
		}
		if(x<=mx)
		{
			cout<<1<<endl;
			continue;
		}
		while(d[ind]-h[ind]<=0 && ind<n)
		{
			ind++;
		}
		x -= mx;
		for(int i=0;i<n;i++)
		{
			
			if(d[i]-h[i]>0)
			{
				if(x/(d[ind]-h[ind])+(x%(d[ind]-h[ind])?1:0)>=x/(d[i]-h[i])+(x%(d[i]-h[i])?1:0))
				{
					ans = x/(d[i]-h[i])+(x%(d[i]-h[i])?1:0);
					ind = i;
				}
			}
		}
		if(ind==n)
		{
			cout<<-1<<endl;
			continue;
		}
		cout<<ans+1<<endl;
		
	}
	return 0;
}