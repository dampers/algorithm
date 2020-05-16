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
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		sort(v.begin(), v.end());
		int sum = 0, kcnt = 0, mx = v[0], cnt = 0;
		for(int i=0;i<n;i++)
		{
			if(mx>=v[i])
			{
				cnt++;
				if(cnt==mx)
				{
					sum++;
					cnt = 0;
				}
			}
			else
			{
				mx = v[i];
				cnt++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}