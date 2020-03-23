#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int paper[3003][3003], n;
int check[3];

void cut(int size, int y, int x)
{
	if(size==1)
	{
		check[1+paper[y][x]]++;
		return;
	}
	int flag = paper[y][x], subsize = size/3;
	bool cutflag = false;
	for(int i=y;i<y+size;i++)
	{
		for(int j=x;j<x+size;j++)
		{
			if(flag!=paper[i][j])
			{
				cutflag = true;
				break;
			}
		}
	}
	if(!cutflag) check[1+flag]++;
	else
	{
		for(int i=y;i<y+size;i+=subsize)
		{
			for(int j=x;j<x+size;j+=subsize)
			{
				cut(subsize, i, j);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>paper[i][j];
		}
	}
	cut(n, 0, 0);
	cout<<check[0]<<endl<<check[1]<<endl<<check[2];
	return 0;
}