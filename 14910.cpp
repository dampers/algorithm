#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tmp, ttmp;
	scanf(" %d", &tmp);
	ttmp = tmp;
	bool flag = true;
	while(scanf(" %d", &tmp)==1)
	{
		if(tmp<ttmp)
			flag = false;
		ttmp = tmp;
	}
	if(flag)
		printf("Good");
	else
		printf("Bad");
	return 0;
}