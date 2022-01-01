#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

const int MAX = 1000001;

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> fx(MAX, 1);
	for(int i=2;i<MAX;i++)
	{
		for(int j=i;j<MAX;j+=i)
			fx[j] += i;
	}
	vector<int> gx(MAX, 0);
	for(int i=1;i<MAX;i++)
		gx[i] = gx[i-1] + fx[i];

	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		cout << gx[n] << endl;
	}

	return 0;
}