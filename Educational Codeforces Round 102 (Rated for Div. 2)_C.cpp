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

		if(n-k==0)
		{
			for(int i=1;i<=k;i++)
				cout<<i<<" ";
			cout<<endl;
		}
		else if(n-k==1)
		{
			for(int i=1;i<k-1;i++)
			{
				cout<<i<<' ';
			}
			cout<<k<<' ';
			cout<<k-1<<endl;
		}
		else
		{
			int kn = 2*k-n;
			for(int i=1;i<kn;i++)
				cout<<i<<' ';
			cout<<k<<' ';
			for(int i=k-1;i>=kn;i--)
				cout<<i<<' ';
			cout<<endl;
		}
	}
	return 0;
}