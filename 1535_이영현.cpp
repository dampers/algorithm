#include <bits/stdc++.h>
 
using namespace std;

int n, mx=0, happy = 0, hp = 100;
int hurt[21];
int gain[21];
//줜나 어렵네유 
void f(int pos, int happy, int hp)
{
	if(pos==n)
	{
		if(hp>0){
			if(mx<happy) mx = happy;
		}
		
		return;
	}
	
	f(pos+1, happy, hp);//인사 안하고 건너뛰는 경우 
	
	f(pos+1, happy+gain[pos], hp-hurt[pos]);//인사하고 다음으로 
	
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
		scanf(" %d", &hurt[i]);
	for(int i = 0; i<n; i++)
		scanf(" %d", &gain[i]);
		
	f(0, happy, hp);
	printf("%d", mx);
	return 0;
}