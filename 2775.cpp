#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
lld apt[15][15];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=1;i<15;i++) apt[0][i] = i;
	for(int i=1;i<15;i++)
		for(int j=1;j<15;j++)
			for(int k=1;k<=j;k++)
				apt[i][j] += apt[i-1][k];
	int tc;
	cin>>tc;
	while(tc--)
	{
		int a, b;
		cin>>a>>b;
		cout<<apt[a][b]<<endl;
	}
	return 0;
}