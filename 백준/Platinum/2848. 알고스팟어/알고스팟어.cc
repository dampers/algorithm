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

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<string> v(n, "");
    for(int i=0;i<n;i++)
        cin >> v[i];
    
    vector<bool> alphabet(26, false);
    int acnt = 0;
    for(auto &K : v)
    {
        for(char C : K)
        {
            alphabet[C-'a'] = true;
        }
    }
    for(int i=0;i<26;i++)
        acnt += alphabet[i];

    vector<vector<int>> adj(26, vector<int>(26, 0));
    vector<int> indegree(26, 0), outdegree(26, 0);
    int flag = 0;


    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int mnlen = min(v[i].length(), v[j].length());
            bool kflag = false;
            for(int k=0;k<mnlen;k++)
            {
                int a = v[i][k]-'a', b = v[j][k]-'a';
                if(v[i][k] == v[j][k]) continue;
                if(adj[a][b] == 1)
                {
                    kflag = true;
                    break;
                }
                adj[a][b] = 1;
                indegree[b]++;
                kflag = true;
                break;
            }
            if(!kflag && v[i].length() > v[j].length())
            {
                flag = 2;
            }
        }
    }

    if(flag == 2)
    {
        cout << "!";
        return 0;
    }
    queue<int> q;
    for(int i=0;i<26;i++)
    {
        if(alphabet[i] && indegree[i] == 0) q.push(i);
    }

    string ans = "";
    while(!q.empty())
    {
        if(q.size() > 1)
        {
            flag = 1;
            break;
        }
        int curr = q.front();
        q.pop();
        ans += 'a' + (char)curr;
        acnt--;
        for(int i=0;i<26;i++)
        {
            if(adj[curr][i])
            {
                int next = i;
                indegree[next]--;
                if(indegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }
    }

    if(flag == 1) cout << "?";
    else if(acnt > 0) cout << "!";
    else cout << ans;
    


    return 0;
}