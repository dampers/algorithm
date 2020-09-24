#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

bool check[10];
int n;
int cnt;

void f(int pos, vector<vector<int>>& v)
{
	if(pos==n)
	{
		cnt++;
		return;
	}
	else if(check[pos])
	{
		f(pos+1, v);
		return;
	}
	check[pos] = true;
	for(int i=0;i<v[pos].size();i++)
	{
		if(!check[v[pos][i]])
		{
			check[v[pos][i]] = true;
			f(pos+1, v);
			check[v[pos][i]] = false;
		}
	}
	check[pos] = false;
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
		int m;
		cin>>n>>m;
		memset(check, false, sizeof(check));
		vector<vector<int>> v(n);
		for(int i=0;i<m;i++)
		{
			int a, b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		cnt = 0;
		f(0, v);
		cout<<cnt<<endl;
	}
	return 0;
}