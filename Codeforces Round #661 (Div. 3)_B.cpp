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
		int n;
		cin>>n;
		vector<lld> a(n), b(n);
		lld mina = (lld)1e10+1, minb = (lld)1e10+1;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			mina = min(a[i], mina);
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			minb = min(b[i], minb);
		}
		lld cnt = 0LL;
		for(int i=0;i<n;i++)
		{
			cnt += max(a[i]-mina, b[i]-minb);
		}
		cout<<cnt<<endl;
 
	}
 
	return 0;
}