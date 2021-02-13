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
	time_t start = clock();
	
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		string name, kind;
		map<string, int> kind_idx;
		for(int i=0;i<n;i++)
		{
			cin >> name >> kind;
			kind_idx[kind]++;
		}
		lld ans = 1LL;
		for(auto k : kind_idx)
		{
			ans *= (k.second+1);
		}
		cout << ans-1 << endl;

	}
	return 0;
}