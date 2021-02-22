#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define FASTio ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
typedef long long lld;

int n, m;
int rec(int pos, vector<int>& v, vector<int>& check)
{
    if(pos == n)
    {
        bool flag = true;
        for(size_t i=0;i<v.size();i++)
            if(!check[v[i]]) return 0;
        return 1;
    }

    int ret = 0;
    for(int i=0;i<=9;i++)
    {
        check[i]++;
        ret += rec(pos+1, v, check);
        check[i]--;
    }
    return ret;
}

int main()
{
    FASTio;
    
    cin >> n >> m;
    vector<int> v(m, 0), check(10, 0);
    for(int i=0;i<m;i++)
        cin >> v[i];
    cout << rec(0, v, check);

    return 0;
}