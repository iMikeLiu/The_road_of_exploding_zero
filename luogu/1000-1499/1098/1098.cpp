#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
using namespace std;
int p1,p2,p3;
char in,in2;
bool check(char in)
{
	return  (in>='a'&&in<='z');//判断是不是字母 
}

bool flag=false;
int main()
{
 	freopen("1098.in","r",stdin);
// 	freopen("1098.out","w",stdout);
	scanf("%d%d%d\n",&p1,&p2,&p3);
	scanf("%c",&in);//先读入一个方便处理 
	while(scanf("%c",&in2)==1)//循环读入 
	{
		start:
		if(in2!='-')//连续的 
		{
			printf("%c",in);//直接输出 
			in=in2;//向前移位 
		}
		else//不连续的 
		{
			char in3;
			scanf("%c",&in3);//再读一个方便处理 
			if(in=='-')//特判 ，用于文章第一个是减号 
			{
				printf("%c%c%c",in,in2,in3);
			}
			else
			if(in3-in==1)//如果差是1，显然不输出-号 
			{
				if(flag==false)//flag往下看 
					printf("%c%c",in,in3);	
				else
					printf("%c",in3);		
			}
			else//不是1 
			if(check(in)==check(in3)&&in3<=in)//同一类型后比前大，输出全不 
			{
				if(flag==false)
					printf("%c%c%c",in,in2,in3);
				else
					printf("%c%c",in2,in3);
			}
			else
			if(check(in)!=check(in3))//不相等，直接输出 
			{
				if(flag==false)
					printf("%c%c%c",in,in2,in3);
				else
					printf("%c%c",in2,in3);
			}
			else//类型相同，开始乱搞 
			if(p3==1)//原来顺序 
			{
				if(p1==1)//所有递增 
				{
					printf("%c",in);
					for(char a=in+1;a<=in3-1;a++)
						for(int i=0;i<p2;i++)
							printf("%c",a);	
					printf("%c",in3);
				}
				if(p1==2)//大写字母 
				{
					if(in>='a'&&in2<='z')//字母 
					{
						printf("%c",in);//两头小写 
						for(char a=in-'a'+'A'+1;a<=in3-'a'+'A'-1;a++)//中间大写 
							for(int i=0;i<p2;i++)
								printf("%c",a);
						printf("%c",in3);//两头小写 
					}
					else//数字 
					{
						printf("%c",in3);
						for(char a=in+1;a<=in3-1;a++)
							for(int i=0;i<p2;i++)
								printf("%c",a);
						printf("%c",in);		
					}	
				}
				if(p1==3)//*号 
				{
					if(flag==false)
						printf("%c",in);
					for(char a=in+1;a<=in3-1;a++)
						for(int i=0;i<p2;i++)
							printf("*");
					printf("%c",in3);	
				}
			}
			else//倒叙，基本同上 
			{
				if(p1==1)
				{
					printf("%c",in);
					for(char a=in3-1;a>=in+1;a--)
						for(int i=0;i<p2;i++)
							printf("%c",a);	
					printf("%c",in3);
				}
				if(p1==2)
				{
					if(in>='a'&&in2<='z')
					{
						if(flag==false)
							printf("%c",in);
						for(char a=in3-'a'+'A'-1;a>=in-'a'+'A'+1;a--)
							for(int i=0;i<p2;i++)
								printf("%c",a);
						printf("%c",in3);
					}
					else
					{
//						printf("%c",in);
						for(char a=in3-1;a>=in+1;a--)
							for(int i=0;i<p2;i++)
								printf("%c",a);
						printf("%c",in3);		
					}	
				}
				if(p1==3)
				{
					printf("%c",in);
					for(char a=in3-1;a>=in+1;a--)
						for(int i=0;i<p2;i++)
							printf("*");
					printf("%c",in3);	
				}
			}
			//7号数据结尾-号特判 
			if(scanf("%c",&in2)!=1)
				return 0;
			flag=false;//清flag 
			if(in2=='-')//又是-号 
			{
				in=in3;//前移 
				flag=true;
				goto start;//跳转 不读入，需要注意，若满足这种情况，则前一个字符已经输出了，所以做标记，不用再输出了 
			}
			else//正常前移 
			{
				in =in2;//正常结束重新读in2 
			}
			
		}
		
	}
 	return 0;
}

