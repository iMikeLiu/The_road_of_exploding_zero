#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;
int m,n,k,l,d;
int x,y,p,q;
typedef struct 
{
	int num,count;
}data;
data i[1011],j[1011];
//i/k,m对应的
//j/l,n对应的 
bool cmp(data a,data b)
{
	if(a.count>b.count)
		return true;
	return false;
}
bool cmp2(data a,data b)
{
	if(a.num<b.num)
		return true;
	return false;
}
int main()
{
    freopen("1056.in","r",stdin);
//    freopen("1056.out","w",stdout);
	scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
	for(int c=0;c<d;c++)
	{
		scanf("%d%d%d%d",&x,&y,&p,&q);
		if(x==p)
		{
			j[min(y,q)].count++;
			j[min(y,q)].num=min(y,q);
		}
		else if(y==q)
		{
			i[min(x,p)].count++;
			i[min(x,p)].num=min(x,p);
		}
	}
	sort(i,i+m,cmp);
	sort(j,j+n,cmp);
	sort(i,i+k,cmp2);
	sort(j,j+l,cmp2);
	for(int c=0;c<k;c++)
		printf("%d ",i[c].num );
	cout<<endl;
	for(int c=0;c<l;c++)
		printf("%d ",j[c].num );
	

    return 0;
}
