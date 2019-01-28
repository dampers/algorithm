#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
char name[11];
int main()
{
	int n, score;
	cin>>n;
	while(n--)
	{
		scanf(" %s %d", name, &score);
		printf("%s ", name);
		if(97<=score && 100>=score) printf("A+");
		else if(90<=score && 96>=score) printf("A");
		else if(87<=score && 89>=score) printf("B+");
		else if(80<=score && 86>=score) printf("B");
		else if(77<=score && 79>=score) printf("C+");
		else if(70<=score && 76>=score) printf("C");
		else if(67<=score && 69>=score) printf("D+");
		else if(60<=score && 66>=score) printf("D");
		else printf("F");
		printf("\n");
	}
	return 0;
}