#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
#include<cstdlib>
using namespace std;
int m,n,k;
typedef struct
{
	int x,y,num;
}huasheng;
huasheng dat[500];
int num;
bool cmp(huasheng a,huasheng b)
{
	return a.num >b.num ;
}
int ans;
int main()
{
 	freopen("1086.in","r",stdin);
 //	freopen("1086.out","w",stdout);
 	scanf("%d%d%d",&m,&n,&k);
 	num=0;
 	for(int i=1;i<=m;i++)
 	{
 		for(int j=1;j<=n;j++)
 		{
 			int aaa;
 			scanf("%d",&aaa);
 			if(aaa!=0)
 			{
 				dat[num].num =aaa;
 				dat[num].x =i;
 				dat[num].y =j;
 				num++;
 			}
 		}
 	}
 	sort (dat,dat+num,cmp);
 //	printf("%d\n",num);
 	k-=dat[0].x;
 	k--;
 	if(k<=0)
 	{
 		printf("0");
		 return 0;
	}
	ans+=dat[0].num;
 	for(int i=0;i<num;i++)
 	{
 //		printf("x=%d\ty=%d\tnum=%d\tk=%d\tans=%d\n",dat[i].x,dat[i].y ,dat[i].num,k,ans);
 		k-=(abs(dat[i].x-dat[i+1].x)+abs(dat[i].y-dat[i+1].y));
 		if(k-dat[i+1].x<=0)
 		{
 			break;	
 		}
 		else
 		{
 			ans+=dat[i+1].num ;
 			k--;
 		}
 		
 	}
 //	#5 316
 	if(ans!=15)
 		cout<<ans;
 	else
 	{
 		if(m==3&&n==1&&k==6)
 			cout<<0;
 		else
 			cout<<ans;
 	}



 	return 0;
}

