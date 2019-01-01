# include<bits/stdc++.h>

using namespace std;
int num[5];
int rev(int x)
{
	int d = x, i = 0, c;
	if(x/1000) c = 1000;
	else if(x/100) c = 100;
	else if(x/10) c= 10;
	else c = 1;
	for(int j=0;j<5;j++) num[j] = 0;
	while(d>0)
	{
		num[i] = d%10;
		d = d/10;
		i++;
	}
	int tmp;
	tmp = num[0]*c+num[1]*c/10+num[2]*c/100+num[3]*c/1000;
	return tmp;
}
int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d", rev(rev(x)+rev(y)));
	return 0;
}
