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
		int n;
		cin >> n;
		vector<string> v(n, "");
		for(int i=0;i<n;i++)
		{
			cin >> v[i];
		}
		vector<string> ansv;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i == j) continue;
				string tmp = v[i]+v[j];
				int lenf = tmp.length()/2;
				bool flag = true;
				for(int l=0;l<lenf;l++)
				{
					if(tmp[l] != tmp[tmp.length()-l-1])
					{
						flag = false;
						break;
					}
				}
				if(flag) ansv.push_back(tmp);
			}
		}
		if(ansv.size() == 0) cout << 0 << endl;
		else cout << ansv[0] << endl;
	}

	return 0;
}
