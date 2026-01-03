#include <bits/stdc++.h>

using namespace std;

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const double EPS = 1e-9;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void solve()
{
    string s;
    cin >> s;
    stack<char> left, right;

    for(char c : s)
    {
        if(c == '<')
        {
            if(left.empty()) continue;
            char tmp = left.top();
            left.pop();
            right.push(tmp);
        }
        else if(c == '>')
        {
            if(right.empty()) continue;
            char tmp = right.top();
            right.pop();
            left.push(tmp);
        }
        else if(c == '-')
        {
            if(left.empty()) continue;
            left.pop();
        }
        else
        {
            left.push(c);
        }
    }
    vector<char> leftv;
    while(!left.empty())
    {
        leftv.push_back(left.top());
        left.pop();
    }
    reverse(leftv.begin(), leftv.end());
    for(char c : leftv) cout << c;
    while(!right.empty())
    {
        cout << right.top();
        right.pop();
    }
    cout << endl;
}

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    while(N-- > 0)
    {
        solve();
    }


    return 0;
}
