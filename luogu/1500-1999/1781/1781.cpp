#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
using namespace std;
int n,Max_=-1;
string a,max_="0";//max_存储最大票数，初始值为0
int main()
{
 	freopen("1781.in","r",stdin);
 //	freopen("1781.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>a;//读入票数
        if(a.length()>max_.length())
		{
			max_=a;
			Max_=i;
		}//先比较位数
        if((a.length()==max_.length())&&(a>max_))
		{
			max_=a;
			Max_=i;
		}//如果位数一样，则直接比较大小
    }
    cout<<Max_+1<<endl<<max_;//输出...要换行哦^_^



 	return 0;
}

