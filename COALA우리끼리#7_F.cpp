#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int table[1005][1005];
int ms[1005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, e;
	cin>>n>>e;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			table[i][j] = 2100000000;
	int x, y, c;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y>>c;
		table[x][y] = min(c, table[x][y]);
	}
    /*for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    		if(table[i][j]!=2100000000)cout<<table[i][j]<<' ';
    		else cout<<"INF"<<' ';
    	cout<<endl;
    }*/
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
		cin>>ms[i];
	lld sum = 0;
	for(int i=1;i<m;i++)
	{
		if(table[ms[i-1]][ms[i]]>=2100000000)
		{
			cout<<-1;
			return 0;
		}
		//cout<<ms[i-1]<<" to "<<ms[i]<<endl;
		//cout<<table[ms[i-1]][ms[i]]<<endl;;
		sum += table[ms[i-1]][ms[i]];
	}
	cout<<sum;
	return 0;
}