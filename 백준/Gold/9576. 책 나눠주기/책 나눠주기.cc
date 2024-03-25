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

int N, M;
int manOfBook[1001], bookOfMan[1001];
bool ch[1001];

bool dfs(int curr, vector<pii>& range)
{
    ch[curr] = true;
    int currBook = range[curr].first, right = range[curr].second;
    for(;currBook <= right; currBook++)
    {
        if(manOfBook[currBook] == 0 || (!ch[manOfBook[currBook]] && dfs(manOfBook[currBook], range)))
        {
            bookOfMan[curr] = currBook;
            manOfBook[currBook] = curr;
            return true;
        }
    }
    return false;
}

void solve()
{
    cin >> N >> M;
    
    memset(manOfBook, 0, sizeof(manOfBook));
    memset(bookOfMan, 0, sizeof(bookOfMan));

    vector<pii> range(M+3, {0, 0});

    for(int i=1;i<=M;i++)
    {
        cin >> range[i].first >> range[i].second;
    }

    int ans = 0;
    for(int i=1;i<=M;i++)
    {
        memset(ch, false, sizeof(ch));
        if(dfs(i, range)) ans++;
    }
    cout << ans << endl;

}



int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--)
    {
        solve();
    }
    

    return 0;
}