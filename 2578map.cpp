#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int check[2][6];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	map<int, pair<int, int> > mp;
	int tmp;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>tmp;
			mp[tmp] = make_pair(i, j);
		}
	}
	int cnt = 0, bingo = 0;
	while(bingo<3)
	{
		cnt++;
		bingo = 0;
		cin>>tmp;
		check[0][mp[tmp].first]++;
		check[1][mp[tmp].second]++;
		if(mp[tmp].first==mp[tmp].second) check[0][5]++;
		if(mp[tmp].second+mp[tmp].first==4) check[1][5]++;
		for(int i=0;i<2;i++)
			for(int j=0;j<6;j++)
				if(check[i][j]==5) bingo++;
	}
	cout<<cnt;
	return 0;
}