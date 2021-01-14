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
		int n, d;
		cin>>n>>d;
		vector<int> v(n, 0);
		bool flag = true;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			if(v[i]>d) 	flag = false;
		}
		if(flag)
		{
			cout<<"YES"<<endl;
			continue;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(v[i]+v[j]<=d)
				{
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}