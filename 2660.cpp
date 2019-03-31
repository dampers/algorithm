#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
vector<vector<int>> head[51];
int 
int main()
{
	int n;
	scanf(" %d", &n);
	int tmp1, tmp2;
	while(1)
	{
		scanf(" %d %d", &tmp1, &tmp2);
		if(tmp1==-1)
			break;
		head[tmp1].push_back(tmp2);
		head[tmp2].push_back(tmp1);
	}
	int mn = 55;
	for(int i=1;i<=n;i++)
	{
		if(mn>head[i].size())
			mn = head[i].size();
	}
	printf("%")
	return 0;
}