#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int num[55];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=1;i<55;i++)
		num[i] = num[i-1]+i;
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		bool flag = false;
		for(int i=1;i<55;i++)
		{
			if(flag) break;
			for(int j=1;j<55;j++)
			{
				if(flag) break;
				for(int k=1;k<55;k++)
				{
					if(flag) break;
					if(num[i]+num[j]+num[k]==n)
					{
						cout<<1<<'\n';
						flag = true;
						break;
					}
					else if(num[i]+num[j]+num[k]>n) break;
				}
			}
		}
		if(!flag) cout<<0<<'\n';
	}
	return 0;
}