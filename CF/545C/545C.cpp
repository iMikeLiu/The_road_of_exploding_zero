#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
using namespace std;
#define MAXN 100011
typedef struct
{
	int x,h;
}tree;
tree data[MAXN];
bool cmp(tree a,tree b)
{
	return a.x<b.x;
}
int main()
{
 	freopen("545C.in","r",stdin);
// 	freopen("545C.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&data[i].x,&data[i].h);	
	sort(data,data+n,cmp);
//	for(int i=0;i<n;i++)fprintf(stderr,"%d %d\n",data[i].x,data[i].h);	
	int ans=1;
	int left=1;
	if(n==1){printf("1");return 0;}
	for(int i=1;i<n-1;i++)
		if(data[i].x-data[i].h>data[i-1].x&&data[i].x-data[i].h>left)//向左倒 
			ans++;
		else if(data[i].x+data[i].h<data[i+1].x)//向右道
			left=data[i].x+data[i].h,ans++;
		//else fprintf(stderr,"%i no\n",i);
	printf("%d",++ans);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}