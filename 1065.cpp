#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int k[4];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	if(n<100)
		cout<<n;
	else
	{
		int cnt = 99;
		for(int i=111;i<=n;i++)
		{
			int tmp = i;
			if(tmp<1000)
			{
				k[2] = tmp%10;
				tmp /= 10;
				k[1] = tmp%10;
				tmp /= 10;
				k[0] = tmp%10;
				if(k[0]-k[1]==k[1]-k[2]) cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}