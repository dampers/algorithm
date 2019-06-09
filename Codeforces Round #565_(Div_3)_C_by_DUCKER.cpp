#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int cn[100];

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    map<int, int> mp = {{4, 0}, {8, 1}, {15, 2}, {16, 3}, {23, 4}, {42, 5}};

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x = mp[x];
        if(x == 0 || cn[x] < cn[x - 1])
            cn[x]++;
    }
    cout << n - 6*cn[5] << '\n';
    return 0;
}