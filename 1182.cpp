#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int ns[22], cnt, goal, n;

void dfs(int pos, int sum, int length)
{
	sum += ns[pos];
	if(pos>=n) return;
	if(sum==goal && length>=1) cnt++;
	dfs(pos+1, sum, length+1);
	dfs(pos+1, sum-ns[pos], length);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>goal;
	for(int i=0;i<n;i++)
		cin>>ns[i];
	dfs(0, 0, 1);
	cout<<cnt;
	return 0;
}