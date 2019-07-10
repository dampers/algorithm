#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	lld mx = 0, tmp;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		mx = max(mx, tmp);
	}
	cout<<mx;
	return 0;
}