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

	string key, cipher;
	cin >> key >> cipher;
	vector<pair<char, int>> v(key.length());
	for(size_t i=0;i<key.length();i++)
	{
		v[i].first = key[i];
		v[i].second = i;
	}
	sort(v.begin(), v.end());

	int mxl = cipher.length()/key.length();
	vector<string> tmp(mxl, key), plain(mxl, key);
	int cipher_index = 0;
	for(size_t j=0;j<key.length();j++)
	{
		for(size_t i=0;i<mxl;i++)
		{
			tmp[i][j] = cipher[cipher_index++];
		}
	}

	for(int i=0;i<mxl;i++)
	{
		for(size_t j=0;j<key.length();j++)
		{
			plain[i][v[j].second] = tmp[i][j];
		}
	}
	for(auto &K : plain)
		cout << K;
	return 0;
}