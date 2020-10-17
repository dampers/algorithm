#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int n;
// O(n^2) LIS
int LIS(int k, vector<int>& v, vector<int>& dp)
{
	int& ret = dp[k];
	if(ret!=-1) return ret;
	ret = 1;
	for(int i=k+1;i<=n;i++)
		if(v[k]<v[i]) ret = max(ret, LIS(i, v, dp)+1);
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
		vector<int> v(n+1), dp(n+1, -1);
		for(int i=1;i<=n;i++)
			cin>>v[i];
		v[0] = INT_MIN;
		cout<<LIS(0, v, dp)-1<<endl;
	}
	return 0;
}
