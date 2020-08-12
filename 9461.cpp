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
	vector<lld> v(101);
	v[1] = v[2] = v[3] = 1LL;
	v[4] = v[5] = 2LL;
	for(int i=6;i<101;i++)
	{
		v[i] = v[i-1]+v[i-5];
	}
	while(tc--)
	{
		int n;
		cin>>n;
		cout<<v[n]<<endl;
	}
	return 0;
}