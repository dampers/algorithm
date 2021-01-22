#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s;
		cin>>s;
		stack<char> st;
		bool flag = true;
		int ans = 0;
		for(size_t i=0;i<s.length();i++)
		{
			if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
			else if(st.empty()) flag = false;
			else if(st.top() == '(' && s[i] == ')') st.pop();
			else if(st.top() == '[' && s[i] == ']') st.pop();
			else if(st.top() == '{' && s[i] == '}') st.pop();
			else flag = false;
		}
		if(!st.empty()) flag = false;
		if(!flag) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}