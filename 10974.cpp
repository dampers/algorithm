#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int num[9];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		num[i] = i;
		cout<<num[i]<<' ';
	}
	cout<<'\n';
	lld p = n;
	for(int i=2;i<n;i++)
		p *= i;
	p--;
	while(p--)
	{
		next_permutation(num+1, num+n+1);
		for(int i=1;i<=n;i++)
		{
			cout<<num[i]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}