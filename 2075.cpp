#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, tmp;
	cin>>n;
	int s = n*n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0;i<s;i++)
	{
		cin>>tmp;
		pq.push(tmp);
		if(pq.size()>n) pq.pop();
	}
	cout<<pq.top();
	return 0;
}