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
		deque<int> dq;
		string orders;
		cin >> orders;
		int n;
		cin >> n;
		string sl;
		cin >> sl;
		int tmp = 0;
		if(n > 0)
		{
			for(size_t i=1;i<sl.size();i++)
			{
				if(sl[i] == ',' || sl[i] == ']')
				{
					dq.push_back(tmp);
					tmp = 0;
				}
				else
				{
					tmp *= 10;
					tmp += sl[i]-'0';
				}
			}
		}
		bool dir = false;
		bool error = false;
		for(char& order : orders)
		{
			if(order == 'R') dir = !dir;
			if(order == 'D')
			{
				if(dq.size() == 0)
				{
					error = true;
					break;
				}
				if(dir) dq.pop_back();
				else dq.pop_front();
			}
		}

		if(error) cout << "error\n";
		else
		{
			cout << "[";
			if(dir)
			{
				while(!dq.empty())
				{
					cout << dq.back();
					if(dq.size() > 1) cout << ',';
					dq.pop_back();
				}
			}
			else
			{
				while(!dq.empty())
				{
					cout << dq.front();
					if(dq.size() > 1) cout << ',';
					dq.pop_front();
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}