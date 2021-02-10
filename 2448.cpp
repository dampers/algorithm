#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

char star[3100][6200];
char standard[3][5] = {{' ', ' ', '*', ' ', ' '}, {' ', '*', ' ', '*', ' '},
						{'*', '*', '*', '*', '*'}};


void divide_conquer(int size, int y, int x)
{
	// stop option.
	if(size == 3)
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<5;j++)
				star[y+i][x+j] = standard[i][j];
		return;
	}

	// center
	divide_conquer(size/2, y, x+size/2);
	// left down
	divide_conquer(size/2, y+size/2, x);
	// right down
	divide_conquer(size/2, y+size/2, x+size);

}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	divide_conquer(n, 0, 0);
	int lsize = n*2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<lsize;j++)
		{
			if(star[i][j] == '*' || star[i][j] == ' ') cout << star[i][j];
			else cout << ' ';
		}
		cout << endl;
	}

	return 0;
}