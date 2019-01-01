# include <bits/stdc++.h>

using namespace std;

int p[6];

int main()
{
	int a, cnt = 0;
	scanf("%d", &a);
	for(int i=0;i<5;i++)
	{
		scanf(" %d", &p[i]);
		if(p[i] == a) cnt++;
	}
	printf("%d", cnt);
	
	return 0;
}
