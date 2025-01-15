#include <bits/stdc++.h>

using namespace std;

long long get_time(int level, vector<int>& diffs, vector<int>& times)
{
    long long time_prev = 0;
    long long ret = 0;
    for(size_t i=0;i<diffs.size();i++)
    {
        if(diffs[i] <= level)
        {
            ret += times[i];
            time_prev = times[i];
        }
        else
        {
            ret += (diffs[i] - level) * (time_prev + times[i]) + times[i];
            time_prev = times[i];
        }
    }
    return ret;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 1;
    
    int left = 1, right = 600000, mid = (right+left)/2;
    while(left < right)
    {
        mid = (right+left)/2;
        long long period = 0;
        period = get_time(mid, diffs, times);
        if(limit < period)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
        
    }
    answer = left;
    return answer;
}