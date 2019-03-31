#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, cntn = 0, cnt = 0;
	scanf("%d", &n);
	int tmp = n;
	while(n > 1)
	{
		if(n%4==0)
		{
			n /= 4;
			cntn+=2;
			continue;
		}
		if(n%3 == 0) n = n/3;
		else if((n-1)%3==0) n--;
		else if(n%2==0) n = n/2;
		else n--;
		cntn++;
	}
	n = tmp;
	while(n > 1)
	{
		
		if(n%3 == 0) n = n/3;
		else if((n-1)%3==0) n--;
		else if(n%2==0) n = n/2;
		else n--;
		cnt++;
	}
	cnt = cnt<cntn?cnt:cntn;
	printf("%d", cnt);
	return 0;
}