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
	int n, m, M, t, r, x;
	cin>>n>>m>>M>>t>>r;
	x = m;
	if(M-m<t)
	{
		cout<<-1;
		return 0;
	}
	for(int i=1;;i++)
	{

		if(x+t>M)
		{
			x -= r;
			if(x<m) x = m;
		}
		else
		{
			x += t;
			n--;
		}
		if(!n)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}