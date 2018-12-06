#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int w[11], k[11];

int main(){

	for(int i=0;i<10;i++)
	{
		scanf(" %d", &w[i]);
	}
	sort(w, w+10);
	for(int i=0;i<10;i++)
	{
		scanf(" %d", &k[i]);
	}
	sort(k,k+10);
	int sumw = w[9]+w[8]+w[7];
	int sumk = k[9]+k[8]+k[7];
	printf("%d %d", sumw, sumk);
	return 0;
}