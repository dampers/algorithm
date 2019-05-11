#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

char name[160][31];
int alp[28];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %s", name[i]);
		int ind = (int)name[i][0]-'a';
		alp[ind]++;
	}
	int flag = 0;
	for(int i=0;i<27;i++)
	{
		if(alp[i]>=5)
		{
			flag = 1;
			printf("%c", i+'a');
		}
	}
	if(!flag) printf("PREDAJA");
	return 0;
}