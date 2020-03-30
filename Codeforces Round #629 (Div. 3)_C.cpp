#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

char one[50005], a[50005], b[50005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	scanf(" %d", &tc);
	while(tc--)
	{
		int n;
		scanf(" %d", &n);
		scanf(" %s", one);
		memset(a, '\0', sizeof(a));
		memset(b, '\0', sizeof(b));
		int aone = 0, bone = 0;
		int flag = 0;
		for(int i=0;i<n;i++)
		{
			a[i] = '0';
			b[i] = '0';
			if(one[i]=='2')
			{
				if(flag==0)
				{
					a[i] = '1';
					b[i] = '1';
				}
				else
				{
					if(flag==1)
					{
						a[i] = '2';
					}
					else
					{
						b[i] = '2';
					}
				}
			}
			if(one[i]=='1')
			{
				if(flag==0)
				{
					a[i] = '1';
					flag = -1;
				}
				else
				{
					if(flag==1)
					{
						a[i] = '1';
					}
					else
					{
						b[i] = '1';
					}
				}
			}
		}
		printf("%s\n%s\n", a, b);
	}
	return 0;
}