#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

pair<int, int> num[500005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i].first;
		num[i].second = i;
	}
	sort(num, num+n);
	int cnt = 0;
	for(int i=0;i<n;i++)
		cnt = max(num[i].second-i, cnt);
	cout<<cnt+1;
	return 0;
}