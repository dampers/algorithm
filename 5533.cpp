#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
struct uni
{
	int num[4];
	int score = 0;
};
struct uni player[201];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) for(int j=0;j<3;j++) cin>>player[i].num[j];
	for(int j=0;j<3;j++)
	{
		for(int i=0;i<n;i++)
		{
			int flag = 0;
			for(int k=0;k<n;k++)
			{
				if(i!=k&&player[i].num[j]==player[k].num[j])
				{
					flag = 1;
					break;
				}
			}
			if(!flag) player[i].score += player[i].num[j];
		}
	}
	for(int i=0;i<n;i++) printf("%d\n", player[i].score);
	return 0;
}