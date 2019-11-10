#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
 
int cell[12][12];
bool line[12][12];
int sum, mxpos, size, n, mnsum = 1800;
 
void dfs(vector<pair<int, int> > v, int pos, int k)
{
    if(mxpos<pos)
    {
        mxpos = pos;
        mnsum = sum;
        //cout<<"mxpos = "<<mxpos<<endl;
        //cout<<"mnsum = "<<mnsum<<endl;
    }
    else if(mxpos==pos)
    {
        mnsum = min(sum, mnsum);
        //cout<<"mxpos = "<<mxpos<<endl;
        //cout<<"mnsum = "<<mnsum<<endl;
    }
    //cout<<"pos = "<<pos<<endl;
    //cout<<"sum = "<<sum<<endl;
    for(int i=k+1;i<size;i++)
    {
        bool lflag = false;
        int y = v[i].first, x = v[i].second;
        //left
        for(int ii=0;ii<x;ii++)
        {
            if(line[y][ii]==true || cell[y][ii]==1)
            {
                lflag = true;
                break;
            }
        }
        if(lflag==false)
        {
            for(int ii=0;ii<=x;ii++)
                line[y][ii] = true;
            sum += x;
            dfs(v, pos+1, i);
            sum -= x;
            for(int ii=0;ii<=x;ii++)
                line[y][ii] = false;
        }
        lflag = false;
        //right
        for(int ii=x+1;ii<n;ii++)
        {
            if(line[y][ii]==true || cell[y][ii]==1)
            {
                lflag = true;
                break;
            }
        }
        if(lflag==false)
        {
            for(int ii=x;ii<n;ii++)
                line[y][ii] = true;
            sum += n-1-x;
            dfs(v, pos+1, i);
            sum -= n-1-x;
            for(int ii=x;ii<n;ii++)
                line[y][ii] = false;
        }
        lflag = false;
        //up
        for(int ii=0;ii<y;ii++)
        {
            if(line[ii][x]==true || cell[ii][x]==1)
            {
                lflag = true;
                break;
            }
        }
        if(lflag==false)
        {
            for(int ii=0;ii<=y;ii++)
                line[ii][x] = true;
            sum += y;
            dfs(v, pos+1, i);
            sum -= y;
            for(int ii=0;ii<=y;ii++)
                line[ii][x] = false;
        }
        lflag = false;
         
        //down
        for(int ii=y+1;ii<n;ii++)
        {
            if(line[ii][x]==true || cell[ii][x]==1)
            {
                lflag = true;
                break;
            }
        }
        if(lflag==false)
        {
            for(int ii=y;ii<n;ii++)
                line[ii][x] = true;
            sum += n-1-y;
            dfs(v, pos+1, i);
            sum -= n-1-y;
            for(int ii=y;ii<n;ii++)
                line[ii][x] = false;
        }
        lflag = false;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<int, int> > v;
    int testcase;
    cin>>testcase;
    for(int tc=1;tc<=testcase;tc++)
    {
        memset(line, false, sizeof(line));
        sum = 0;
        mxpos = 0;
        cout<<"#"<<tc<<' ';
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int ii=0;ii<n;ii++)
            {
                cin>>cell[i][ii];
                if((i==0 || ii==0 || i==n-1 || ii==n-1)&&cell[i][ii]==1) line[i][ii] = true;
                else if(cell[i][ii]==1) v.push_back({i, ii});
            }
        }
        size = v.size();
        dfs(v, 0, -1);
        cout<<mnsum<<endl;
        v.clear();
    }
    return 0;
}
