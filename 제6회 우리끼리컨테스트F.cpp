#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int num[100005];
int dpmx[100005];
int dpmn[100005];
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int mx, mn, n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>num[i];
    dpmx[0] = num[0];
    dpmn[0] = num[0];
    for(int i=1;i<n;i++)
    {
        dpmx[i] = max(dpmx[i-1]+num[i], num[i]);
        dpmn[i] = min(dpmn[i-1]+num[i], num[i]);
    }
    mx = dpmx[0];
    mn = dpmn[0];
    for(int i=0;i<n;i++)
    {
        mx = max(mx, dpmx[i]);
        mn = min(mn, dpmn[i]);
    }
    cout<<mx<<' '<<mn;
    return 0;
}