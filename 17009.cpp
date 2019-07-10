#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int na = 0, nb = 0;
	for(int i=3;i>=1;i--)
	{
		int tmp;
		scanf(" %d", &tmp);
		na += tmp*i;
	}
	for(int i=3;i>=1;i--)
	{
		int tmp;
		scanf(" %d", &tmp);
		nb += tmp*i;
	}
	if(na>nb)
		printf("A");
	else if(na<nb)
		printf("B");
	else
		printf("T");
	return 0;
}