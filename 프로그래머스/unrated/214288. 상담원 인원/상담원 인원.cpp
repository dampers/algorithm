#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int numbers[8];
priority_queue<int, vector<int>, greater<int>> pq[8];

int cal(int k, vector<vector<int>>& reqs)
{
    for(int i=0;i<k;i++)
    {
        cout << numbers[i] << ' ';
    }
    cout << endl;
    int waiting = 0;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<numbers[i];j++)
            pq[i].push(0);           
    }
    
    for(auto K : reqs)
    {
        int rtime = K[0];
        int duration = K[1];
        int kind = K[2]-1;
        
        int last = pq[kind].top();
        pq[kind].pop();
        if(last <= rtime)
        {
            pq[kind].push(rtime + duration);
        }
        else// if(last > rtime)
        {
            waiting += last - rtime;
            pq[kind].push(last + duration);
        }
    }
    cout << waiting << endl;
    return waiting;
}

int dfs(int pos, int rest, int k, vector<vector<int>>& reqs)
{
    if(pos == k-1)
    {
        numbers[k-1] = rest + 1;
        return cal(k, reqs);
    }
    int ret = 1e9;
    for(int i=0;i<=rest;i++)
    {
        numbers[pos] = i+1;
        ret = min(ret, dfs(pos+1, rest-i, k, reqs));
    }
    return ret;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = dfs(0, n-k, k, reqs);
    
    return answer;
}