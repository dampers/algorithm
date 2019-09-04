#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int star[11][11][11];
int n;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				cin>>star[i][j][k];
	int mx = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int cnt = 0;
			for(int k=0;k<n;k++)
			{
				if(!star[k][i][j]) cnt++;
				else break;
			}
			mx = max(cnt, mx);
		}
	}
	for(int i=n-1;i>0;i--)
	{
		for(int j=n-1;j>0;j--)
		{
			int cnt = 0;
			for(int k=n-1;k>0;k--)
			{
				if(!star[i][k][j]) cnt++;
				else break;
			}
			mx = max(cnt, mx);
		}
	}
	for(int i=n-1;i>0;i--)
	{
		int cnt = 0;
		for(int j=n-1;j>0;j--)
		{
			int cnt = 0;
			for(int k=n-1;k>0;k--)
			{
				if(!star[i][j][k]) cnt++;
				else break;
			}
			mx = max(cnt, mx);
		}
	}


	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int cnt = 0;
			for(int k=0;k<n;k++)
			{
				if(!star[k][i][j]) cnt++;
				else break;
			}
			mx = max(cnt, mx);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int cnt = 0;
			for(int k=0;k<n;k++)
			{
				if(!star[i][k][j]) cnt++;
				else break;
			}
			mx = max(cnt, mx);
		}
	}
	for(int i=0;i<n;i++)
	{
		int cnt = 0;
		for(int j=0;j<n;j++)
		{
			int cnt = 0;
			for(int k=0;k<n;k++)
			{
				if(!star[i][j][k]) cnt++;
				else break;
			}
			mx = max(cnt, mx);
		}
	}
	cout<<mx;
	return 0;
}