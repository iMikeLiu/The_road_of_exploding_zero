#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;
int n,m;
int a[1111];
int main()
{
    freopen("1059.in","r",stdin);
 //   freopen("1059.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);//输入 
    sort(a,a+n);//sort排序 
    int m=unique(a,a+n)-a;//unique函数调用 
    printf("%d\n",m);
    for(int i=0;i<m;i++)
        printf("%d ",a[i]);//输出 
    return 0;
}
