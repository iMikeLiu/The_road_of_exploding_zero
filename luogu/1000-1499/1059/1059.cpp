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
        scanf("%d",&a[i]);//���� 
    sort(a,a+n);//sort���� 
    int m=unique(a,a+n)-a;//unique�������� 
    printf("%d\n",m);
    for(int i=0;i<m;i++)
        printf("%d ",a[i]);//��� 
    return 0;
}
