#include<bits/stdc++.h>
using namespace std;
int seq[51];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf(" %d", &seq[i]);
	if(seq[1]-seq[0]==seq[2]-seq[1]) printf("%d", seq[n-1]+(seq[1]-seq[0]));
	else printf("%d", seq[n-1]*(seq[1]/seq[0]));
	return 0;
}
