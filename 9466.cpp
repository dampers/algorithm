#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int target;
bool flag;

int dfs(int pos, int gn, vector<int>& select, vector<int>& visit)
{
	visit[pos] = gn;
	if(pos == select[pos]) return 1;
	if(visit[select[pos]] == gn)
	{
		target = select[pos];
		flag = true;
		return 1;
	}
	else if(visit[select[pos]] > 0) return 0;
	int ret = dfs(select[pos], gn, select, visit);	
	if(flag) ret++;
	if(target == pos) flag = false;
	return ret;
}

int main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		vector<int> visit(n+1, 0), select(n+1, 0);
		for(int i=1;i<=n;i++)
			cin >> select[i];
		int gn = 1, ans = 0;
		for(int i=1;i<=n;i++)
		{
			if(visit[i]) continue;
			else if(select[i] == i)
			{
				ans++;
				visit[i] = gn++;
				continue;
			}
			ans += dfs(i, gn++, select, visit);
			flag = false;
		}
		cout << n-ans << endl;
	}
	return 0;
}