#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

string dfs(int edge, vector<set<int>>& top, vector<bool>& check)
{
	check[edge] = true;
	string ret = "";
	for(auto& next : top[edge])
		if(!check[next]) ret += dfs(next, top, check);
	ret += (char)('a'+edge);
	return ret;
}

bool make_graph(vector<string>& v, vector<set<int>>& top)
{
	bool ret = false;
	string tmp = v[0];
	for(size_t i=1;i<v.size();i++)
	{
		size_t mn_len = min(tmp.length(), v[i].length());
		for(size_t j=0;j<mn_len;j++)
		{
			if(tmp[j] != v[i][j])
			{
				if(top[v[i][j]-'a'].find(tmp[j]-'a') == top[v[i][j]-'a'].end())
					top[tmp[j]-'a'].insert(v[i][j]-'a');
				else ret = true;
				break;
			}
		}
		tmp = v[i];
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
		int n;
		cin>>n;
		vector<string> v(n);
		for(int i=0;i<n;i++)
			cin >> v[i];
		reverse(v.begin(), v.end());
		vector<bool> check(26, false);
		vector<set<int>> top(26, set<int>());

		if(make_graph(v, top))
		{
			cout << "INVALID HYPOTHESIS" << endl;
			continue;
		}
		string ans = "";
		for(int i=0;i<26;i++)
			if(!check[i]) ans += dfs(i, top, check);
		cout << ans << endl;
	}
	return 0;
}