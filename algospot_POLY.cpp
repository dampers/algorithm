#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

#define MOD 10000000
int n;

int top_down(int num, int pos, vector<vector<int>>& v)
{
	int& ret = v[num][pos];
	if(num == pos) return 1;
	if(ret != -1) return ret;
	ret = 0;
	for(int i=1;i<=num-pos;i++)
	{
		ret += ((pos+i-1) * top_down(num-pos, i, v)) % MOD;
		ret %= MOD;
	}
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
		cin>>n;
		vector<vector<int>> v(n+1, vector<int>(n+1, -1));

		int res = 0;
		for(int i=1;i<=n;i++)
		{
			res += top_down(n, i, v);
			res %= MOD;
		}
		cout<<res<<endl;
	}
	return 0;
}