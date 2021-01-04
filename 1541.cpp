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
	
	string s;
	cin>>s;
	
	vector<int> v;
	queue<char> op;
	v.push_back(0);
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='-' || s[i]=='+')
		{
			op.push(s[i]);
			v.push_back(0);
		}
		else if(s[i]>='0' && s[i]<='9')
		{
			*(v.end()-1) *= 10;
			*(v.end()-1) += s[i]-'0';
		}
	}


	lld ans = (lld)v[0], sub = 0;
	for(int i=1;i<v.size();i++)
	{
		if(op.front()=='-')
		{
			ans -= sub;
			sub = 0;
			sub += v[i];
		}
		if(op.front()=='+')
		{
			if(sub) sub += v[i];
			else ans += v[i];
		}
		op.pop();
	}
	if(sub) ans -= sub;
	cout<<ans;


	return 0;
}