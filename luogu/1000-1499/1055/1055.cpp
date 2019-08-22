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
int a[11];


int main()
{
    freopen("1055.in","r",stdin);
    freopen("1055.out","w",stdout);
	for(int i=0;i<10;i++)
	{
		char c=getchar();
		if(c>='0'&&c<='9')
			a[i]=c-'0';
		else if(c=='X')
			a[i]=10;
		else
			i--;
	}
//	for(int i=0;i<10;i++)printf("%d ",a[i]);
	int check=0;
	for(int i=0;i<9;i++)
		check+=a[i]*(i+1);
	check%=11;//check=check%11;
	if(a[9]==check)
		printf("Right");
	else
		if(check==10)
			printf("%d-%d%d%d-%d%d%d%d%d-X",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);	
	else
		printf("%d-%d%d%d-%d%d%d%d%d-%d",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],check);
	


    return 0;
}

