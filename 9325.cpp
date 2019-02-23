#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int s, n;
		cin>>s>>n;
		for(int j=0;j<n;j++)
		{
			int p, q;
			cin>>p>>q;
			s += p*q;
		}
		cout<<s<<endl;
	}	
	return 0;
}