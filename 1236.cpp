#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<string> v(n, "");
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	vector<int> row(n, 0), col(m, 0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(v[i][j] == 'X')
			{
				col[j] = 1;
				row[i] = 1;
			}
		}
	}
	int rcnt = 0, ccnt = 0;
	for(int i=0;i<n;i++)
		if(row[i] == 0) rcnt++;
	for(int i=0;i<m;i++)
		if(col[i] == 0) ccnt++;
	cout << max(rcnt, ccnt);

	return 0;
}
