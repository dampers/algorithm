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
	int n, s;
	cin>>n>>s;
	lld sum = 0LL, k = (lld)s/n;
	if(k==1LL)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n-1;i++)
	{
		cout<<k<<' ';
	}
	cout<<s-k*(n-1)<<endl;
	cout<<s-1<<endl;
	return 0;
}