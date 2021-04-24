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
	int tc;
	cin >> tc;
	while(tc--)
	{
		vector<bool> check(10000, false);
		int a, b;
		cin >> a >> b;
		check[a] = true;
		queue<pair<int, string>> q;
		q.push({a, ""});
		while(!q.empty())
		{
			int tmp = q.front().first;
			string ans = q.front().second;
			q.pop();
			if(tmp == b)
			{
				cout << ans << endl;
				break;
			}
			int d, s, l, r;
			d = tmp*2>9999?tmp*2-10000:tmp*2;
			s = tmp-1>=0?tmp-1:tmp-1+10000;
			l = ((tmp%1000)*10) + (tmp/1000);
			r = (tmp/10) + (tmp%10)*1000;
			if(!check[d])
			{
				q.push({d, ans+"D"});
				check[d] = true;
			}
			if(!check[s])
			{
				q.push({s, ans+"S"});
				check[s] = true;
			}
			if(!check[l])
			{
				q.push({l, ans+"L"});
				check[l] = true;
			}
			if(!check[r])
			{
				q.push({r, ans+"R"});
				check[r] = true;
			}
		}
	}
	return 0;
}