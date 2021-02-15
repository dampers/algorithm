#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;
 
int ans;
void rec(int pos, lld a, lld b, set<pair<int, pair<int, int>>>& st)
{
	if(a == 0LL)
	{
		ans = min(pos, ans);
		return ;
	}
	else if(b > a)
	{
		ans = min(pos+1, ans);
		return;
	}
	else if(pos > 20) return;
	else if(b == 1)
	{
		rec(pos+1, a, b+1, st);
		return;
	}
	if(st.find({pos+1, {a/b, b}}) == st.end())
		rec(pos+1, a/b, b, st);
	if(st.find({pos+1, {a, b+1}}) == st.end())
		rec(pos+1, a, b+1, st);
}
 
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	//time_t start = clock();
	int tc;
	cin>>tc;
	while(tc--)
	{
		lld a, b;
		cin >> a >> b;
		if(a < b)
		{
			cout << 1 << endl;
			continue;
		}
		ans = INT_MAX;
		set<pair<int, pair<int, int>>> st;
		rec(0, a, b, st);
		cout << ans << endl;
	}
	//cout << (clock()-start)/1000.0;
 
	return 0;
}