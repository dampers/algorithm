#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int main()
{
	int n, m, p;
	scanf("%d", &n);
	int flag = 1, max = 0, pre;
	for(int i=0;i<9;i++)
	{
		pre = max;
		max += 9*(i+1)*pow(10, i);
		if(max<n)
			flag++;
		else
			break;
	}
	if(n<10)
	{
		printf("%d", n);
		return 0;
	}
	n -= pre;
	m = n%flag;
	n = n/flag+pow(10, flag-1);
	if(!m) n--;
	//printf("n = %d m = %d flag = %d pre = %d\n", n, m, flag, pre);
	int ans = n;
	ans /= pow(10, flag-m);
	ans %= 10;
	if(!m) ans = n%10;
	printf("%d", ans);
	return 0;
}