#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int n, l, r;

bool brute_force(string& a, string& b, int pos, int n, int check, int aindex)
{
	if(pos==n) return true;
	bool ret = false;
	if(aindex==l || aindex==r) aindex++;
	if(aindex<n && b[pos]==a[aindex])
		ret |= brute_force(a, b, pos+1, n, check, aindex+1);
	if(check==0 && b[pos]==a[l])
		ret |= brute_force(a, b, pos+1, n, 1, aindex);
	if(check==1 && b[pos]==a[r])
		ret |= brute_force(a, b, pos+1, n, 2, aindex);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	string a, b, tmp = "";
	cin>>a>>b;
	cin>>l>>r;
	if(brute_force(a, b, 0, n, 0, 0)) cout<<"YES";
	else cout<<"NO";
	return 0;
}