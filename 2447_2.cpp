#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

char star[7001][7001];
char standard[3][3] = {{'*','*','*'}, {'*',' ','*'}, {'*','*','*'}};

void make_center(int size, int y, int x)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			star[y+i][x+j] = ' ';
	}
}

void divide_conquer(int size, int y, int x)
{
	// stop option
	if(size == 3)
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				star[y+i][x+j] = standard[i][j];
		return ;
	}

	// in option
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			// center
			if(i*3 + j == 4) make_center(size/3, y+i*(size/3), x+j*(size/3));
			else divide_conquer(size/3, y+i*(size/3), x+j*(size/3));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	divide_conquer(n, 0, 0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<star[i][j];
		cout<<endl;
	}

	return 0;
}