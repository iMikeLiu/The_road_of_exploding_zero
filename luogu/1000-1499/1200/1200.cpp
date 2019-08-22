#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
using namespace std;
char a[10],b[10];
int d,mod1,mod2;
long long int ans=1;
int main()
{
	freopen("1200.in","r",stdin);
//	freopen("1200.out","w",stdout);
	scanf("%s%s",&a,&b);
	d=strlen(a);
	for(int c=0;c<d;c++)
	{
		ans=ans*(a[c]-64);
	}
	mod1=ans%47;
	d=strlen(b);
	ans=1;
	for(int c=0;c<d;c++)
	{
		ans=ans*(b[c]-64);
	}
	mod2=ans%47;
	if(mod1==mod2)
	{
		cout<<"GO";
	}
	else
	{
		cout<<"STAY";
	}
	return 0;
}
