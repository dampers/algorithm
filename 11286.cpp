#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
class comp
{
public:
	bool operator()(int a, int b)
	{
		if(abs(a)==abs(b)) return a>b;
		else return abs(a)>abs(b);
	}
};
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, tmp;
	cin>>n;
	priority_queue<int, vector<int>, comp> pq;
	while(n--)
	{
		cin>>tmp;
		if(tmp) pq.push(tmp);
		else
		{
			if(pq.empty()) cout<<0<<endl;
			else
			{
				cout<<pq.top()<<endl;
				pq.pop();
			}
		}
	}
	return 0;
}