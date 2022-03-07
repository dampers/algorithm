#include<bits/stdc++.h>

using namespace std;

#define endl '\n';

int main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for(int t=1;t<=tc;t++)
	{
		int n, k;
		cin >> n >> k;
		vector<int> v(1, 0);
		int tmp;
		for(int i=0;i<n;i++)
		{
			cin >> tmp;
			if(v.back() < tmp) v.push_back(tmp);
			else *lower_bound(v.begin(), v.end(), tmp) = tmp;
		}
		cout << "Case #" << t << endl;
		if(v.size()-1 >= k)
		{
			cout << 1 << endl;
		}
		else cout << 0 << endl;
	}
	
	
	return 0;
}
