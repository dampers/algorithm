#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

void divide_conque(string& k, int size, int start)
{
	if(size == 1) return;
	size /= 3;
	int end = start+size+size;
	for(int i=start+size;i<end;i++)
		k[i] = ' ';
	divide_conque(k, size, start);
	divide_conque(k, size, end);
}

int main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	while(scanf("%d", &n) == 1)
	{
		string k = string((int)pow(3, n), '-');
		divide_conque(k, k.size(), 0);
		cout << k << endl;
	}
	return 0;
}