#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int n, m;

double top_down(vector<vector<double>>& dp, int day, int length)
{
	if(day==m) return length >= n? 1:0;
	double& ret = dp[day][length];
	if(ret!=-1.0) return ret;
	return ret = 0.25*top_down(dp, day+1, length+1)+0.75*top_down(dp, day+1, length+2);
}

int main()
{
	
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d %d", &n, &m);
		vector<vector<double>> dp(m+1, vector<double> (2*n+1, -1.0));
		printf("%.8f\n", top_down(dp, 0, 0));

	}
	return 0;
}