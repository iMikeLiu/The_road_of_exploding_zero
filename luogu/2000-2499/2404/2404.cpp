#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
#include<cstdlib>
#include<map>
using namespace std;
int a[10001]={1},n,total;
int print(int t)
{
    int i;
    for(i=1;i<=t-1;i++)
       printf("%d+",a[i]);
    printf("%d\n",a[t]);
    total++;
}
int search(int s,int t)
{
    int i;
    for(i=a[t-1];i<=s;i++)
    {
       if(i<n)
       {
           	a[t]=i;
           	s-=i;
           	if(s==0)
			   print(t);
        	else 
				search(s,t+1);
           	s+=i;
       }
   }
}
int main()
{
 	freopen("2404.in","r",stdin);
// 	freopen("2404.out","w",stdout);
    scanf("%d",&n);
    search(n,1);//将将要拆分的数字n递给s


 	return 0;
}

