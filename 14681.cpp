# include<bits/stdc++.h>

using namespace std;

int main()
{
	int x, y, s;
	scanf("%d %d", &x, &y);
	if(x>0&&y>0) s = 1;
	else if(x<0&&y>0) s = 2;
	else if(x<0&&y<0) s = 3;
	else s = 4;
	printf("%d", s);
	return 0;
}
