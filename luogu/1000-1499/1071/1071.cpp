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
char buf[10000]; 
char know[10000];
char password[32];
int longs,a;
int countn[26],maxn;


int main()
{
     freopen("1071.in","r",stdin);
//    freopen("1071.out","w",stdout);
    scanf("%s%s",buf,know);
    for(int i=0;buf[i]!=0;i++)
    {
        if(password[buf[i]-'A']==0)
            a++;
        if(password[buf[i]-'A']!=0&&password[buf[i]-'A']!=know[i]&&password[know[i]-'A']!=buf[i])
        {
            printf("Failed");
            return 0;
        }
        else
            password[buf[i]-'A']=know[i];        
    }
    if(a!=26)
    {
        printf("Failed");
        return 0;
    }
    for(int i=0;i<a;i++)
    	maxn=max(maxn,++countn[password[i]-'A']);
    if(maxn>1)
    {
        printf("Failed");
        return 0;
    }
    scanf("%s",buf);
    for(int i=0;buf[i]!=0;i++)
        printf("%c",password[buf[i]-'A']);
     return 0;
}

