#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

pii makeNext(int curr, int ud, int rcnt)
{
    string tmps = to_string(curr);
    for(int i=0;i<rcnt;i++)
    {
        int nr = tmps[i]-'0'-1;
        if(ud & (1<<nr)) ud &= ~(1<<nr);
        else ud |= (1<<nr);
    }
    reverse(tmps.begin(), tmps.begin()+rcnt);
    return make_pair(stoll(tmps), ud);
}

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    pii start = {0, 0};
    for(int i=0;i<n;i++)
    {
        getline(cin, s);
        start.first += s[0]-'0';
        start.first *= 10;
        if(s[2]=='+') start.second |= (1<<(s[0]-'0'-1));
    }
    start.first /= 10;

    pii goal = {1, (1<<n)-1};
    for(int i=2;i<=n;i++)
    {
        goal.first *= 10;
        goal.first += i;
    }
    
    queue<pii> q;
    q.push(start);

    if(start == goal)
    {
        printf("0");
        return 0;
    }
    int cnt = 0;
    set<pii> st;
    st.insert(start);


    while(!q.empty())
    {
        cnt++;
        //if(kcnt == 5) break;
        int size = q.size();
        while(size--)
        {
            int curr =  q.front().first;
            int cud = q.front().second;
            q.pop();
            pii next;
            for(int i=1;i<=n;i++)
            {
                next = makeNext(curr, cud, i);
                if(st.find(next) == st.end())
                {
                    st.insert(next);
                    q.push(next);
                }
                if(next == goal)
                {
                    cout << cnt;
                    return 0;
                }
            }
        }
    }
    
    return 0;
}
