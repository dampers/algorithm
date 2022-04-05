#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

unsigned long long add(int ts, int n)
{
    return stoull(to_string(ts)+to_string(n));
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<bool> check(k+1, false);
    
    unsigned long long ts = n;
    int cnt = 1;
    while(1)
    {
        unsigned long long tmp = ts % k;
        if(tmp == 0)
        {
            cout << cnt << endl;
            return 0;
        }
        else if(check[tmp])
        {
            cout << -1;
            return 0;
        }
        check[tmp] = true;
        cnt++;
        ts = add(tmp, n);
    }

	return 0;
}