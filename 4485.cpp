#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

class Compare
{
public:
	bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
	{return a.first > b.first;}
};

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc = 0;
	while(1)
	{
		tc++;
		int n;
		cin >> n;
		if(n == 0) return 0;
		vector<vector<int>> v(n, vector<int> (n, 0));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin >> v[i][j];
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> pq;
		vector<vector<bool>> check(n, vector<bool>(n, false));
		pq.push({v[0][0],{0, 0}});
		check[0][0] = false;
		while(!pq.empty())
		{
			int pres = pq.top().first;
			int y = pq.top().second.first, x = pq.top().second.second;
			pq.pop();
			if(y == n-1 && x == n-1)
			{
				cout << "Problem " << tc << ": " << pres << endl;
				break;
			}
			for(int i=0;i<4;i++)
			{
				int ny = y+dy[i], nx = x+dx[i];
				if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
				if(check[ny][nx]) continue;
				check[ny][nx] = true;
				pq.push({pres+v[ny][nx], {ny, nx}});
			}
		}

	}

	return 0;
}