#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int n;
int count_cache[101][101];
int cache[101][101];

int path(int y, int x)
{
	if(cache[y][x]!=0) return cache[y][x];
	if(y==n) 	
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
		cin>>n;
	}

	return 0;
}