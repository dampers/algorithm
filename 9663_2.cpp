#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int queen[16];
int n;

int backtrack(int pos, int k)
{
	if(pos>n) return 1;
	int res = 0;
	for(int i=1;i<=n;i++)
	{
		bool flag = false;
		for(int j=1;j<pos;j++)
		{
			if(queen[j]==i || abs(pos-j)==abs(i-queen[j]))
			{
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			queen[pos] = i;
			res += backtrack(pos+1, i);
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	cout<<backtrack(1, 1);
	return 0;
}