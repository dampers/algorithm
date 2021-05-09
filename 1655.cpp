#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, less<int>> mx_heap;
	priority_queue<int, vector<int>, greater<int>> mn_heap;
	int tmp;
	while(n--)
	{
		cin >> tmp;
		mx_heap.push(tmp);

		while(!mx_heap.empty() && !mn_heap.empty() && mn_heap.top() < mx_heap.top())
		{
			tmp = mn_heap.top();
			mn_heap.pop();
			mn_heap.push(mx_heap.top());
			mx_heap.pop();
			mx_heap.push(tmp);
		}
		tmp = (mx_heap.size()+mn_heap.size()) % 2;
		while(mn_heap.size()+tmp < mx_heap.size())
		{
			mn_heap.push(mx_heap.top());
			mx_heap.pop();
		}
		cout << mx_heap.top() << endl;
	}
	return 0;
}