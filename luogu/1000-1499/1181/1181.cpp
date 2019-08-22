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
int main()
{
 	freopen("1181.in","r",stdin);
// 	freopen("1181.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int now=0,ans=1; 
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if(a+now>m)
			now=a,ans++;
		else
			now+=a;	
	}
	printf("%d",ans);


 	return 0;
}

