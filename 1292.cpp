#include <iostream>
#include <vector>

using namespace std;

int main()
{

	int n, m;
	cin >> n >> m;
	vector<int> v;
	v.push_back(1);
	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<i;j++)
		{
			v.push_back(i+v.back());
		}
	}
	cout << v[m]-v[n-1];

	return 0;
}