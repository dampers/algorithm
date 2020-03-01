#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int n, cnt;
int check[16];

void backtrack(int pos)
{
	if(pos==n+1)
	{
		//for(int i=1;i<=n;i++) cout<<check[i]<<' ';
		//cout<<endl;
		cnt++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		bool flag = true;
		for(int j=1;j<pos;j++)
		{
			if(check[j]==i || abs(check[j]-i)==pos-j)
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			check[pos] = i;
			backtrack(pos+1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		check[1] = i;
		backtrack(2);
	}
	cout<<cnt;
	return 0;
}