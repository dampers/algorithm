#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n, tmp;
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> rightpq;
		priority_queue<int, vector<int>, less<int>> leftpq;
		cout << (n+1)/2 << endl;
		int cnt = 0;
		for(int i=1;i<=n;i++)
		{
			cin >> tmp;
			if(leftpq.empty() || (!rightpq.empty() && tmp <= rightpq.top())) leftpq.push(tmp);
			else rightpq.push(tmp);
			while(leftpq.size()+1 > rightpq.size())
			{
				rightpq.push(leftpq.top());
				leftpq.pop();
			}
			while(leftpq.size() < rightpq.size())
			{
				leftpq.push(rightpq.top());
				rightpq.pop();
			}
			if(i%2)
			{
				cout << leftpq.top() << ' ';
				cnt++;
				if(cnt == 10)
				{
					cnt = 0;
					cout << endl;
				}
			}
		}
		cout << endl;
	}
	return 0;
}
