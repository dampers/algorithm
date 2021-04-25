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
	cin >> n >> m;
	vector<int> port(101, 0);
	vector<bool> check(101, false);
	n += m;
	for(int i=0;i<n;i++)
	{
		int x, y;
		cin >> x >> y;
		port[x] = y;
	}
	queue<int> q;
	q.push(1);
	check[1] = true;
	int cnt = 0;
	bool flag = false;
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int pos = q.front();
			q.pop();
			if(pos == 100)
			{
				cout << cnt;
				return 0;
			}
			for(int i=1;i<7;i++)
			{
				int tmp = pos+i;
				if(check[tmp] || tmp>100) continue;
				if(port[tmp])  	q.push(port[tmp]);
				else q.push(tmp);
				check[tmp] = check[port[tmp]] = true;
			}
		}
		cnt++;
	}

	return 0;
}