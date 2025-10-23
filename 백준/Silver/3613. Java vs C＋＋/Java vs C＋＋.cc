#include <bits/stdc++.h>

using namespace std;

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

string convert_to_cpp(string& s)
{
    string ans = "";
    for(size_t i=0;i<s.length();i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            ans += '_';
            ans += (s[i]-'A')+'a';
        }
        else ans += s[i];
    }
    return ans;
}

string convert_to_java(string& s)
{
    string ans = "";
    for(size_t i=0;i<s.length();i++)
    {
        if(s[i] == '_')
        {
            ans += (s[i+1]-'a')+'A';
            i++;
        }
        else ans += s[i];
    }
    return ans;
}

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    int java = 0, cpp = 0;

    if((s[0] >= 'A' && s[0] <= 'Z') || s[0] == '_' || s.back() == '_')
    {
        cout << "Error!" << endl;
        return 0;
    }

    for(size_t i=1;i<s.length();i++)
    {
        if(i+1 < s.length() && s[i] == '_') cpp = 1;
        if(s[i] >= 'A' && s[i] <= 'Z') java = 1;
        if(i+1 < s.length() && s[i] == '_' && s[i+1]=='_')
        {
            java = 1;
            cpp = 1;
            break;
        }
    }
    if(java == 1 && cpp == 1) cout << "Error!" << endl;
    else if(java == cpp) cout << s << endl;
    else if(java) cout << convert_to_cpp(s) << endl;
    else cout << convert_to_java(s) << endl;

    return 0;
}