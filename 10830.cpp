#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void matrix_multiple(vector<vector<int>>& u, vector<vector<int>>& v)
{
	vector<vector<int>> ret(u.size(), vector<int>(u.size(), 0));
	for(size_t i=0;i<u.size();i++)
	{
		for(size_t j=0;j<u[i].size();j++)
		{
			for(size_t k=0;k<u[i].size();k++)
			{
				ret[i][j] = (ret[i][j] + u[i][k] * v[k][j]) % 1000;
			}
		}
	}
	for(size_t i=0;i<u.size();i++)
	{
		for(size_t j=0;j<u.size();j++)
		{
			v[i][j] = ret[i][j];
		}
	}
}

void binary_exp(lld b, vector<vector<int>>& a, vector<vector<int>>& ans)
{
	vector<vector<int>> tmp(a.size(), vector<int>(a.size(), 0));
	for(int i=0;i<a.size();i++)
		for(int j=0;j<a.size();j++)
			tmp[i][j] = a[i][j];

	while(b)
	{
		if(b & 1LL)
		{
			matrix_multiple(tmp, ans);
		}
		matrix_multiple(tmp, tmp);
		b >>= 1;
	}
}

int main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	lld b;
	cin >> n >> b;
	vector<vector<int>> a(n, vector<int>(n, 0)), ans(n, vector<int>(n, 0));
	for(int i=0;i<n;i++)
		ans[i][i] = 1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> a[i][j];
		}
	}

	binary_exp(b, a, ans);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << ans[i][j] << ' ';
		cout << endl;
	}	

	return 0;
}