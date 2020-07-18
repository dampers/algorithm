#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int compn[10][4][4];
char compm[11][5][5];

int gaman[5][5];
char gamam[6][6];

int n;
bool check[11];

int dx[] = {0, 0, 1, 1};
int dy[] = {0, 1, 0, 1};

lld ans;

time_t s, e, tmp;

void add(int k, int num)
{
	int x = dx[k], y = dy[k];

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(compm[num][i][j]!='W') gamam[i+y][j+x] = compm[num][i][j];
			gaman[i+y][j+x] += compn[num][i][j];
			if(gaman[i+y][j+x]<0) gaman[i+y][j+x] = 0;
			else if(gaman[i+y][j+x]>9) gaman[i+y][j+x] = 9;
		}
	}
}

void rotate(int num)
{
	int copyn[4][4];
	char copym[5][5];

	memcpy(copyn, compn[num], sizeof(copyn));
	memcpy(copym, compm[num], sizeof(copym));

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			compn[num][i][j] = copyn[3-j][i];
			compm[num][i][j] = copym[3-j][i];
		}
	}

}

lld ans_check()
{
	lld r , b, g, y;
	r = b = g = y = 0LL;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(gamam[i][j]=='R') r += gaman[i][j];
			else if(gamam[i][j]=='G') g += gaman[i][j];
			else if(gamam[i][j]=='B') b += gaman[i][j];
			else if(gamam[i][j]=='Y') y += gaman[i][j];
		}
	}
	return 7*r+5*b+3*g+2*y;
}

void f(int pos)
{
	if(pos == 3)
	{
		ans = max(ans, ans_check());
		return;
	}

	int copyn[5][5];
	char copym[6][6];

	for(int i=0;i<n;i++)
	{
		if(!check[i])
		{
			memcpy(copyn, gaman, sizeof(copyn));
			memcpy(copym, gamam, sizeof(copym));
			check[i] = true;
			for(int j=0;j<4;j++) //rotate
			{
				for(int k=0;k<4;k++) // 4qure
				{
					add(k, i);
					f(pos+1);
					memcpy(gaman, copyn, sizeof(copyn));
					memcpy(gamam, copym, sizeof(copym));
				}
				rotate(i);
			}
			check[i] = false;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	s = clock();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				cin>>compn[i][j][k];
			}
		}

		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				cin>>compm[i][j][k];
			}
		}
	}

	f(0);

	cout<<ans<<endl;

	//e = clock();
	//cout<<((double)e-s)/1000<<endl;

	return 0;
}