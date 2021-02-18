#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;


int n;

int rec(int pos, int num, vector<vector<int>>& ability, vector<bool>& team)
{
    if(pos == n/2)
    {
        int teamA = 0, teamB = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(team[i] && team[j]) teamA += (ability[i][j]+ability[j][i]);
                else if(!team[i] && !team[j]) teamB += (ability[i][j]+ability[j][i]);
            }
        }
        return abs(teamA-teamB);
    }
    int ret = INT_MAX;
    for(int i=num;i<n;i++)
    {
        if(!team[i])
        {
            team[i] = true;
            ret = min(rec(pos+1, i+1, ability, team), ret);
            team[i] = false;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    vector<vector<int>> ability(n, vector<int>(n, 0));
    vector<bool> team(n, false);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> ability[i][j];
    cout << rec(0, 0, ability, team);


    return 0;
}