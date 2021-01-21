#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n, d, p;
		cin>>n>>d>>p;
		vector<vector<int>> v(n, vector<int>());
		vector<vector<double>> dp(d+1, vector<double>(n, 0.0));
		vector<bool> check(n, false);
		queue<int> q;
		dp[0][p] = 1.0;
		q.push(p);
		
		int tmp;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>tmp;
				if(tmp) v[i].push_back(j);
			}
		}

		for(int i=1;i<=d;i++)
		{
			fill(check.begin(), check.end(), false);
			size_t size = q.size();
			while(size--)
			{
				int pret = q.front();
				q.pop();
				for(size_t j=0;j<v[pret].size();j++)
				{
					int next = v[pret][j];
					dp[i][next] += dp[i-1][pret]/v[pret].size();
					if(!check[next])
					{
						check[next] = true;
						q.push(next);
					}
				}
			}
		}
		int check_num;
		cin>>check_num;

		cout<<fixed;
		cout.precision(12);
		for(int i=0;i<check_num;i++)
		{
			cin>>tmp;
			cout<<dp[d][tmp]<<" ";
		}
		cout<<endl;

	}
	return 0;
}