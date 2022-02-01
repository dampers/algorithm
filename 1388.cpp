#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.sync_with_stdio(NULL);
	cout.tie(NULL);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<string> v(n, "");
	vector<vector<bool>> check(n, vector<bool>(m, false));
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(check[i][j]) continue;
			check[i][j] =true;
			if(v[i][j] == '-')
			{
				int curr = j+1;
				while(curr < m && !check[i][curr] && v[i][j] == v[i][curr])
				{
					check[i][curr] = true;
					curr++;
				}
			}
			else if(v[i][j] == '|')
			{
				int curr = i+1;
				while(curr < n && !check[curr][j] && v[i][j] == v[curr][j])
				{
					check[curr][j] = true;
					curr++;
				}
			}
			ans++;
		}
	}
	cout << ans;
	return 0;
}
