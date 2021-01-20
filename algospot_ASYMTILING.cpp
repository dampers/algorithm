#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

#define MOD 1000000007

lld top_down(vector<lld>& v, int pos)
{
	if(pos<=1) return 1;
	lld& ret = v[pos];
	if(v[pos] != -1) return v[pos];
	ret = (top_down(v, pos-1) + top_down(v, pos-2))%MOD;
	return ret;
}

lld asymmetric(vector<lld>& v, int pos)
{
	if(pos%2) return (top_down(v, pos) - top_down(v, pos/2) + MOD) % MOD;
	lld ret = top_down(v, pos);
	ret = (ret - top_down(v, pos/2) + MOD) % MOD;
	ret = (ret - top_down(v, pos/2-1) + MOD) % MOD;
	return ret;
}

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
		vector<lld> v(n+1, -1);
		cout<<asymmetric(v, n)<<endl;
	}
	return 0;
}