#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int m, n;
	scanf("%d %d", &m, &n);
	if(m==0)
	{
		printf("0");
		return 0;
	}
	vector<int> v;
	while(m)
	{
		int tmp = m%n;
		v.push_back(tmp);
		m /= n;
	}
	int size = v.size();
	for(int i=0;i<size;i++)
	{
		int tmp = v.back();
		if(tmp>9)
			printf("%c", 'A'-10+tmp);
		else
			printf("%d",tmp);
		v.pop_back();
	}
	return 0;
}