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
	getline(cin, s);

	char aeiou[] = {'a', 'e', 'i', 'o', 'u', '\0'};
	for(size_t i=0;i<s.length();i++)
	{
		bool flag = false;
		for(int j=0;j<5;j++)
		{
			if(s[i] == aeiou[j]) flag = true;
		}
		cout << s[i];
		if(flag) i += 2;
	}

	return 0;
}
