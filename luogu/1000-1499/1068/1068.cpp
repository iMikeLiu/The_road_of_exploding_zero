#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;
typedef struct 
{
	int number,score;
}people;
bool cmp(people line1,people line2)
{
    if(line1.score==line2.score) 
		return (line1.number<line2.number) ;//如果分数相等，号码小的在前面，最爽的排列，超简单。
    else    
		return (line1.score>line2.score) ;
}
people player[10000] ;
int m,n,peoper=0;
int main()
{
	freopen("1068.in","r",stdin);
//	freopen("1068.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
		scanf("%d%d",&player[i].number,&player[i].score);
    sort(player+1,player+n+1,cmp);
    m=m*1.5;//c++中* /自动向下取整
    while(player[m].score==player[m+1].score) 
		m=m+1;//最后一个记录，如果相等，继续向下取
    printf("%d %d\n",player[m].score,m);
    for(int i=1;i<=m;i++){
        printf("%d %d\n",player[i].number,player[i].score);
    }
    return 0;
}
