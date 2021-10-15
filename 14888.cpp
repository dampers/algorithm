#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int mx = (int)(1e9)*-1;
int mn = 1e9;
int n;
void solve(int pos, int cal, vector<int>& oper, vector<int>& v)
{
	if(pos == n)
	{
		mx = max(cal, mx);
		mn = min(cal, mn);
		return;
	}
	for(int i=0;i<4;i++)
	{
		if(oper[i])
		{
			oper[i]--;
			if(i == 0) solve(pos+1, cal+v[pos], oper, v);
			if(i == 1) solve(pos+1, cal-v[pos], oper, v);
			if(i == 2) solve(pos+1, cal*v[pos], oper, v);
			if(i == 3) solve(pos+1, cal/v[pos], oper, v);
			oper[i]++;
		}
	}
}
 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	cin >> n;
	vector<int> v(n, 0), oper(4, 0);
	for(int i=0;i<n;i++)
		cin >> v[i];
	for(int i=0;i<4;i++)
		cin >> oper[i];
	solve(1, v[0], oper, v);
	cout << mx << endl << mn;
	return 0;
}