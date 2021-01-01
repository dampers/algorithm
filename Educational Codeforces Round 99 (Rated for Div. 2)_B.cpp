#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

lld jump[5000005];
lld n;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	memset(jump, -1LL, sizeof(jump));
	queue<lld> q;
	q.push(0LL);
	int cnt = 1;
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			lld tmp = q.front();
			q.pop();
			if(jump[tmp]!=-1LL) continue;
			jump[tmp] = cnt-1;
			if(tmp+cnt<=5000000) q.push(tmp+cnt);
			if(tmp-1>=0) q.push(tmp-1);
		}
		cnt++;
	}
	while(tc--)
	{
		cin>>n;
		cout<<jump[n]<<endl;
	}
	cout<<jump[9]<<endl;
	return 0;
}