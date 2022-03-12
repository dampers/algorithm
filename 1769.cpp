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

	string s;
	cin >> s;
	bool flag = false;
	int cnt = 0;
	while(s.length() > 1)
	{
		cnt++;
		string tmp = s;
		int ntmp = 0;
		for(auto& K : tmp)
		{
			ntmp += K-'0';
		}
		s = "";
		if(ntmp % 3 == 0) flag = true;
		while(ntmp)
		{
			s.push_back((ntmp%10)+'0');
			ntmp /= 10;
		}
		reverse(s.begin(), s.end());
	}
	if(cnt == 0 && (s.back()-'0')%3 == 0) flag = true;
	cout << cnt << endl;
	if(flag) cout << "YES";
	else cout << "NO";

	return 0;
}
