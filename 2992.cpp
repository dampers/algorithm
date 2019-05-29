#include <bits/stdc++.h>
using namespace std;

char str[7];
int num[7];
bool check[7];
int len;
int res;
int sum;
vector<int> v;

void f(int pos)
{
	//printf("pos = %d\n", pos);
	if(pos == len)
	{
		v.push_back(res);
	}
	for(int i=0;i<len;i++)
	{
		if(!check[i])
		{
			if(num[i]==0 && pos==0) continue;
			check[i] = true;
			res += num[i]*pow(10,len-pos-1);
			f(pos+1);
			res -= num[i]*pow(10,len-pos-1);
			check[i] = false;
		}
	}
}

int main()
{
	scanf("%s", str);
	len = strlen(str);
	if(len==1)
	{
		printf("0");
		return 0;
	}
	for(int i=0;i<len;i++)
	{
		num[i] = (int)str[i]-'0';
		sum += num[i]*pow(10, len-i-1);
	}
	//printf("sum = %d\n", sum);
	sort(num, num+len);
	f(0);
	sort(v.begin(), v.end());
	int size = v.size();
	if(v[size-1]==sum)
	{
		printf("0");
		return 0;
	}
	for(int i=0;i<size;i++)
	{
		if(sum<v[i])
		{
			printf("%d", v[i]);
			return 0;
		}
	}
	return 0;
}