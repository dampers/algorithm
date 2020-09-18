#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

string a[5] = {
	"###...#.###.###.#.#.###.###.###.###.###",
	"#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
	"#.#...#.###.###.###.###.###...#.###.###",
	"#.#...#.#.....#...#...#.#.#...#.#.#...#",
	"###...#.###.###...#.###.###...#.###.###"};


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<vector<string>> nums(10);
	string tmp = "";
	for(int i=0;i<5;i++)
		for(int j=0;j<10;j++)
			nums[j].push_back(tmp+a[i][j*4]+a[i][j*4+1]+a[i][j*4+2]);
	int n;
	cin>>n;
	vector<string> screen(5);
	for(int i=0;i<5;i++)
		cin>>screen[i];
	vector<vector<string>> scnums(n);
	vector<vector<int>> posible(n);

	for(int i=0;i<5;i++)
		for(int j=0;j<n;j++)
			scnums[j].push_back(tmp+screen[i][j*4]+screen[i][j*4+1]+screen[i][j*4+2]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<10;j++)
		{
			bool flag = true;
			for(int k=0;k<5;k++)
			{
				if(!flag) break;
				for(int l=0;l<3;l++)
				{
					if(nums[j][k][l]=='.' && scnums[i][k][l]=='#')
					{
						flag = false;
						break;
					}
				}
			}
			if(flag) posible[i].push_back(j);
		}
	}
	double avg = 0.0;
	bool flag = true;
	for(int i=0;i<posible.size();i++)
	{
		double sum = 0.0;
		if(posible[i].size()==0)
		{
			flag = false;
			break;
		}
		for(int j=0;j<posible[i].size();j++)
			sum += posible[i][j]*pow(10, n-i-1);
		avg += sum/posible[i].size();
	}
	if(!flag) cout<<-1;
	else cout<<setprecision(10)<<avg;
	return 0;
}
