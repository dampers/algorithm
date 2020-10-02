#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

void divs(string& s, stack<string>& st, int& pos)
{
	string ptmp = "";
	if(s[pos]!='x')
	{
		st.push(ptmp+s[pos++]);
		return;
	}
	pos++;
	ptmp += 'x';
	int cnt = 0;
	while(cnt<4 && pos<s.length())
	{
		divs(s, st, pos);
		cnt++;
	}
	string tmp[4];
	while(cnt>0)
	{
		tmp[--cnt] = st.top();
		st.pop();
	}
	st.push(ptmp+tmp[2]+tmp[3]+tmp[0]+tmp[1]);
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
		string s;
		cin>>s;
		int pos = 0;
		stack<string> st;
		divs(s, st, pos);
		cout<<st.top()<<endl;
	}
	return 0;
}