#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	vector <int> v;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		v.push_back(i);
	int ind = -1;
	cout<<"<";
	while(n--)
	{
		ind += k;
		int size = v.size();
		ind %= size;
		cout<<v[ind];
		if(n>0) cout<<", ";
		v.erase(v.begin()+ind, v.begin()+ind+1);
		ind--;
	}
	cout<<'>';
	return 0;
}