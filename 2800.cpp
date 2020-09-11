#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

bool check[11];
vector<pair<int, int>> pv;
vector<string> ans;
string s;

void f(int pos, int cnt)
{
	if(pos==pv.size())
	{
		if(cnt==0) return;
		string tmp = "";
		for(int i=0;i<s.length();i++)
		{
			if(s[i]==' ') continue;
			else tmp += s[i];
		}
		ans.push_back(tmp);
		return;
	}
	s[pv[pos].first] = ' ';
	s[pv[pos].second] = ' ';
	f(pos+1, cnt+1);
	s[pv[pos].first] = '(';
	s[pv[pos].second] = ')';
	f(pos+1, cnt);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	stack<int> st;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(') st.push(i);
		else if(s[i]==')')
		{
			pv.push_back({st.top(), i});
			st.pop();
		}
	}
	f(0, 0);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;
	return 0;
}