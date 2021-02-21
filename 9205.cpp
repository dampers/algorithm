#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int get_dist(pair<int, int>& a, pair<int, int>& b)
{
	return abs(a.first-b.first)+abs(a.second-b.second);
}

void floyd(vector<pair<int, int>>& coord, vector<vector<bool>>& possible)
{
	for(size_t i=0;i<coord.size();i++)
	{
		for(size_t j=0;j<coord.size();j++)
		{
			for(size_t k=0;k<coord.size();k++)
			{
				if(possible[i][k] && possible[k][j] && !possible[i][j])
				{
					possible[i][j] = true;
					possible[j][i] = true;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		vector<pair<int, int>> coord(n+2);
		for(int i=0;i<n+2;i++)
			cin >> coord[i].second >> coord[i].first;
		vector<vector<bool>> possible(n+2, vector<bool>(n+2, false));
		for(size_t i=0;i<coord.size();i++)
		{
			for(size_t j=i+1;j<coord.size();j++)
			{
				if(get_dist(coord[i], coord[j]) <= 1000)
				{
					possible[i][j] = true;
					possible[j][i] = true;
				}
			}
		}
		floyd(coord, possible);
		cout << (possible[0][n+1]?"happy\n":"sad\n");
	}
	
	return 0;
}