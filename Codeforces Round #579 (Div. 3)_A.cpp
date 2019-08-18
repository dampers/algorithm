#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int num[205];

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
		for(int i=0;i<n;i++)
			cin>>num[i];
		if(n==1)
		{
			cout<<"YES\n";
			continue;
		}
		else if(n==3)
		{
			if(num[0]==1 && num[1]==2 && num[2]==3) cout<<"YES\n";
			else if(num[0]==1 && num[1]==3 && num[2]==2) cout<<"YES\n";
			else if(num[0]==3 && num[1]==1 && num[2]==2) cout<<"YES\n";
			else if(num[0]==2 && num[1]==1 && num[2]==3) cout<<"YES\n";
			else if(num[0]==3 && num[1]==2 && num[2]==1) cout<<"YES\n";
			else if(num[0]==2 && num[1]==3 && num[2]==1) cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		int k = 500;
		int kind = 0;
		bool flag = false;
		for(int i=0;i<n;i++)
		{
			if(k>num[i])
			{
				k = num[i];
				kind = i;
			}
		}
		int qu = 0;
		if(kind==n-1)
		{
			if(num[0]==2) qu = 1;
			else if(num[n-2]==2) qu = 2;
			else qu = 100;
		}
		else if(kind==0)
		{
			if(num[1]==2) qu = 1;
			else if(num[n-1]==2) qu = 2;
			else qu = 100;
		}
		else
		{
			if(num[kind+1]==2) qu = 1;
			else if(num[kind-1]==2) qu = 2;
			else qu = 100;
		}
		if(qu==100)
		{
			cout<<"NO\n";
			continue;
		}
		int cnt = 2;
		if(qu==1)
		{
			qu = kind;
			for(int i=0;i<n-1;i++)
			{
				if(qu==n-1)
				{
					if(num[0]!=cnt)
					{
						flag = true;
						break;
					}
					qu = 0;
					cnt++;
				}
				else
				{
					if(num[qu+1]!=cnt)
					{
						flag = true;
						break;
					}
					qu++;
					cnt++;
				}
			}
		}
		else if(qu==2)
		{
			qu = kind;
			for(int i=0;i<n-1;i++)
			{
				if(qu==0)
				{
					if(num[n-1]!=cnt)
					{
						flag = true;
						break;
					}
					qu = n-1;
					cnt++;
				}
				else
				{
					if(num[qu-1]!=cnt)
					{
						flag = true;
						break;
					}
					qu--;
					cnt++;
				}
			}
		}
		if(flag) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}