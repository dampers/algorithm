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
	int n, m;
	cin>>n>>m;
	vector<vector<int>> grp(m);
	for(int i=0, k;i<m;i++)
	{
		cin>>k;
		grp[i].resize(k);
		for(int j=0;j<k;j++)
			cin>>grp[i][j];
	}
	vector<int> vir(n), v(n), org(n);
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		cin>>vir[i];
		org[i] = vir[i];
		if(vir[i]==1) cnt++;
	}
	for(int i=m-1;i>=0;i--)
	{
		bool flag = false;
		for(int j=0;j<grp[i].size();j++)
		{
			if(!vir[grp[i][j]-1])
			{
				flag = true;
				break;
			}
		}
		if(flag)
		{
			for(int j=0;j<grp[i].size();j++)
			{
				if(vir[grp[i][j]-1]) cnt--;
				vir[grp[i][j]-1] = 0;
			}
		}
	}
	for(int i=0;i<n;i++) v[i] = vir[i];
	for(int i=0;i<m;i++)
	{
		bool kflag = false;
		for(int j=0;j<grp[i].size();j++)
		{
			if(v[grp[i][j]-1])
			{
				kflag = true;
				break;
			}
		}
		if(kflag)
			for(int j=0;j<grp[i].size();j++)
				v[grp[i][j]-1] = 1;
	}
	bool ans = true;
	for(int i=0;i<n;i++)
	{
		if(v[i]!=org[i])
		{
			ans = false;
			break;
		}
	}
	if(ans)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
			cout<<vir[i]<<' ';
	}
	else cout<<"NO";
	return 0;
}