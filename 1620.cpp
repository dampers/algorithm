#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	map<string, int> dogam;
	vector<string> v(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		dogam[v[i]] = i;
	}
	while(m--)
	{
		string tmp;
		cin>>tmp;
		if(tmp[0]>='0' && tmp[0]<='9') cout<<v[stoi(tmp)]<<endl;
		else cout<<dogam[tmp]<<endl;
	}
	return 0;
}