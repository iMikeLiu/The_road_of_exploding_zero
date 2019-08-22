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
char dat[100000];
int n,k;
bool a[10]={1,0,1,1,0,1,1,1,1,1};//上 
bool b[10]={1,0,0,0,1,1,1,0,1,1};//上左 
bool c[10]={1,1,1,1,1,0,0,1,1,1};//上右 
bool d[10]={0,0,1,1,1,1,1,0,1,1};//中 
bool e[10]={1,0,1,0,0,0,1,0,1,0};//下左 
bool f[10]={1,1,0,1,1,1,1,1,1,1};//下右 
bool g[10]={1,0,1,1,0,1,1,0,1,1};//下  


int main()
{
 	freopen("1536.in","r",stdin);
 	freopen("my1536.out","w",stdout);
	scanf("%d%s",&k,dat);
	n=strlen(dat);
	int x=3+2*k;
	for(int j=0;j<n;j++)
	{
		putchar(' ');
		char c=' ';
		if(a[(int)(dat[j]-'0')])
			c='-';
		for(int i=0;i<k;i++)
			putchar(c);
		putchar(' ');putchar(' ');
	}
	putchar('\n');
	for(int z=0;z<k;z++)
	{
		for(int j=0;j<n;j++)
		{
			if(b[(int)(dat[j]-'0')])
				putchar('|');
			else
				putchar(' ');
			for(int i=0;i<k;i++)
				putchar(' ');
			if(c[(int)(dat[j]-'0')])
				putchar('|');
			else
				putchar(' ');
			putchar(' ');
		}
		putchar('\n');
	} 
	for(int j=0;j<n;j++)
	{
		putchar(' ');
		char c=' ';
		if(d[(int)(dat[j]-'0')])
			c='-';
		for(int i=0;i<k;i++)
			putchar(c);
		putchar(' ');putchar(' ');
	}
	putchar('\n');
	for(int z=0;z<k;z++)
	{
		for(int j=0;j<n;j++)
		{
			if(e[(int)(dat[j]-'0')])
				putchar('|');
			else
				putchar(' ');
			for(int i=0;i<k;i++)
				putchar(' ');
			if(f[(int)(dat[j]-'0')])
				putchar('|');
			else
				putchar(' ');
			putchar(' ');
		}
		putchar('\n');
	} 
	for(int j=0;j<n;j++)
	{
		putchar(' ');
		char c=' ';
		if(g[(int)(dat[j]-'0')])
			c='-';
		for(int i=0;i<k;i++)
			putchar(c);
		putchar(' ');putchar(' ');
	}
 	return 0;
}

