#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int layer[200005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	vector<vector<int>> cont(n);
	vector<vetor<pair<int, int>> v(n);
	for(int i=0;i<n-1;i++)
	{
		int ua, va;
		cin>>ua>>va;
		v[ua].push_back(va);
		v[va].push_back(ua);
	}
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		
	}
	
	return 0;
}