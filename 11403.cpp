#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int table[105][105];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>table[i][j];
	queue <int> q;
	for(int i=0;i<n;i++)
	{
		if(table[i][j]==1)
		{
			
		}
	}
	return 0;
}