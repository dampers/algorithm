#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

vector<vector<int>> matrix = {
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 0, 1, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 0, 1, 0, 1, 1, 0},
	{0, 0, 1, 1, 1, 0, 0, 1},
	{0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0, 1, 1, 0}
};


const int MOD = 1000000007;

vector<vector<int>> multipleMatrix(vector<vector<int>>& A, vector<vector<int>>& B)
{
	vector<vector<int>> ret(8, vector<int>(8, 0));

	for(size_t ai=0;ai<8;ai++)
	{
		for(size_t bj=0;bj<8;bj++)
		{
			int tmp = 0;
			for(size_t k=0;k<8;k++)
			{
				tmp += A[ai][k] * B[k][bj];
				tmp %= MOD;
			}
			ret[ai][bj] = tmp % MOD;
		}
	}
	return ret;
}

void expMatrix(vector<vector<int>>& ans, int n)
{
	while(n)
	{
		if(n&1)
		{
			ans = multipleMatrix(ans, matrix);
		}
		n >>= 1;
		matrix = multipleMatrix(matrix, matrix);
	}
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n;
	cin >> n;
	vector<vector<int>> ans(8, vector<int>(8, 0));
	for(int i=0;i<8;i++)
		ans[i][i] = 1;
	expMatrix(ans, n);
	cout << ans[0][0];

	return 0;
}