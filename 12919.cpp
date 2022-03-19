#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool removes(string& s, string goal)
{
	if(s.length() == goal.length())
	{
		if(s == goal) return true;
		else return false;
	}
	bool ret = false;
	if(goal[0] == 'A' && goal.back() == 'B') return false;
	if(goal.back() == 'A') ret |= removes(s, goal.substr(0, goal.length()-1));
	if(goal[0] == 'B') ret |= removes(s, string(goal.rbegin(), goal.rend()).substr(0, goal.length()-1));
	return ret;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, goal;
	cin >> s >> goal;
	cout << removes(s, goal);

	return 0;
}
