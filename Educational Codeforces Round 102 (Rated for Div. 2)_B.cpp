#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

size_t gcd(size_t a, size_t b)
{
	if(a<b) swap(a, b);
	size_t tmp;
	while(b)
	{
		tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin>>tc;
	while(tc--)
	{
		string a, b;
		cin>>a>>b;
		if(a==b)
		{
			cout<<a<<endl;
			continue;
		}
		size_t small = min(a.size(), b.size());
		string pat = "";
		bool flag = false;
		for(size_t i=0;i<small;i++)
		{
			if(a[i]!=b[i]) break;
			if(a[i]==b[i])
			{
				pat += a[i];
				if(a.size()%(i+1)==0 && b.size()%(i+1)==0)
				{
					size_t alen = a.size()/(i+1), blen = b.size()/(i+1);
					string atmp = "";
					string btmp = "";
					for(size_t j=0;j<alen;j++)
					{
						atmp += pat;
					}
					for(size_t j=0;j<blen;j++)
					{
						btmp += pat;
					}
					if(atmp==a && btmp==b)
					{
						flag = true;
						break;
					}
				}
			}
		}
		if(!flag)
		{
			cout<<-1<<endl;
			continue;
		}
		size_t apt = a.size()/pat.size(), bpt = b.size()/pat.size();
		size_t sgcd = gcd(apt, bpt);
		size_t lcm = (apt/sgcd)*bpt;
		string ans = "";
		for(size_t i=0;i<lcm;i++)
			ans += pat;
		cout<<ans<<endl;
	}
	return 0;
}