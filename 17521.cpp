#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int a[16];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	lld n, m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	lld coin = 0;
	bool flag = false;
	for(int i=0;i<n;i++)
	{
		bool kflag = false;
		int mx = 0, mn = 500;
		if(!flag)
		{
			for(int j=i;j<n-1;j++)
			{
				if(a[j]<a[j+1])
				{
					i = j;
					mn = a[j];
					kflag = true;
					break;
				}
			}
			if(kflag)
			{
				coin += m/mn;
				m = m%mn;
			}
			flag = true;
		}
		else
		{
			for(int j=i;j<n-1;j++)
			{
				if(a[j]>a[j+1])
				{
					i = j;
					mx = a[j];
					break;
				}
			}
			if(mx==0)
			{
				mx = a[n-1];
				i = n-1;
			}
			m += coin*mx;
			coin = 0;
			flag = false;
		}
		//cout<<m<<' '<<coin<<endl;
	}
	cout<<m;
	return 0;
}