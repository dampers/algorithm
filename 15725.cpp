#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char mb[20050];
int main()
{
	int sum = 0;
	scanf(" %s", mb);
	int len = strlen(mb), x = 0;
	for(int i=0;i<len;i++)
	{
		if(mb[i] == 'x')
		{
			int h = 1;
			if(i==0)
				sum++;
			else if(mb[i-1]=='-')
				sum--;
			else if(mb[i-1]=='+')
				sum++; 
			else
			{
				if(mb[x] =='-')
				{
					x++;
					h = -1;
				}
				else if(mb[x] == '+')
					x++;
				for(int j=i-1;j>=x;j--, h*=10)
					sum += h*(mb[j]-48);
				x = i+1;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}