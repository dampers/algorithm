#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

map<string, int> listen;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	string tmp;
	getline(cin, tmp);
	for(int i=0;i<n;i++)
	{
		getline(cin, tmp);
		listen[tmp] = 1;
	}
	vector<string> v;
	for(int i=0;i<m;i++)
	{
		getline(cin, tmp);
		if(listen[tmp]==1)
		{
			v.push_back(tmp);
		}
	}
	sort(v.begin(), v.end());
	int size = v.size();
	cout<<size<<'\n';
	for(int i=0;i<size;i++)
		cout<<v[i]<<'\n';
	return 0;
}