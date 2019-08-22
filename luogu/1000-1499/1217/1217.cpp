#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
using namespace std;
int a,b;
//产生8位回文数 4个循环 
bool check(int x)
{
	int a=sqrt(x);
	for(int i=2;i<=a;i++)
		if(x%i==0)
			return false;
	return true;
} 
namespace one
{
	void run(int start,int stop)
	{
		for(int i=start;i<=9&&i<=stop;i++)
			if(check(i))
				printf("%d\n",i);
	}
}
namespace two
{
	int ans;
	void run(int start,int stop)
	{
		for(int i=1;i<=9;i++)
		{
			ans=i*10+i;
			if(ans<start)
				continue;
			if(ans>stop)
				return;
			if(check(ans))
				printf("%d\n",ans);
		}
	}	
}
namespace three
{
	int ans;
	void run(int start,int stop)
	{
		for(int i=1;i<=9;i+=2)
			for(int j=0;j<=9;j++)
			{
				ans=i*100+j*10+i;
				if(ans<start)
					continue;
				if(ans>stop)
					return;
				if(check(ans))
					printf("%d\n",ans);
			}
	}	
}
namespace four
{
	int ans;
	void run(int start,int stop)
	{
		for(int i=1;i<=9;i+=2)
			for(int j=0;j<=9;j++)
			{
				ans=i*1000+j*100+j*10+i;
				if(ans<start)
					continue;
				if(ans>stop)
					return;
				if(check(ans))
					printf("%d\n",ans);
			}
	}	
}
namespace five
{
	int ans;
	void run(int start,int stop)
	{
		for(int i=1;i<=9;i+=2)
			for(int j=0;j<=9;j++)
				for(int k=0;k<=9;k++)
				{
					ans=i*10000+j*1000+k*100+j*10+i;
					if(ans<start)
						continue;
					if(ans>stop)
						return;
					if(check(ans))
						printf("%d\n",ans);
				}
	}	
}
namespace six
{
	int ans;
	void run(int start,int stop)
	{
		for(int i=1;i<=9;i+=2)
			for(int j=0;j<=9;j++)
				for(int k=0;k<=9;k++)
				{
					ans=i*100000+j*10000+k*1000+k*100+j*10+i;
					if(ans<start)
						continue;
					if(ans>stop)
						return;
					if(check(ans))
						printf("%d\n",ans);
				}
	}	
}
namespace seven
{
	int ans;
	void run(int start,int stop)
	{
		for(int i=1;i<=9;i+=2)
			for(int j=0;j<=9;j++)
				for(int k=0;k<=9;k++)
					for(int l=0;l<=9;l++)
					{
						ans=i*1000000+j*100000+k*10000+l*1000+k*100+j*10+i;
						if(ans<start)
							continue;
						if(ans>stop)
							return;
						if(check(ans))
							printf("%d\n",ans);
					}
	}	
}
namespace eight
{
	int ans;
	void run(int start,int stop)
	{
		for(int i=1;i<=9;i+=2)
			for(int j=0;j<=9;j++)
				for(int k=0;k<=9;k++)
					for(int l=0;l<=9;l++)
					{
						ans=i*10000000+j*1000000+k*100000+l*10000+l*1000+k*100+j*10+i;
						if(ans<start)
							continue;
						if(ans>stop)
							return;
						if(check(ans))
							printf("%d\n",ans);
					}
	}	
}
int main()
{
 	freopen("1217.in","r",stdin);
// 	freopen("1217.out","w",stdout);
	scanf("%d%d",&a,&b);
	one::run(a,b);
	two::run(a,b);
	three::run(a,b);
	four::run(a,b);
	five::run(a,b);
	six::run(a,b);
	seven::run(a,b);
	eight::run(a,b);


 	return 0;
}

