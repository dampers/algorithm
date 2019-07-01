#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
char pass[13] = {'#', '*', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			for(int k=0;k<12;k++)
			{
				for(int l=0;l<12;l++)
				{
					printf("%c%c%c%c\n",pass[i],pass[j],pass[k],pass[l]);
				}
			}
		}
	}
	return 0;
}