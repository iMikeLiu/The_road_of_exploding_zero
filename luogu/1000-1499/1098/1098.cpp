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
	return  (in>='a'&&in<='z');//�ж��ǲ�����ĸ 
}

bool flag=false;
int main()
{
 	freopen("1098.in","r",stdin);
// 	freopen("1098.out","w",stdout);
	scanf("%d%d%d\n",&p1,&p2,&p3);
	scanf("%c",&in);//�ȶ���һ�����㴦�� 
	while(scanf("%c",&in2)==1)//ѭ������ 
	{
		start:
		if(in2!='-')//������ 
		{
			printf("%c",in);//ֱ����� 
			in=in2;//��ǰ��λ 
		}
		else//�������� 
		{
			char in3;
			scanf("%c",&in3);//�ٶ�һ�����㴦�� 
			if(in=='-')//���� ���������µ�һ���Ǽ��� 
			{
				printf("%c%c%c",in,in2,in3);
			}
			else
			if(in3-in==1)//�������1����Ȼ�����-�� 
			{
				if(flag==false)//flag���¿� 
					printf("%c%c",in,in3);	
				else
					printf("%c",in3);		
			}
			else//����1 
			if(check(in)==check(in3)&&in3<=in)//ͬһ���ͺ��ǰ�����ȫ�� 
			{
				if(flag==false)
					printf("%c%c%c",in,in2,in3);
				else
					printf("%c%c",in2,in3);
			}
			else
			if(check(in)!=check(in3))//����ȣ�ֱ����� 
			{
				if(flag==false)
					printf("%c%c%c",in,in2,in3);
				else
					printf("%c%c",in2,in3);
			}
			else//������ͬ����ʼ�Ҹ� 
			if(p3==1)//ԭ��˳�� 
			{
				if(p1==1)//���е��� 
				{
					printf("%c",in);
					for(char a=in+1;a<=in3-1;a++)
						for(int i=0;i<p2;i++)
							printf("%c",a);	
					printf("%c",in3);
				}
				if(p1==2)//��д��ĸ 
				{
					if(in>='a'&&in2<='z')//��ĸ 
					{
						printf("%c",in);//��ͷСд 
						for(char a=in-'a'+'A'+1;a<=in3-'a'+'A'-1;a++)//�м��д 
							for(int i=0;i<p2;i++)
								printf("%c",a);
						printf("%c",in3);//��ͷСд 
					}
					else//���� 
					{
						printf("%c",in3);
						for(char a=in+1;a<=in3-1;a++)
							for(int i=0;i<p2;i++)
								printf("%c",a);
						printf("%c",in);		
					}	
				}
				if(p1==3)//*�� 
				{
					if(flag==false)
						printf("%c",in);
					for(char a=in+1;a<=in3-1;a++)
						for(int i=0;i<p2;i++)
							printf("*");
					printf("%c",in3);	
				}
			}
			else//���𣬻���ͬ�� 
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
			//7�����ݽ�β-������ 
			if(scanf("%c",&in2)!=1)
				return 0;
			flag=false;//��flag 
			if(in2=='-')//����-�� 
			{
				in=in3;//ǰ�� 
				flag=true;
				goto start;//��ת �����룬��Ҫע�⣬�����������������ǰһ���ַ��Ѿ�����ˣ���������ǣ������������ 
			}
			else//����ǰ�� 
			{
				in =in2;//�����������¶�in2 
			}
			
		}
		
	}
 	return 0;
}

