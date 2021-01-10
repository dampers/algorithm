#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

string div_s(vector<string>& v, int size, int y, int x)
{
	bool flag = true;
	for(int i=y;i<y+size;i++)
		for(int j=x;j<x+size;j++)
			if(v[i][j]!=v[y][x])
				flag = false;
	if(flag) return string(1, v[y][x]);
	size /= 2;
	return "("+div_s(v, size, y, x)+div_s(v, size, y, x+size)+div_s(v, size, y+size, x)+div_s(v, size, y+size, x+size)+")";

}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;
	vector<string> v(n, "");
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<div_s(v, n, 0, 0);
	
	return 0;
}