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
    int c,m,e,tot,num;//���� 
}s[301];
int cmp( student a, student b){//�����ṹ�� 
    if(a.tot>b.tot)return 1;
    if(a.tot<b.tot)return 0;//�ֱܷȽ� 
    if(a.c>b.c)return 1;
    if(a.c<b.c)return 0;//���ıȽ� 
    if(a.num<b.num)return 1;//��űȽ� 
    return 0;
}


int main()
{
 	freopen("1093.in","r",stdin);
 //	freopen("1093.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
	{
        scanf("%d%d%d",&s[i].c,&s[i].m,&s[i].e);//����Ӣ���� 
        s[i].tot=s[i].c+s[i].m+s[i].e;//�ּܷ��� 
        s[i].num=i+1;//��� 
    }//���� 
    sort(s+0,s+n,cmp);//���� 
    for(int i=0;i<5;i++)
		printf("%d %d\n",s[i].num,s[i].tot);//��� 
 	return 0;
}
