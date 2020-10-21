#include <iostream>
int main(){int a,b,c,d;std::cin>>a>>b>>c;d=c%(7*a+b);std::cout<<7*(c/(7*a+b))+((d/a>=7)?7:((d/a)+(d%a?1:0)));}