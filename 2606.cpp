#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

vector<vector<int>> con[101];
bool visit[101][101];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int ind, tmp;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d", &ind, &tmp);
		con[ind].push_back(tmp);
	}
	return 0;
}