#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {0, 1, -1, 1, -1, 0};
const int dy[] = {-1, -1, 0, 0, 1, 1};

int get_prox(int ax, int ay, int bx, int by, int cx, int cy)
{
    return (cy-ay)*(bx-ax)-(by-ay)*(cx-ax);
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    cout.precision(1);
    cout << fixed;
    cout << abs(ax*(by-cy)+bx*(cy-ay)+cx*(ay-by)) / 2.0 << endl;

    int n;
    cin >> n;
    int x, y;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        int ab_ct = get_prox(ax, ay, bx, by, cx, cy) * get_prox(ax, ay, bx, by, x, y);
        int ac_bt = get_prox(ax, ay, cx, cy, bx, by) * get_prox(ax, ay, cx, cy, x, y);
        int bc_at = get_prox(bx, by, cx, cy, ax, ay) * get_prox(bx, by, cx, cy, x, y);
        if(ab_ct >= 0 && ac_bt >= 0 && bc_at >= 0) ans++;
    }
    cout << ans << endl;

	return 0;
}