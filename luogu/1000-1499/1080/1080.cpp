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
int n,l=1,a[100010],b[100010],c[100010],g[1000010];
void gj1(int x)
{
    for(int i=1;i<=l;i++) g[i]*=b[x];
    for(int i=1;i<=l;i++)
    {
        g[i+1]+=(g[i]/10);
        g[i]%=10;
    }
    l++;
    while(g[l]>9)
    {
        g[l+1]+=(g[l]/10);
        g[l]%=10;
        l++;
    }
    if(g[l]==0) l--;
}
void gj2()
{
    for(int i=l;i>=1;i--)
    {
        g[i-1]+=((g[i]%c[n])*10);
        g[i]/=c[n];
    }
    while(g[l]==0) l--;
    if(l==0) printf("1\n");
}
void qsort(int l,int r)
{
    int i=l,j=r,mid=a[(l+r)/2];
    while(i<=j)
    {
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j)
        {
            int t=a[i]; a[i]=a[j]; a[j]=t;
            t=b[i]; b[i]=b[j]; b[j]=t;
            t=c[i]; c[i]=a[j]; c[j]=t;
            i++; j--;
        }
    }
    if(l<j) qsort(l,j);
    if(i<r) qsort(i,r);
}
int main()
{
	freopen("1080.in","r",stdin);
// 	freopen("1080.out","w",stdout);
    scanf("%d",&n);
    scanf("%d %d",&b[0],&c[0]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&b[i],&c[i]);
        a[i]=b[i]*c[i];
    }
    qsort(1,n);
    g[1]=b[0];
    for(int i=1;i<n;i++) gj1(i);
    gj2();
    for(int i=l;i>=1;i--) printf("%d",g[i]);
    return 0;
}

