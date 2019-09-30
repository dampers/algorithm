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
		int h, w, n;
		cin>>h>>w>>n;
		int k = n%h, t = n/h;
		if(k==0)
		{
			k = h;
			t--;
		}
		printf("%d\n", (k*100+t+1));
	}
	return 0;
}