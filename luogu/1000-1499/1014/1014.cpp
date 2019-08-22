#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;
long long x,i;
int main()
{
	freopen("1014.in","r",stdin);
	//freopen("1014.out","w",stdout);
	cin>>x;
	for(i=0;i<x;i++)
	{
		x-=i;
	}
	//x个数，i行数 
	if(i%2==0)
	{
		printf("%d/%d",x,i+1-x);
	}
	else
	{
		printf("%d/%d",i+1-x,x);
	}
	
	
    return 0;
}
