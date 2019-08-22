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
#define MAX 3011
int a[MAX];
int b[MAX];
char c;
int a_n=0,b_n=0,A,B;
int table[4][4];
#define  d(x,y) table[x][y]
#define  g(k) (-A-B*(k-1))
int main()
{
 	freopen("’“∞÷∞÷.in","r",stdin);
// 	freopen("’“∞÷∞÷.out","w",stdout);
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='\n')
			break;
		switch (c)
		{
			case 'A':
				a[a_n]=0;
				break;
			case 'T':
				a[a_n]=1;
				break;
			case 'G':
				a[a_n]=2;
				break;
			case 'C':
				a[a_n]=3;
				break;
		}
		a_n++;
	}
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='\n')
			break;
		switch (c)
		{
			case 'A':
				b[b_n]=0;
				break;
			case 'T':
				b[b_n]=1;
				break;
			case 'G':
				b[b_n]=2;
				break;
			case 'C':
				b[b_n]=3;
				break;
		}
		b_n++;
	}
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			scanf("%d",&table[i][j]);
	scanf("%d%d",&A,&B);
	if(b_n==1&&a_n==1)
		printf("%d",d(a[0],b[0]));
	

 	return 0;
}

