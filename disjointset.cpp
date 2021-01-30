#include <bits/stdc++.h>

using namespace std;

int a[200001];
bool check[200001];

class DisjointSet
{
public:
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 1)
    {
        for(int i=0;i<n;i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if(u==parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if(u==v) return;
        if(rank[u]>rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u]==rank[v]) rank[u]++;
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    DisjointSet ds(n+2);
    for(int i=0;i<n;i++)
    {
        int tmp;
        scanf(" %d", &tmp);
        if(ds.find(tmp)==tmp)
        {
            check[tmp] = true;
            ds.merge(tmp, tmp+1);
        }
        else
        {
            int tt = ds.find(tmp+1);
            if(tt!=n+1)
            {
                check[tt] = true;
                ds.merge(tt, tt+1);
            }
        }
    }
    long long sum = 0;
    for(int i=1;i<=n;i++)
        if(check[i]) sum += i;
    printf("%lld", sum);

    return 0;
}