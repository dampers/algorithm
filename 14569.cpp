#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int cls[1001][55];
int student[10001][55];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, tmp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		cls[i][0] = k;
		for(int j=1;j<=k;j++)
			cin>>cls[i][j];
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>tmp;
			student[i][tmp] = 1;
		}
		for(int j=0;j<n;j++)
		{
			bool flag = false;
			for(int l=1;l<=cls[j][0];l++)
			{
				if(student[i][cls[j][l]]!=1)
				{
					flag = true;
					break;
				}
			}
			if(!flag) student[i][0]++;
		}
		cout<<student[i][0]<<endl;
	}
	return 0;
}