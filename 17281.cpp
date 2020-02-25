#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int bat[55][10];
int nextbat[8] = {1,2,3,5,6,7,8,4};
int mx, n;
int num[8] = {1, 2, 3, 4, 5, 6, 7, 8};
bool check[9];
int cnt;

void simul()
{
	int top = 0, out = 0, point = 0;
	bool flag = false;
	for(int i=0;i<n;i++)
	{
		bool first = false, second = false, third = false;
		//cout<<"n = "<<i<<"\n\n";
		out = 0;
		while(out<3)
		{
			if(top>7) top = 0;
			int batter = nextbat[top];
			if(top==3 && !flag)
			{
				top--;
				batter = 0;
				flag = true;
			}
			else if(top==3 && flag)
			{
				flag = false;
			}
			//cout<<"top = "<<top<<endl;
			//cout<<"batter = "<<batter<<endl;
			//cout<<"<< "<<bat[i][batter]<<" >>"<<endl;
			if(bat[i][batter]==0)
			{
				out++;
			}
			else if(bat[i][batter]==1)
			{
				if(third)
				{
					point++;
					third = false;
				}
				if(second)
				{
					second = false;
					third = true;
				}
				if(first)
				{
					second = true;
					first = false;
				}
				first = true;
			}
			else if(bat[i][batter]==2)
			{
				if(third)
				{
					point++;
					third = false;
				}
				if(second)
				{
					point++;
					second = false;
				}
				if(first)
				{
					third = true;
					first = false;
				}
				second = true;
			}
			else if(bat[i][batter]==3)
			{
				if(third)
				{
					point++;
					third = false;
				}
				if(second)
				{
					second = false;
					point++;
				}
				if(first)
				{
					first = false;
					point++;
				}
				third = true;
			}
			else if(bat[i][batter]==4)
			{
				if(third)
				{
					point++;
					third = false;
				}
				if(second)
				{
					second = false;
					point++;
				}
				if(first)
				{
					first = false;
					point++;
				}
				point++;
			}
			top++;
			//cout<<"point = "<<point<<"\n\n";
		}
	}
	mx = max(point, mx);
}

void next(int pos)
{
	if(pos==8)
	{
		simul();
		/*for(int i=0;i<8;i++)
		{
			cout<<nextbat[i]<<' ';
		}
		cout<<endl;*/
		return;
	}
	for(int i=0;i<8;i++)
	{
		if(check[i]) continue;
		nextbat[pos] = num[i];
		check[i] = true;
		next(pos+1);
		check[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<9;j++)
		{
			cin>>bat[i][j];
		}
	}
	next(0);
	cout<<mx;

	return 0;
}
