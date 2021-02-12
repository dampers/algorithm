#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

vector<int> dp[101][101];
bool check[101][101];

vector<int> add_v(vector<int> a, vector<int> b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	vector<int> ret(max(a.size(), b.size())+1);
	a.resize(ret.size(), 0);
	b.resize(ret.size(), 0);
	int carry = 0;
	for(size_t i=0;i<ret.size();i++)
	{
		ret[i] = (a[i]+b[i]+carry);
		carry = ret[i]/10;
		ret[i] %= 10;
	}
	if(ret.back() == 0) ret.pop_back();
	reverse(ret.begin(), ret.end());
	return ret;
}

vector<int> combination(int n, int r)
{
	if(check[n][r]) return dp[n][r];
	check[n][r] = true;
	if(r == 0 || n == r)
	{
		dp[n][r].push_back(1);
		return dp[n][r];
	}
	return dp[n][r] = add_v(combination(n-1, r), combination(n-1, r-1));
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	vector<int> ans = combination(n, m);
	for(size_t i=0;i<ans.size();i++)
		cout<<ans[i];
	return 0;
}