#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool check[27];
vector<vector<int> > v(27);

void pre(int pos)
{
	printf("%c", v[pos][0]);
	if(v[pos][1]!='.') pre((int)(v[pos][1]-'A'));
	if(v[pos][2]!='.') pre((int)(v[pos][2]-'A'));
}

void cent(int pos)
{
	if(v[pos][1]!='.') cent((int)(v[pos][1]-'A'));
	printf("%c", v[pos][0]);
	if(v[pos][2]!='.') cent((int)(v[pos][2]-'A'));
}

void after(int pos)
{
	if(v[pos][1]!='.') after((int)(v[pos][1]-'A'));
	if(v[pos][2]!='.') after((int)(v[pos][2]-'A'));
	printf("%c", v[pos][0]);
}

int main()
{
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		char a, b, c;
		scanf(" %c %c %c", &a, &b, &c);
		v[a-'A'].push_back(a);
		v[a-'A'].push_back(b);
		v[a-'A'].push_back(c);
	}
	pre(0);
	printf("\n");
	cent(0);
	printf("\n");
	after(0);
	return 0;
}
