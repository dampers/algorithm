#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

class Compare
{
public:
	bool operator()(const pair<int, int> a, const pair<int, int> b)
	{return a.second>b.second}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	pq.push(1);
	cout<<pq.top();
	pq.pop();
	return 0;
}