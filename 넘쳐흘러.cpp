#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	for(int i=0;i<20;i++)
	{
		int m, k;
		scanf("%d %d", &m, &k);
		int cnt = 0, c = 1, flag = 0;
		printf("%d\n", k%m?k%m:m);
		while(k>3*c)
		{
			k -= 3*c;
			if(k<3)
			{
				flag = 1;
				break;
			}
			k -= 2;
			c++;
		}
		if(flag&&k==1) printf("눈이 와~ 눈이 와~\n");
		else if(flag&&k==2) printf("펑펑~\n");
		else if(flag&&k==0) printf("담아서 넘쳐~\n");
		else
		{
			while(k>=3) k-=3;
			switch(k)
			{
				case 1:
				printf("넘쳐서 흘러~\n"); break;
				case 2:
				printf("흘러서 담아~\n"); break;
				case 0:
				printf("담아서 넘쳐~\n"); break;
			}
		}
	}
	return 0;
}
