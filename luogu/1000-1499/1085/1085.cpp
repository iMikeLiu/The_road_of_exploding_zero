#include<cstdio>
#include<iostream>
using namespace std;
int a,b,maxn=0,day=0;
int main()
{
	freopen("1085.in","r",stdin);
	for(int c=1;c<=7;c++)
	{
		cin>>a>>b;
		if((a+b)>8&&(a+b)>maxn)
		{
			maxn=a+b;
			day=c;	
		}
	}
	cout<<day;
}
