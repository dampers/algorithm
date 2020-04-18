#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    string king, sname, fname, mname;
    cin>>king;
    vector<vector<string>> v(155);
    map<string, pair<int, double>> person;
    person[king].first = 1;
    int pnum = 2;
    for(int i=0;i<n;i++)
    {
        cin>>sname>>fname>>mname;
        if(person[sname].first==0) person[sname].first = pnum++;
        if(person[fname].first==0) person[fname].first = pnum++;
        if(person[mname].first==0) person[mname].first = pnum++;
        v[person[fname].first].push_back(sname);
        v[person[mname].first].push_back(sname);
    }
    for(int i=0;i<m;i++)
    {
        cin>>sname;
        person[sname].second = 1.0;
    }
    queue<int> q;
    q.push(1);
    string name = "";
    double ks = 0.5;
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            int bfs = q.front();
            q.pop();
            int bfssize = v[bfs].size();
            for(int i=0;i<bfssize;i++)
            {
                name = v[bfs][i];
                int prenum = person[name].first;
                if(person[name].second>0.0)
                {
                    person[name].second += ks;
                }
                q.push(prenum);
            }
        }
        ks *= 0.5;
    }
    double mx = 0.0;
    for(auto it = person.begin();it!=person.end();it++)
    {
        if(mx<(*it).second.second)
        {
            mx = (*it).second.second;
            name = (*it).first;
        }
    }
    cout<<name;
    return 0;
}
