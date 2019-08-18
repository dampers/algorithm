#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int table[26][2];
int check[6][2];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tmp;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>tmp;
			table[tmp][0] = i;
			table[tmp][1] = j;
		}
	}
	int cnt = 0, bingo = 0;
	while(bingo<3)
	{
		bingo = 0;
		cnt++;
		cin>>tmp;
		check[table[tmp][0]][0]++;
		check[table[tmp][1]][1]++;
		if(table[tmp][0]+table[tmp][1]==4) check[5][0]++;
		if(table[tmp][0]==table[tmp][1]) check[5][1]++;
		for(int i=0;i<6;i++)
			for(int j=0;j<2;j++)
				if(check[i][j]==5) bingo++;
	}
	cout<<cnt;
	return 0;
}