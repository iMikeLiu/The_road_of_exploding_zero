#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;
int n,k;
int main()
{
    freopen("1067.in","r",stdin);
//    freopen("1067.out","w",stdout);
    scanf("%d",&n);
    for(int i=n;i>=0;i--)
    {
        scanf("%d",&k);
        if(k==0)
            continue;
        if(k<0)
           	printf("-");
        else
         	if(i!=n)
            	printf("+");
        k=abs(k);
        if(k!=1||i==0)
        	printf("%d",k);
        if(i!=0&&i!=1)
        	printf("x^%d",i);
        if(i==1)
        	printf("x");
        
    }
    return 0;
}
