#include<iostream>
#include<cstdio>
using namespace std;
char in[800];
long long count[30];
#define maxn(x,y) ((x)>(y))?(x):(y)
long long start=0;
int main()
{
	freopen("1598.in","r",stdin);
	for(int i=0;i<4;i++)
	{
		gets(in);
		for(int j=0;in[j]!=0;j++)
		{
			if(in[j]!=' ')
				count[in[j]-'A'+1]++;
			
		}
	}
	for(int i=1;i<=26;i++)
	{
//		printf("%d ",count[i]);
		start=maxn(start,count[i]);
	}
//	cout<<endl<<start<<endl;
	for(int i=start;i>0;i--)
	{
		for(int j=1;j<=26;j++)
		{
			if(count[j]>=i)
				printf("*");
			else
				printf(" ");
			if(j!=26)
				printf(" ");
		}
		printf("\n");
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
}
