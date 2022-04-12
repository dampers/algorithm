#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void dfs(int k, int max, vector<int>& checks, set<int>& sleep)
{
    if(sleep.find(k) != sleep.end()) return;
    checks[k] = 1;
    for(int i=k+k;i<=max;i+=k)
    {
        dfs(i, max, checks, sleep);
    }
    
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k, q, m;
	cin >> n >> k >> q >> m;
	vector<int> checks(n+10, 0);
	set<int> sleep;
	vector<int> psum(n+10, 0);
	int tmp;
	for(int i=0;i<k;i++)
	{
	    cin >> tmp;
	    sleep.insert(tmp);
	}
	for(int i=0;i<q;i++)
	{
	    cin >> tmp;
	    dfs(tmp, n+2, checks, sleep);
	}
	for(int i=1;i<=n+2;i++)
	{
	    psum[i] = psum[i-1]+checks[i];
	}
	
	int a, b;
	for(int i=0;i<m;i++)
	{
	    cin >> a >> b;
	    cout << b-a+1-(psum[b]-psum[a-1]) << endl;
	}

	return 0;
}
