#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int rotatea[10][5] = {
	{0, 1, 2, -1, -1},
	{3, 7, 9, 11, -1},
	{4, 10, 14, 15, -1},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15, -1},
	{3, 14, 15, -1, -1},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13},
};
lld mncnt = 987654321LL;

bool check(vector<int>& v)
{
	for(int i=0;i<16;i++)
		if(v[i]!=12)
			return false;
	return true;
}

void rotates(vector<int>& v, int k)
{
	for(int i=0;i<5;i++)
	{
		if(rotatea[k][i]==-1) break;
		v[rotatea[k][i]] = (v[rotatea[k][i]]+3)%12 ? (v[rotatea[k][i]]+3)%12:12;
	}
}

void f(int pos, vector<int>& v, lld cnt)
{
	if(pos==10)
	{
		if(check(v)) mncnt = min(cnt, mncnt);
		return;
	}
	for(int i=0;i<4;i++)
	{
		f(pos+1, v, cnt+i);
		rotates(v, pos);
	}
}


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		vector<int> v(16);
		mncnt = 987654321LL;
		for(int i=0;i<16;i++)
			cin>>v[i];
		f(0, v, 0LL);
		if(mncnt==987654321LL) cout<<-1<<endl;
		else cout<<mncnt<<endl;
	}
	return 0;
}