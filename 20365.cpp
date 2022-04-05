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
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    int red = 0, blue = 0;
    for(size_t i=0;i<s.length();i++)
    {
        if(i > 0 && s[i] == 'R' && s[i-1] != 'R') red++;
        else if(i > 0 && s[i] == 'B' && s[i-1] != 'B') blue++;
        else if(i == 0)
        {
            if(s[i] == 'R') red++;
            else blue++;
        }
    }
    if(red > blue) cout << blue+1 << endl;
    else cout << red+1 << endl;

	return 0;
}