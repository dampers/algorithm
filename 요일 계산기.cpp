#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int f = 0;
	int y = 2007, m, d;
	cout<<"요일을 알고싶은 날짜를 입력하세요 (ex) 2019 06 29) :";
	cin>>y>>m>>d;
	if(y>=2007)
	{
		for(int i=0;i<y-2007;i++)
		{
			int asd = 2007+i;
			if((asd%4==0 && asd%100!=0 ) || asd%400==0) f = 1;
			else f = 0;
			d += 1+f;
		}
	}
	else
	{
		for(int i=0;i<2007-y;i++)
		{
			if(i%4==0 && i%100!=0 && i%400==0) f = 1;
			else f = 0;
			d -= f+1;
			if(d<1) d += 7;
		}
	}
	if(y%4==0 && y%100!=0 && y%400==0) f = 1;
	else f = 0;
	for(int i=1;i<m;i++)
	{
		if(i==2) d += 28+f;
		else if(i<=7 && i%2==1) d += 31;
		else if(i>7 && i%2==0) d += 31;
		else d += 30;
	}
	switch(d%7)
	{
		case 1:
			cout<<"MON";
			break;
		case 2:
			cout<<"TUE";
			break;
		case 3:
			cout<<"WED";
			break;
		case 4:
			cout<<"THU";
			break;
		case 5:
			cout<<"FRI";
			break;
		case 6:
			cout<<"SAT";
			break;
		case 0:
			cout<<"SUN";
			break;
	}
	return 0;
}
