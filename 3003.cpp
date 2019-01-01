# include <bits/stdc++.h>

using namespace std;

int pin[7];

int main()
{
	for(int i=0;i<6;i++)
	{
		scanf("%d", &pin[i]);
	}
	printf("%d %d %d %d %d %d", 1-pin[0], 1-pin[1], 2-pin[2], 2-pin[3], 2-pin[4], 8-pin[5]);
	return 0;
}
