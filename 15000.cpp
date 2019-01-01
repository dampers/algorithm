# include <bits/stdc++.h>

using namespace std;

char alp[1000001];

int main()
{
	scanf("%s", alp);
	for(int i=0;i<strlen(alp);i++)
	{
		alp[i] -= 32;
	}
	printf("%s", alp);
	return 0;
}
