#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    // time, (y, x)
    map<pair<int, pair<int, int>>, int> mp;
    
    for(size_t i=0;i<routes.size();i++)
    {
        int t = 1;
        int source = routes[i][0] - 1;
        int sy = points[source][0];
        int sx = points[source][1];
        if(mp.find({0, {sy, sx}}) == mp.end()) mp[{0, {sy, sx}}] = 1;
        else mp[{0, {sy, sx}}] += 1;
        
        for(size_t j=1;j<routes[i].size();j++)
        {
            int dest = routes[i][j] - 1;
            while(sy != points[dest][0])
            {
                if(sy > points[dest][0]) sy--;
                else sy++;
                if(mp.find({t, {sy, sx}}) == mp.end()) mp[{t, {sy, sx}}] = 1;
                else mp[{t, {sy, sx}}] += 1;
                t++;
            }
            while(sx != points[dest][1])
            {
                if(sx > points[dest][1]) sx--;
                else sx++;
                if(mp.find({t, {sy, sx}}) == mp.end()) mp[{t, {sy, sx}}] = 1;
                else mp[{t, {sy, sx}}] += 1;
                t++;
            }
        }
    }
    
    for(auto K : mp)
    {
        if(K.second > 1) answer++;
    }
    
    
    return answer;
}