#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,ans=0;
int find(int x)//数字与根数对应关系 
{
	switch(x)
	{
		case 0:
			return 6;
		case 1:
			return 2;
		case 2:
			return 5;
		case 3:
			return 5;
		case 4:
			return 4;
		case 5:
			return 5;
		case 6:
			return 6;
		case 7:
			return 3;
		case 8:
			return 7;
		case 9:
			return 6;
		default:
			return find(x/10)+find(x%10);	
	}
}


int main()
{
 	freopen("1149.in","r",stdin);
// 	freopen("1149.out","w",stdout);
	scanf("%d",&n);
	n-=4;//拼等号和加号
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(find(i)+find(j)+find(i+j)==n)
			{
				if(i!=j)
					ans+=2;
				else
					ans++;
			}
		}
	}
	printf("%d",ans);
	



 	return 0;
}

