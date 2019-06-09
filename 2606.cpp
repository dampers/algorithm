#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

vector<vector<int>> v[101];

int main()
{
	int n, r;
	scanf("%d %d",&n, &r);
	for(int i=0;i<r;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	return 0;
}