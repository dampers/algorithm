#include <bits/stdc++.h>
#include <string>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

string updown(int& pos, string& s)
{
	char head = s[pos++];
	if(head!='x') return string(1, head);
	string tmp[4];
	for(int i=0;i<4;i++)
		tmp[i] = updown(pos, s);
	return string("x") + tmp[2]+tmp[3]+tmp[0]+tmp[1];
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
		cout<<updown(pos, s)<<endl;
	}
	return 0;
}