#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
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
		vector<int> v(n+1, 0);
		v[1] = 1;
		v[2] = 2;
		v[3] = 3;
		for(int i=4;i<=n;i++)
			v[i] = (v[i-1]+v[i-2])%1000000007;
		cout<<v[n]<<endl;
	}
	return 0;
}