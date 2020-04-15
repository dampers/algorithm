#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
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
		int x, n, m;
		cin>>x>>n>>m;
		while(n>0 || m>0)
		{
			if(x<=10 && m>0)
			{
				m--;
				x -= 10;
				break;
			}
			else if(n>0)
			{
				n--;
				x = x/2 + 10;
			}
			else if(m>0)
			{
				m--;
				x -= 10;
			}
		}
		if(x>0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	
	return 0;
}