#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int a=2;a<101;a++)
		for(int b=2;b<a;b++)
			for(int c=b;c<a;c++)
				for(int d=c;d<a;d++)
					if(a*a*a==b*b*b+c*c*c+d*d*d)
						printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
	return 0;
}