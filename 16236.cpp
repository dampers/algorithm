#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int mp[22][22];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<pair<int, int>> v(7);

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, y, x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mp[i][j];
			if(mp[i][j]==9)
			{
				y = i;
				x = j;
			}
			else if(mp[i][j]>0)
			{
				v[mp[i][j]].push_back({i, j});
			}
		}
	}
	return 0;
}