#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int n, k;
int	dp[105][100005];

int top_down(int pos, int weight, int value, vector<pair<int, int>>& v)
{
	if(pos == n) return 0;
	if(dp[pos][weight]!= -1) return dp[pos][weight];
	if(weight+v[pos].first > k) return dp[pos][weight] = top_down(pos+1, weight, value, v);
	return dp[pos][weight] = max(top_down(pos+1, weight, value, v), top_down(pos+1, weight+v[pos].first, value+v[pos].second, v)+v[pos].second);
}

int main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	vector<pair<int, int>> v(n);
	memset(dp, -1, sizeof(dp));
	for(int i=0;i<n;i++)
		cin >> v[i].first >> v[i].second;
	cout << top_down(0, 0, 0, v);


	return 0;
}