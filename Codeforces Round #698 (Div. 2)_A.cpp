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
		int n;
		cin>>n;
		vector<int> v(n, 0);
		for(int i=0;i<n;i++)
			cin>>v[i];
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		int cnt = 1;
		int mx = 1;
		for(int i=1;i<n;i++)
		{
			if(v[i-1]==v[i]) cnt++;
			else
			{
				mx = max(cnt, mx);
				cnt = 1;
			}
		}
		mx = max(cnt, mx);
		cout<<mx<<endl;
	}

	return 0;
}