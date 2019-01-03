#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,max;
	scanf("%d %d %d",&a,&b,&c);
	if(a == b && a == c)
	{
		printf("%d",10000+a*1000);
	}
	else if(a == b || a == c)
	{
		printf("%d",1000+a*100);
	}
	else if( b == c)
	{
		printf("%d",1000+b*100);
	}
	else
	{
		if(a>=b && a>=c)
		{
			max = a;
		}
		else if(b>=a && b>=c)
		{
			max = b;
		}
		else
		{
			max = c;
		}
		printf("%d",max*100);
	}
	return 0;
	}
