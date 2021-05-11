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
	priority_queue<int, vector<int>, greater<int>> mn_heap;
	priority_queue<int, vector<int>, less<int>> mx_heap;
	
	int tmp;
	for(int i=0;i<n;i++)
	{
		cin >> tmp;
		mx_heap.push(tmp);
		while(!mn_heap.empty() && mx_heap.top() > mn_heap.top())
		{
			tmp = mn_heap.top();
			mn_heap.pop();
			mn_heap.push(mx_heap.top());
			mx_heap.pop();
			mx_heap.push(tmp);
		}
		tmp = (mx_heap.size()+mn_heap.size())%2;
		while(mx_heap.size() > mn_heap.size()+tmp)
		{
			mn_heap.push(mx_heap.top());
			mx_heap.pop();
		}
		cout << mx_heap.top() << endl;
	}
	
	return 0;
}