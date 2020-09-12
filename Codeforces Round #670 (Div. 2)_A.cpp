#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int a[101], b[101];

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
		{
			cin>>v[i];
		}
		sort(v.begin(), v.end());
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for(int i=0;i<n;i++)
		{
			if(a[v[i]]==0) a[v[i]] = 1;
			else if(b[v[i]]==0) b[v[i]] = 1;
		}
		int ma = 0, mb = 0;
		for(int i=0;i<101;i++)
		{
			if(a[i]==0)
			{
				ma = i;
				break;
			}
		}
		for(int i=0;i<101;i++)
		{
			if(b[i]==0)
			{
				mb = i;
				break;
			}
		}
		cout<<ma+mb<<endl;


	}

	return 0;
}