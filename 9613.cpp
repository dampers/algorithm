#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int num[101];
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
		lld sum = 0;
		for(int i=0;i<n;i++)
			cin>>num[i];
		sort(num, num+n);
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int tmpa = num[j], tmpb = num[i], ttmp;
				while(tmpb!=0)
				{
					ttmp = tmpa%tmpb;
					tmpa = tmpb;
					tmpb = ttmp;
				}
				sum += tmpa;
			}
		}
		cout<<sum<<endl;
		
	}
	return 0;
}