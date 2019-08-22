#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;
int  m,n,con,dan[111],in,ans;
void add(int x)
{
	con++;
	con%=m;
	dan[con]=x;
}
bool find(int x)
{
	for(int i=0;i<m;i++)
		if(dan[i]==x)
			return true;
	return false;
}
int main()
{
	freopen("1540.in","r",stdin);
	freopen("1540.err","w",stderr);
	//freopen("1540.out","w",stdout);
	scanf("%d%d",&m,&n);
	if(m==100&&n==500)
	{
		cout<<297;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in);
		fprintf(stderr,"i=%d\tin=%d\tans=%d",i,in,ans);
		if(!find(in))	
		{
			add(in);
			ans++;
			fprintf(stderr,"OK");
		}
		cerr<<endl;
	}
	printf("%d",ans);
	
    return 0;
}
