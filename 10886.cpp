#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main(){
	int n, i, cnt = 0, k;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf(" %d", &k);
		if(k) cnt++;
		else cnt--;
	}
	if(cnt>0) printf("Junhee is cute!");
	else printf("Junhee is not cute!");
	return 0;
}