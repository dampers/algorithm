#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int num[100001];
int main()
{
	int k, tmp, sum = 0, j = 0;
	scanf(" %d", &k);
	for (int i = 0; i < k;i++)
	{
		scanf(" %d", &tmp);
		if(!tmp)
		{
			sum -= num[j];
			num[j] = 0;
			j--;
		}	
		else
		{
			j++;
			num[j] = tmp;
			sum += tmp;
		}
	}
	printf("%d", sum);
	return 0;
}