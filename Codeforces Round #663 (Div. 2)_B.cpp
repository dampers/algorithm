
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
	string mp[101];
	while(tc--)
	{
		int n, m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>mp[i];
		}
		int cnt = 0;
		for(int i=0;i<n-1;i++)
		{
			if(mp[i][m-1]=='R') cnt++;
		}
		for(int i=0;i<m-1;i++)
		{
			if(mp[n-1][i]=='D') cnt++;
		}
		cout<<cnt<<endl;
	}
 
 
	return 0;
}