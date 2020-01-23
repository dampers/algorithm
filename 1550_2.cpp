#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	getline(cin, s);
	lld k = 0LL;
	lld cnt = 1LL;
	for(int i=s.length()-1;i>=0;i--)
	{
		if(s[i]>='0' && s[i]<='9') k += cnt*(s[i]-'0');
		else if(s[i]>='A' && s[i]<='F') k += cnt*(s[i]-'A'+10);
		cnt *= 16;
	}
	cout<<k;
	return 0;
}