#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
using namespace std;
int n,r,q;
#define maxn 200011
#define maxm 100011
struct people
{
	int s,w,num;
}dat[maxn],w[maxm],l[maxm];
bool cmp(people a,people b)
{
    if (a.s==b.s)
        return a.num<b.num;
    else
        return a.s>b.s;
}


int main()
{
 	freopen("1309.in","r",stdin);
// 	freopen("1309.out","w",stdout);
 	scanf("%d%d%d",&n,&r,&q);
 	n*=2;
 	for(int i=1;i<=n;i++)
 		scanf("%d",&dat[i].s);
 	for(int i=1;i<=n;i++)
 		scanf("%d",&dat[i].w),dat[i].num=i;
 	sort(dat+1,dat+n+1,cmp);
 	for(int i=1;i<=r;i++)
 	{
 		int win=0,lose =0;
 		for(int j=1;j<=n;j+=2)
 		{
 			if(dat[j].w >dat[j+1].w )
 			{
 				w[++win]=dat[j];
                w[win].s++;
                l[++lose]=dat[j+1];
 			}
 			else
 			{
 				w[++win]=dat[j+1];
                w[win].s++;
                l[++lose]=dat[j];	
 			}
 		}
 		merge(w+1,w+win+1,l+1,l+lose+1,dat+1,cmp);
 	}
 	printf("%d",dat[q].num );
 	



 	return 0;
}


