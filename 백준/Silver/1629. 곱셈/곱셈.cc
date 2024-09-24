#include <iostream>
#define l long long
int muls(l a,l b,l c){l tmp=a,ret=1;while(b){if(b&1)ret=(ret*tmp)%c;tmp=(tmp*tmp)%c;b>>=1;}return ret;}int main(){l a,b,c;std::cin>>a>>b>>c;std::cout<<muls(a,b,c);return 0;}