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
		int n, m;
		cin>>n>>m;
		vector<int> crash(101, 0);
		for(int i=0;i<n;i++)
		{
			int tmp;
			cin>>tmp;
			crash[tmp]++;
		}
		for(int i=0;i<m;i++)
		{
			int tmp;
			cin>>tmp;
			crash[tmp]++;
		}
		int ans = 0;
		for(int i=1;i<=100;i++)
		{
			if(crash[i]==2)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}