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
		return (line1.number<line2.number) ;//���������ȣ�����С����ǰ�棬��ˬ�����У����򵥡�
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
    m=m*1.5;//c++��* /�Զ�����ȡ��
    while(player[m].score==player[m+1].score) 
		m=m+1;//���һ����¼�������ȣ���������ȡ
    printf("%d %d\n",player[m].score,m);
    for(int i=1;i<=m;i++){
        printf("%d %d\n",player[i].number,player[i].score);
    }
    return 0;
}
