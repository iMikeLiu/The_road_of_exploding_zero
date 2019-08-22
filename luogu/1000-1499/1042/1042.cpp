#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
using namespace std;
int a11=0,b11=0,a21=0,b21=0;
char c,s[100000]; //第一个坑点，这题读入的字符串贼大。
void work1() //第一次处理：边读边做，算11进制
{
     int t=0;
     while(true)
     {
        if(c=='W'||c=='L') 
        {
        s[t]=c; t++; //将每一个“W”或“L”放入字符数组中
      }
      if(c=='E') break;
      if(c=='W') a11++;
      if(c=='L') b11++; 
      if((a11>=11||b11>=11)&&(abs(a11-b11)>=2))
      {
        printf("%d:%d\n",a11,b11);
        a11=0; b11=0;
      }
      scanf("%c",&c); //简单模拟，不解释
    }
     printf("%d:%d\n\n",a11,b11); //第二个坑点，不管最后是不是0：0都要输出
}
void work2() //第二次处理：利用字符数组计算21进制
{
     for(int i=0; i<strlen(s); i++)
    {
      if(s[i]=='W') a21++;
      if(s[i]=='L') b21++;
      if((a21>=21||b21>=21)&&(abs(a21-b21)>=2))
      {
        printf("%d:%d\n",a21,b21);
        a21=0; b21=0;
      }
    }
    if(!(a21==0&&b21==0)) printf("%d:%d\n",a21,b21); //此处同上，不解释
}
int main()
{
 	freopen("1042.in","r",stdin);
// 	freopen("1042.out","w",stdout);
	scanf("%c",&c); 
	if(c=='E') //特判，不然第一个数据一上来就是个E就傻了。。
	{
		printf("0:0\n\n");
        printf("0:0\n");
        return 0;
	}
	work1(); //计算11进制
	work2(); //计算21进制
	return 0;
}

