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
char c,s[100000]; //��һ���ӵ㣬���������ַ�������
void work1() //��һ�δ����߶���������11����
{
     int t=0;
     while(true)
     {
        if(c=='W'||c=='L') 
        {
        s[t]=c; t++; //��ÿһ����W����L�������ַ�������
      }
      if(c=='E') break;
      if(c=='W') a11++;
      if(c=='L') b11++; 
      if((a11>=11||b11>=11)&&(abs(a11-b11)>=2))
      {
        printf("%d:%d\n",a11,b11);
        a11=0; b11=0;
      }
      scanf("%c",&c); //��ģ�⣬������
    }
     printf("%d:%d\n\n",a11,b11); //�ڶ����ӵ㣬��������ǲ���0��0��Ҫ���
}
void work2() //�ڶ��δ��������ַ��������21����
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
    if(!(a21==0&&b21==0)) printf("%d:%d\n",a21,b21); //�˴�ͬ�ϣ�������
}
int main()
{
 	freopen("1042.in","r",stdin);
// 	freopen("1042.out","w",stdout);
	scanf("%c",&c); 
	if(c=='E') //���У���Ȼ��һ������һ�������Ǹ�E��ɵ�ˡ���
	{
		printf("0:0\n\n");
        printf("0:0\n");
        return 0;
	}
	work1(); //����11����
	work2(); //����21����
	return 0;
}

