#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

struct wall
{
	int y;
	int x;
	int r;

	wall()
	{
		y = 0;
		x = 0;
		r = 0;		
	}
	wall(int y, int x, int r)
	{
		this->y = y;
		this->x = x;
		this->r = r;
	}
};

bool compare(wall &A, wall &B)
{
	return A.r > B.r;
}

double get_sqdist(wall &a, wall &b)
{
	return (a.y-b.y)*(a.y-b.y)+(a.x-b.x)*(a.x-b.x);
}

void init(int node, int pos, vector<wall>& wallv, vector<vector<int>>& tree,
			vector<bool>& check
			)
{
	bool flag = false;
	check[node] = true;
	for(size_t i=0;i<tree[node].size();i++)
	{
		int tmp = tree[node][i];
		if(check[tmp]) continue;
		int mxr = max(wallv[tmp].r, wallv[pos].r);
		if(get_sqdist(wallv[tmp], wallv[pos]) < mxr*mxr)
		{
			flag = true;
			init(tmp, pos, wallv, tree, check);
			break;
		}
	}
	if(!flag)
	{
		tree[node].push_back(pos);
		tree[pos].push_back(node);
	}
}

int depth, fnode;

void dfs(int pos, int node, vector<vector<int>>& tree, vector<bool>& check)
{
	check[node] = true;
	if(pos > depth)
	{
		depth = pos;
		fnode = node;
	}
	for(size_t i=0;i<tree[node].size();i++)
	{
		int tmp = tree[node][i];
		if(check[tmp]) continue;
		dfs(pos+1, tmp, tree, check);
	}
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
		vector<wall> wallv(n, wall());
		int tmpy, tmpx, tmpr;
		for(int i=0;i<n;i++)
		{
			cin>>tmpx>>tmpy>>tmpr;
			wallv[i] = wall(tmpy, tmpx, tmpr);
		}
		sort(wallv.begin(), wallv.end(), compare);
		vector<vector<int>> tree(n, vector<int>());
		vector<bool> check(n, false);
		
		for(int i=1;i<n;i++)
		{
			fill(check.begin(), check.end(), false);
			init(0, i, wallv, tree, check);
		}

		depth = 0;
		fnode = 0;
		fill(check.begin(), check.end(), false);
		dfs(0, 0, tree, check);
		fill(check.begin(), check.end(), false);
		dfs(0, fnode, tree, check);
		cout<<depth<<endl;
	}
	return 0;
}