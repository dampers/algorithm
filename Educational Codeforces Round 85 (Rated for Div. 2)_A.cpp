#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int pc[2][101];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>pc[0][i]>>pc[1][i];
		}
		bool flag = false;
		for(int i=1;i<n;i++)
		{
			if(pc[0][i]-pc[0][i-1]<pc[1][i]-pc[1][i-1])
			{
				flag = true;
				break;
			}
			if(pc[0][i]<pc[0][i-1])
			{
				flag = true;
				break;
			}
			if(pc[1][i]<pc[1][i-1])
			{
				flag = true;
				break;
			}
		}
		if(pc[0][0]<pc[1][0])
		{
			cout<<"NO"<<endl;
		}
		else if(flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}