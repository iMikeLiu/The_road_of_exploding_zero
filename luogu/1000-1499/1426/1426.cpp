#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
using namespace std;
int s,x;
double mi,v=7;
int main()
{
	freopen("1426.in","r",stdin);
//	freopen("1426.out","w",stdout);
	scanf("%d%d",&s,&x);
	while(1)
	{
		if((mi>s-x)&&(mi<s+x))
		{
			v*=0.98;
			mi+=v;
			if((mi>s-x)&&(mi<s+x))
			{
				printf("y");
				return 0;
			}
			else
			{
				printf("n");
				return 0;
			}
		}
		mi+=v;
		v*=0.98;
		if(v==0)
		{
			printf("n");
			return 0;	
		}
		
		
	}

    return 0;
}

