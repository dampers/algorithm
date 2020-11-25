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
		int n, q;
		cin>>n>>q;
		string s;
		cin>>s;
		for(int iq=0;iq<q;iq++)
		{
			int l, r;
			cin>>l>>r;
			if(r-l+1==s.length())
			{
				cout<<"NO"<<endl;
				continue;
			}
			bool check = false;
			for(int i=r;i<s.length();i++)
			{
				if(s[r-1]==s[i])
				{
					check = true;
					break;
				}
			}
			for(int i=l-2;i>=0;i--)
			{
				if(s[l-1]==s[i])
				{
					check = true;
					break;
				}
			}
			if(check) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;

		}
	}
	return 0;
}