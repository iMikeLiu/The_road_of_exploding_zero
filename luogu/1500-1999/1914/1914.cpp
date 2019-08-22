#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 10000001
long long n;
char in[MAXN];
int main()
{
	freopen("1914.in","r",stdin);
	scanf("%lld%s",&n,in);
	for(int i=0;in[i]!=0;i++)
	{
		putchar((in[i]-'a'+n)%26+'a');
	}
	return 0;	
} 
