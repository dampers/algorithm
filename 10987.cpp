#include<bits/stdc++.h>
using namespace std;
char word[101];
int main()
{
	scanf("%s", word);
	int cnt=0;
	for(int i=0;i<strlen(word);i++)
	{
		if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u') cnt++;
	}
	printf("%d", cnt);
	return 0;
}
