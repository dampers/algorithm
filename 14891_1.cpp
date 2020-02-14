#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

unsigned char t[5];
bool check[4];

void rotate(int &dir, int q, int k)
{
    unsigned char tmp;
    if(dir==1) t[q] = (t[q]<<1)+(t[q]&128?1:0);
    else t[q] = (t[q]>>1)+(t[q]&1?128:0);
    if(k) dir *= -1;
}

int main()
{
	for(int i=0;i<4;i++)
		for(int j=1;j<=128;j<<=1)
		{
			unsigned char c;
			scanf(" %c", &c);
			t[i] += (c-'0')*j;
		}
	int k, one, dir;
	scanf(" %d", &k);
	while(k--)
	{
		scanf(" %d %d", &one, &dir);
		memset(check, false, sizeof(check));
		for(int i=0;i<3;i++)
			if(t[i]&4&&!(t[i+1]&64)||!(t[i]&4)&&(t[i+1]&64)) check[i] = true;
		rotate(dir, one-1, 1);
		if(one==1)
			for(int i=0;i<3;i++)
				if(check[i]) rotate(dir, i+1, 1);
				else break;
		if(one==2)
		{
			if(check[0]) rotate(dir, 0, 0);
			for(int i=1;i<3;i++)
				if(check[i]) rotate(dir, i+1, 1);
				else break;
		}
		if(one==3)
		{
			if(check[2]) rotate(dir, 3, 0);
			for(int i=1;i>=0;i--)
				if(check[i]) rotate(dir, i, 1);
				else break;
		}
		if(one==4)
			for(int i=2;i>=0;i--)
				if(check[i]) rotate(dir, i, 1);
				else break;
	}
	int cnt = 0;
	for(int i=0;i<4;i++)
		if(t[i]&1) cnt += 1<<i;
	printf("%d", cnt);
	return 0;
}