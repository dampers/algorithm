#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int block[505][505];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int tmp;
		cin>>tmp;
		for(int j=n-1;j>=n-tmp;j--)
		{
			block[j][i] = 1;
		}
	}
	int cnt = 0;
	for(int i=n-1;i>=0;i--)
	{
		int lindex = 0;
		bool flag = false;
		for(int j=0;j<m;j++)
		{
			if(block[i][j] && !flag)
			{
				lindex = j;
				flag = true;
			}
			else if(block[i][j] && flag)
			{
				cnt += j-lindex-1;
				lindex = j;
			}
		}
	}
	cout<<cnt;
	return 0;
}