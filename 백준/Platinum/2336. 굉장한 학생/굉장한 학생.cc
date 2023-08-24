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

typedef struct{
    int x, y, z;
}grade;

bool compare(grade a, grade b)
{
    return a.x < b.x;
}

grade v[500005];
int tree[2002222];

int update(int node, int start, int end, int idx, int value)
{
    if(idx < start || end < idx) return tree[node];
    if(start == end) return tree[node] = value;
    int mid = (start + end) / 2;
    return tree[node] = min(update(node*2, start, mid, idx, value), update(node*2+1, mid+1, end, idx, value));
}

int get(int node, int start, int end, int left, int right)
{
    if(right < start || end < left) return INT_MAX;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return min(get(node*2, start, mid, left, right), get(node*2+1, mid+1, end, left, right));
}


int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> tmp;
        v[tmp].x = i;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> tmp;
        v[tmp].y = i;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> tmp;
        v[tmp].z = i;
    }

    sort(v+1, v+n+1, compare);
    for(int i=1;i<=n;i++)
        update(1, 1, n, i, INT_MAX);
    int ans = 0;

    for(int i=1;i<=n;i++)
    {
        if(get(1, 1, n, 1, v[i].y) > v[i].z) ans++;
        update(1, 1, n, v[i].y, v[i].z);
    }

    cout << ans;

    return 0;
}