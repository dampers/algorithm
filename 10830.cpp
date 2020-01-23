#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

lld a[50][5][5], bb[5][5];


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<lld> v;
	int n;
	lld b;
	cin>>n>>b;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[1][i][j];
			a[1][i][j] %= 1000;
		}
	}
	v.push_back(b);
	while(b>1)
	{
		v.push_back(b/2);
		b /= 2;
	}
	int size = v.size();
	reverse(v.begin(), v.end());
	/*for(int i=0;i<size;i++)
		cout<<v[i]<<' ';
	cout<<endl;*/
	for(int i=2;i<size+1;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				for(int l=0;l<n;l++)
				{
					a[i][j][k] += (a[i-1][j][l]*a[i-1][l][k])%1000;
					a[i][j][k] %= 1000;
				}
			}
		}
		if(v[i-1]%2)
		{
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
					bb[j][k] = 0;
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					for(int l=0;l<n;l++)
					{
						bb[j][k] += (a[i][j][l]*a[1][l][k])%1000;
						bb[j][k] %= 1000;
					}
				}
			}
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
					a[i][j][k] = bb[j][k];
		}
		/*for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				cout<<a[i][j][k]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;*/
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[size][i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}