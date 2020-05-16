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
		lld a, k;
		cin>>a>>k;
		if(k==1LL)
		{
			cout<<a<<endl;
			continue;
		}

		lld tmp = a, ttmp = a;
		for(lld i=0;i<k-1;i++)
		{
			tmp = ttmp;
			int mn = 10, mx = 0;
			while(tmp)
			{
				if(tmp%10>mx) mx = tmp%10;
				if(tmp%10<mn) mn = tmp%10;
				tmp /= 10;
			}
			cout<<mx<<' '<<mn<<endl;
			ttmp += (lld)mx*mn;
			if(mn==0) break;
		}
		cout<<ttmp<<endl;
	}
	return 0;
}