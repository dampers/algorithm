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
	int tc;
	cin>>tc;
	while(tc--)
	{
		string t;
		cin>>t;
		if(t.length()==2)
		{
			cout<<t<<endl;
			continue;
		}
		int one = 0, zero = 0;
		for(int i=0;i<t.length();i++)
		{
			if(t[i]=='0') zero++;
			else one++;
		}
		if(one==0 || zero==0)
		{
			cout<<t<<endl;
			continue;
		}
		bool flag = false;
		string s = "";
		s += t[0];
		flag = t[0]=='0'?false:true;
		for(int i=1;i<t.length();i++)
		{
			if(flag)
			{
				if(t[i]=='1') s += "01";
				else s += t[i];
			}
			else
			{
				if(t[i]=='0') s += "10";
				else s += t[i];
			}
			flag = t[i]=='0'?false:true;
		}
		cout<<s<<endl;
	}
	
	return 0;
}