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
struct a  
{
 	int b,num;   
}data[1010];
bool cmp(a x,a y)
{
 	return x.b<y.b;    
}
int main()
{
	freopen("1223.in","r",stdin);
// 	freopen("1223.out","w",stdout);
 	int n,i,j;
 	double time=0;
 	scanf("%d",&n); 
 	for(i=1;i<n+1;i++)   
		scanf("%d",&data[i].b),data[i].num=i;
 	sort(data+1,data+n+1,cmp);
  	for(i=1;i<=n;i++)
   		printf("%d ",data[i].num); 
  	printf("\n"); 
	for(j=n-1;j>=1;j--)
		i=n-j,time+=data[i].b*j;
 	printf("%.2lf",time/n);//算平均，保留两位小数
  	return 0; 
}
