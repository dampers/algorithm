#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int num[1005][1005];

struct info
{
	int key;
	int cost;
	int clip;
};

void check(int qkey, int qcost)
{
	if(num[qkey][0]==-1) num[qkey][0] = qcost;
	else num[qkey][0] = min(num[qkey][0], qcost);
}


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	for(int i=0;i<1005;i++)
		for(int j=0;j<1005;j++)
			num[i][j] = -1;

	queue<info> q;
	q.push({1, 0, 0});
	num[1][0] = 0;
	while(!q.empty())
	{
		int qkey = q.front().key, qcost = q.front().cost, qclip = q.front().clip;
		q.pop();
		if(qkey-1>=0 && (num[qkey-1][qclip]==-1 || num[qkey-1][qclip]>qcost+1))
		{
			num[qkey-1][qclip] = qcost+1;
			check(qkey-1, qcost+1);
			q.push({qkey-1, qcost+1, qclip});
		}
		if(num[qkey][qkey]==-1 || num[qkey][qkey]>qcost+1)
		{
			num[qkey][qkey] = qcost+1;
			q.push({qkey, qcost+1, qkey});
		}
		if(qclip>0 && qkey+qclip<1005 && (num[qkey+qclip][qclip]==-1 || num[qkey+qclip][qclip]>qcost+1))
		{
			num[qkey+qclip][qclip] = qcost+1;
			check(qkey+qclip, qcost+1);
			q.push({qkey+qclip, qcost+1, qclip});
		}
		if(num[n][0]>=0)
		{
			cout<<num[n][0];
			return 0;
		}
	}
	cout<<num[n][0];
	return 0;
}