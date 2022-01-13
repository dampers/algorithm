#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

bool flag = false;
int n;

void printAns(int hello, int world)
{
    cout << "  " << hello << endl;
    cout <<"+ " << world << endl;
    cout << "-------\n";
    if(hello + world < 99999) cout << " ";
    cout << " " << hello + world;
}

void f(int pos, vector<int>& v, vector<bool>& check)
{
    //if(v[1]*10000 + v[0]*10000 > n) return;
    if(pos == v.size())
    {
        int hello = v[1]*10000 + v[2]*1000 + v[3]*100 + v[3]*10 + v[4];
        int world = v[0]*10000 + v[4]*1000 + v[5]*100 + v[3]*10 + v[6];
        if(hello + world == n)
        {
            flag = true;
            printAns(hello, world);
        }
        return;
    }
    for(int i=0;i<10;i++)
    {
        if(check[i]) continue;
        if(i == 0 && (pos == 1 || pos == 0)) continue;
        check[i] = true;
        v[pos] = i;
        f(pos+1, v, check);
        check[i] = false;
        if(flag) return;
    }
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<int> v(7, 0);
	vector<bool> check(10, false);
	f(0, v, check);
	if(flag == false) cout << "No Answer";
	
	

	return 0;
}