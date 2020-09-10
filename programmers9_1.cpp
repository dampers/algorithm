#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int num[1002][1002];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> answer;
	int n;
	cin>>n;
    int sum = (n*(n+1))/2, state = 0;
    cout<<sum<<endl;
    for(int i=1;i<=n;i++)
        num[i][1] = i;
    for(int i=1;i<n;i++)
        num[n][i+1] = n+i;
    int cnt = n+n, y = n, x = n;
    while(cnt<=sum)
    {
        
        if(state==0)
        {
            while(y-1>0 && x-1>0 && y-1<=n && x-1<=n && num[y-1][x-1]==0 && cnt<=sum)
            {
                y--;
                x--;
                num[y][x] = cnt++;
            }
            state = 1;
        }
        if(state==1)
        {
            while(y+1>0 && y+1<=n && num[y+1][x]==0 && cnt<=sum)
            {
                y++;
                num[y][x] = cnt++;
            }
            state = 2;
        }
        if(state==2)
        {
            while(x+1>0 && x+1<=n && num[y][x+1]==0 && cnt<=sum)
            {
                x++;
                num[y][x] = cnt++;
            }
            state = 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(num[i][j]==0) continue;
            answer.push_back(num[i][j]);
        }
    }
    for(auto it=answer.begin();it!=answer.end();it++)
    	cout<<*it<<' ';
	return 0;
}