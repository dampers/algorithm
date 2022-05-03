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

	int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N, 0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> v[i][j];
        }
    }
    int asum = 0, bsum = 0;
    for(int i=0;i<N;i++)
    {
        int oa = 0, ob = 0, ea = 0, eb = 0;
        for(int j=0;j<N;j+=2)
        {
            ea += v[i][j];
            eb += v[j][i];
        }
        for(int j=1;j<N;j+=2)
        {
            oa += v[i][j];
            ob += v[j][i];
        }
        asum += max(ea, oa);
        bsum += max(eb, ob);
    }
    cout << max(asum, bsum);

	return 0;
}
