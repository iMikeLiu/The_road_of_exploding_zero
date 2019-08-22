#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
using namespace std;
struct person{
    int id,w;
}dat[10000001]; //结构体，方便些
int n,k,e[11];
bool cmp(person a,person b)
{
    if(a.w==b.w) 
		return a.id<b.id;
    return a.w>b.w;
}


int main()
{
 	freopen("1583.in","r",stdin);
// 	freopen("1583.out","w",stdout);
 	scanf("%d%d",&n,&k); //输入
    for(int i=1;i<=10;i++) 
		scanf("%d",&e[i]);
    for(int i=0;i<n;i++)
	{
        scanf("%d",&dat[i].w);
        dat[i].id=i+1;    
    } 
    sort(dat,dat+n,cmp); //sort函数，需带algorithm头文件
    for(int i=0;i<n;i++)
        dat[i].w+=e[i%10+1];
    sort(dat,dat+n,cmp); 
    for(int i=0;i<k;i++) 
		printf("%d ",dat[i].id); //输出
    return 0;   


}
