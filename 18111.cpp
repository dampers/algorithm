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
	int n, m, b;
	cin>>n>>m>>b;
	vector<vector<int>> v(n, vector<int>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>v[i][j];

	int mncnt = (int)1e9;
	int flat = 0;
	for(int d=0;d<257;d++)
	{
		int tmpb = b;
		int cnt = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(v[i][j]>d)
				{
					tmpb += v[i][j]-d;
					cnt += (v[i][j]-d)*2;
				}
			}
		}
		bool flag = true;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(v[i][j]<d)
				{
					if(tmpb>=d-v[i][j])
					{
						tmpb -= d-v[i][j];
						cnt += d-v[i][j];
					}
					else
					{
						flag = false;
						break;
					}
				}
			}
		}
		if(flag)
		{
			if(mncnt>=cnt)
			{
				mncnt = cnt;
				flat = d;
			}
		}
	}
	cout<<mncnt<<' '<<flat<<endl;
	return 0;
}