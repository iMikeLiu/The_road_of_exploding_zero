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
const int N = 1000100;
void get_next(char s[],int next[])    //找next数组
{
    int len=strlen(s+1);    //确保调用s中的元素的时候是从s[1]开始而不是s[0]，因为next数组从1开头 
    for (int i=2,j=0;i<=len;i++) 
	{
        while (j && s[i]!=s[j+1]) 
			j=next[j];    //就是移动过程 
        if (s[i]==s[j+1]) 
			j++;    //如果匹配就继续
        next[i]=j;    //表明第i位的next[i]的值是j 
    }
} 
int kmp(char s[],char t[],int next[],int addr[])    //在s中找t
{
    int lens=strlen(s+1),lent=strlen(t+1),ans=0;    //同上 
    for (int i=1,j=0;i<=lens;i++) 
	{       
         while (j && s[i]!=t[j+1]) 
		 	j=next[j]; 
         if (s[i]==t[j+1]) 
		 	j++;        
         if (j==lent) 
			addr[ans++]=i-lent+1;        
    } 
    return ans;
} 
char a[N],b[N];
int c[N],d[N];


int main()
{
 	freopen("3375.in","r",stdin);
//	freopen("3375.out","w",stdout);
	cin>>a+1>>b+1;
	int aaaa=strlen(b+1);
	get_next(b,c);
	int ans=kmp(a,b,c,d);
	for(int i=0;i<ans;i++)
	  	printf("%d\n",d[i]);
	for(int i=1;i<=aaaa;i++)
		printf("%d ",c[i]);


 	return 0;
}

