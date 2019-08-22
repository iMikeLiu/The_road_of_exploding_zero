#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
using namespace std;
int n;
struct student{
    int c,m,e,tot,num;//定义 
}s[301];
int cmp( student a, student b){//两个结构体 
    if(a.tot>b.tot)return 1;
    if(a.tot<b.tot)return 0;//总分比较 
    if(a.c>b.c)return 1;
    if(a.c<b.c)return 0;//语文比较 
    if(a.num<b.num)return 1;//序号比较 
    return 0;
}


int main()
{
 	freopen("1093.in","r",stdin);
 //	freopen("1093.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
	{
        scanf("%d%d%d",&s[i].c,&s[i].m,&s[i].e);//语数英读入 
        s[i].tot=s[i].c+s[i].m+s[i].e;//总分计算 
        s[i].num=i+1;//序号 
    }//读入 
    sort(s+0,s+n,cmp);//排序 
    for(int i=0;i<5;i++)
		printf("%d %d\n",s[i].num,s[i].tot);//输出 
 	return 0;
}
