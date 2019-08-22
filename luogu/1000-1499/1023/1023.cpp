#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
using namespace std;
int x,a[10][2],dy,bt,ans=2000000000,i,j,n,maxlr,maxlrjg,t;
int zlr(int xl,int jg,int bt)
{
	return (jg-**a+bt)*xl;
}


int main()
{
 	freopen("1023.in","r",stdin);
// 	freopen("1023.out","w",stdout);
    scanf("%d",&x);
	scanf("%d%d",&a[n][0],&a[n][1]);
	while(a[n][0]+1||a[n][1]+1)
		n++,scanf("%d%d",&a[n][0],&a[n][1]);
    scanf("%d",&dy);
    for(bt=-32;bt<=9;bt++,maxlr=maxlrjg=i=0)
	{
        for(;i<n-1;i++)
            for(j=*a[i];j<*a[i+1];j++)
                if((t=zlr(a[i][1]+(a[i+1][1]-a[i][1])/(*a[i+1]-*a[i])*(j-*a[i]),j,bt))>=maxlr)
                    maxlr=t,maxlrjg=j;
        for(i=a[n-1][1];i>0;j++,i-=dy)
            if((t=zlr(i,j,bt))>=maxlr)
                maxlr=t,maxlrjg=j;
        if(maxlrjg==x&&abs(bt)<abs(ans))
			ans=bt;
	}
    if(ans-2000000000)
		cout<<ans;
    else 
		cout<<"NO SOLUTION";
	


 	return 0;
}

