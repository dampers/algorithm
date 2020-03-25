#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

char star[3003][3003];

void f(int size, int y, int x)
{
	int check = 0;
	if(size == 3)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(++check==5) continue;
				star[i][j] = '*';
			}
		}
		return;
	}
	else if(size == 9)
	{
		for(int i=y-3;i<y+4;i+=3)
		{
			for(int j=x-3;j<x+4;j+=3)
			{
				if(++check == 5) continue;
				int center = 0;
				for(int ii=i;ii<i+3;ii++)
				{
					for(int jj=j;jj<j+3;jj++)
					{
						if(++center == 5) continue;
						star[ii][jj] = '*';
					}
				}
			}
		}
		return;
	}
	int sub = size/3, yy = y-((sub/3)*2), xx = x-((sub/3)*2);
	for(int i=yy;i<yy+3*sub;i+=sub)
	{
		for(int j=xx;j<xx+3*sub;j+=sub)
		{
			if(++check == 5) continue;
			f(size/3, i, j);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	f(n, n/3, n/3);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(star[i][j]!='*') cout<<' ';
			else cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}