#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int tiling[101];

int get_tiling(int pos)
{
	if(pos<=1) return 1;
	int& ret = tiling[pos];
	if(tiling[pos]!=0) return tiling[pos];
	return tiling[pos] = (get_tiling(pos-1)+get_tiling(pos-2))%1000000007;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		memset(tiling, 0, sizeof(tiling));
		cout<<get_tiling(n)<<endl;
	}

	return 0;
}