#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
bool check[100005];
vector<pair<int, lld> > v[100005];
int lnode;
lld mx = 0LL;

void dfs(int parent, lld value)
{
	int size = v[parent].size();
	cout<<"parent = "<<parent<<"\n";
	for(int i=0;i<size;i++)
	{
		int son = v[parent][i].first;
		if(check[son]) continue;
		cout<<son<<endl;
		value += v[parent][i].second;
		check[son] = true;
		if(mx<value)
		{
			mx = value;
			lnode = son;
		}
		dfs(son, value);
		check[son] = false;
		value -= v[parent][i].second;
	}
	cout<<"mx = "<<mx<<endl;
	cout<<"return"<<endl;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int parents;
		cin>>parents;
		int son;
		lld value;
		while(1)
		{
			cin>>son;
			if(son==-1) break;
			cin>>value;
			v[parents].push_back(make_pair(son, value));
		}
	}
	check[1] = true;
	dfs(1, 0LL);
	memset(check, false, sizeof(check));
	check[lnode] = true;
	mx = 0LL;
	//cout<<lnode<<endl;
	dfs(lnode, 0LL);
	cout<<mx;
	return 0;
}