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
		int n, k;
		cin>>n>>k;
		vector<int> v(n+1, 0);
		for(int i=1;i<=k;i++)
			v[i] = i;
		for(int i=1;i<=(n-k);i++)
		{
			v[k+i] = k-i;
		}
		int kn = 2*k-n;
		for(int i=1;i<kn;i++)
			cout<<i<<' ';
		for(int i=k;i>=kn;i--)
			cout<<i<<' ';
		cout<<endl;
	}
	return 0;
}