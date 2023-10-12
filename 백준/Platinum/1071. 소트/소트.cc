#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void push_number(int target, map<int, int>& mp, vector<int>& ob)
{
    int nk = mp[target];
    while(nk-- > 0)
        ob.push_back(target);
}

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

	vector<int> v;
	int n;
    cin >> n;
	int buf;
    for(int i=0;i<n;i++)
    {
		cin >> buf;
		v.push_back(buf);
	}
	sort(v.begin(), v.end());

	int cnt = 0;
    for(size_t i=0;i<v.size()-1;i++)
    {
		if(v[i+1] == v[i] + 1)
        {
			auto it = lower_bound(v.begin()+i, v.end(), v[i]+2);
			if(it != v.end()) swap(*it, v[i + 1]);
			else
            {
				auto ub = upper_bound(v.begin()+i+1, v.end(), v[i]);
				auto lb = lower_bound(v.begin()+i-cnt, v.end(), v[i]);
				while (ub != v.end())
                {
					swap(*lb, *ub);
					lb++; ub++;
				}
			}
			cnt = 0;
		}
		else if(v[i+1] == v[i]) cnt++;
	}
	for (auto K : v) cout << K << ' ';
}