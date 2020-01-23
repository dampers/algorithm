#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int num[1000];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	clock_t start, end;
	start = clock();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	vector<int> v;
	v.push_back(1);
	int key = abs(num[0]), p = 0, dir = num[0]>0?1:-1;
	num[0] = 0;
	for(int i=0;i<n-1;i++)
	{
		while(key>0)
		{
			if(dir>0)
			{
				do
				{
					p++;
					if(p>=n) p = 0;
				}while(num[p]==0);
			}
			else
			{
				do
				{
					p--;
					if(p<0) p = n-1;
				}while(num[p]==0);
			}
			key--;
		}
		key = abs(num[p]);
		dir = num[p]>0?1:-1;
		num[p] = 0;
		v.push_back(p+1);
	}
	int size = v.size();
	for(int i=0;i<size;i++)
		cout<<v[i]<<' ';
	end = clock();
double time = (double)(end-start)/CLOCKS_PER_SEC;
	cout<<"finished at: "<< time;
	return 0;
}