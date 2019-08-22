#include<iostream>
#include<cstdio>
using namespace std;
int count,in;
int dp(int in)
{
	if(in<=1)
		return 0;
	int a=in/2;
	count+=a;
	for(int i=1;i<=a;i++)
		dp(i);
}
int main()
{
	freopen("1028.in","r",stdin);
	scanf("%d",&in);
	count=1;
	dp(in);
	printf("%d",count);
	
	return 0;
	
} 
