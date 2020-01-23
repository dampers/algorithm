#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int num[6], color[6], onum[6], cnt[10];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<5;i++)
	{
		char tmp;
		scanf(" %c %d", &tmp, &num[i]);
		if(tmp=='R') num[i]+=10;
		else if(tmp=='B') num[i]+=20;
		else if(tmp=='Y') num[i]+=30;
		else if(tmp=='G') num[i]+=40;
	}
	int point = 0;
	sort(num, num+5);
	for(int i=0;i<5;i++)
	{
		onum[i] = num[i]%10;
		color[i] = num[i]-onum[i];
		cnt[onum[i]]++;
	}
	for(int i=1;i<=9;i++)
	{
		if(cnt[i]==4) point = max(point, 800+i); //2
		if(cnt[i]==3)
		{
			for(int j=1;j<=9;j++)
			{
				if(i==j) continue;
				if(cnt[j]==2) point = max(point, 700+i*10+j); //3
			}
			point = max(point, 400+i); //6
		}
		if(cnt[i]==2)
		{
			point = max(point, 200+i); //8
			for(int j=1;j<=9;j++)
			{
				if(i==j) continue;
				if(cnt[j]==2) point = max(point, 300+(max(i, j)*10)+min(i, j)); //7
			}
		}
	}
	//1 4 5 9
	if(num[0]+1==num[1] && num[1]+1==num[2] && num[2]+1==num[3] && num[3]+1==num[4])
		point = max(900+(num[4]%10), point); //1
	sort(onum, onum+5);
	if(color[0]==color[1]&&color[1]==color[2]&&color[2]==color[3]&&color[3]==color[4])
		point = max(600+onum[4], point); //4
	if(onum[0]+1==onum[1] && onum[1]+1==onum[2] && onum[2]+1==onum[3] && onum[3]+1==onum[4])
		point = max(point, 500+onum[4]); //5
	point = max(100+onum[4], point); //9
	cout<<point;
	return 0;
}