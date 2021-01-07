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
	string s, key;
	getline(cin, s);
	cin>>key;
	for(size_t i=0;i<s.length();i++)
	{
		if(s[i]==' ') continue;
		size_t key_idx = i%key.length();
		s[i] -= (key[key_idx]-'a'+1);
		if(s[i]<'a') s[i] += 26;
	}
	cout<<s<<endl;
	return 0;
}