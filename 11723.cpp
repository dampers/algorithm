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
	
	int m;
	cin>>m;
	int ss = 0, n;
	while(m--)
	{
		string s;
		cin>>s;
		if(s=="add")
		{
			cin>>n;
			ss |= (1<<n);
		}
		else if(s=="remove")
		{
			cin>>n;
			if(ss&(1<<n)) ss ^= (1<<n);
		}
		else if(s=="check")
		{
			cin>>n;
			if(ss&(1<<n)) cout<<1<<endl;
			else cout<<0<<endl;
		}
		else if(s=="toggle")
		{
			cin>>n;
			ss ^= (1<<n);
		}
		else if(s=="all")
		{
			for(int i=1;i<=20;i++)
				ss |= (1<<i);
		}
		else if(s=="empty") ss = 0;
	}
	return 0;
}