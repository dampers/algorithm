#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

queue<int> q[2001];
bool flag = false;
void f(int pos, int k)
{
	printf("pos = %d\n", pos);
	if(pos==4)
	{
		flag = true;
		return;
	}
	if(flag) return;
	while(!q[k].empty())
	{
		int df = q[k].front();
		q[k].pop();
		f(pos+1, df);
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int tmpa, tmpb;
		cin>>tmpa>>tmpb;
		q[tmpa].push(tmpb);
		//q[tmpb].push(tmpa);
	}
	for(int i=0;i<n;i++)
	{
		if(flag) break;
		f(0, i);
	}
	if(flag) printf("1");
	else printf("0");
	return 0;
}