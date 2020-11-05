#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

bool check[101];
int p, s;

int back_track(int state, int pos, vector<vector<int>> v)
{
	check[state] = true;
	if(state==s) return 0;
	int ret = -1;
	for(int i=0;i<v[state].size();i++)
	{
		if(check[v[state][i]]) continue;
		ret = back_track(v[state][i], pos+1, v);
		if(ret>=0) break;
	}
	if(ret==-1) return -1;
	return ret+1;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	cin>>p>>s;
	vector<vector<int>> v(n+1);
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int a, b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cout<<back_track(p, 0, v);
	return 0;
}