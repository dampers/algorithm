#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int check(int size, int y, int x, vector<vector<int>>& paper)
{
	int color = paper[y][x];
	for(int i=y;i<y+size;i++)
		for(int j=x;j<x+size;j++)
			if(color != paper[i][j]) return -1;
	return color;

}


pair<int, int> pair_add(pair<int, int> a, pair<int, int> b)
{
	return make_pair(a.first+b.first, a.second+b.second);
}

pair<int, int> divide_conquer(int size, int y, int x, vector<vector<int>>& paper)
{
	int color = check(size, y, x, paper);
	pair<int, int> ret = {0, 0}; //white, blue
	
	// white
	if(color == 0) return make_pair(1, 0);
	// blue
	else if(color == 1) return make_pair(0, 1);
	// else
	ret = pair_add(ret, divide_conquer(size/2, y, x, paper));
	ret = pair_add(ret, divide_conquer(size/2, y, x+size/2, paper));
	ret = pair_add(ret, divide_conquer(size/2, y+size/2, x, paper));
	ret = pair_add(ret, divide_conquer(size/2, y+size/2, x+size/2, paper));

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> paper(n, vector<int>(n, 0));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> paper[i][j];

	pair<int, int> result = divide_conquer(n, 0, 0, paper);
	cout << result.first << '\n' << result.second;

	return 0;
}