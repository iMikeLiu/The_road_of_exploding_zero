#include<iostream>
#include <cstdio>
using namespace std;
int r[30][2]={0},s[30][2]={0};
int main()
{
	//r车上人数，s上车人数 
	r[1][0]=1;r[1][1]=0;//0 a的系数，1 b的系数	
	s[1][0]=1;s[1][1]=0;
	r[2][0]=1;r[2][1]=0;	
	s[2][0]=0;s[2][1]=1;
	for(int i=3;i<=20;i++)
	{
		r[i][0]=r[i-1][0]+s[i-2][0];
		r[i][1]=r[i-1][1]+s[i-2][1];
		s[i][0]=s[i-1][0]+s[i-2][0];
		s[i][1]=s[i-1][1]+s[i-2][1];
		
	}
	int a,n,m,x,b;
	scanf("%d%d%d%d",&a,&n,&m,&x);
	//r[n-1][0]*a+r[n-1][1]*b=m
	b=(m-r[n-1][0]*a)/r[n-1][1];
	printf("%d",r[x][0]*a+r[x][1]*b);
	return 0;
} 
