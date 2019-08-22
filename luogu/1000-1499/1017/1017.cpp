#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;
int n,r;
void chenge(int x)
{
	int j=x%r;
	x/=r;
	if(j<0)
    {
        j-=r;
        x++;
    }
	if(x!=0)
		chenge(x);
	if(j>9)
		printf("%c",j-10+'A');
	else
		printf("%d",j);
}
int main()
{
	freopen("1017.in","r",stdin);
//	freopen("1017.out","w",stdout);
	scanf("%d%d",&n,&r);
	printf("%d=",n);
//	r=-r;
	chenge(n);
	printf("(base%d)",r);
    return 0;
}
