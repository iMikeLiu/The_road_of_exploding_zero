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
int ans[14],check[3][28]={0},sum=0,n;
void dfs(int line)
{
    if(line>n)
    {
        sum++;
        if(sum>3) 
			return;
        else
        {
            for(int i=1;i<=n;i++) 
				printf("%d ",ans[i]);
            printf("\n");
            return;
        }
    }
    for(int i=1;i<=n;i++)
    {
    	if((check[0][i]==0)&&(check[1][line+i]==0)&&(check[2][line-i+n+2]==0))
    	{
    		ans[line]=i;
	    	check[0][i]=1;check[1][line+i]=1;check[2][line-i+n+2]=1;
	    	dfs(line+1);
	    	check[0][i]=0;check[1][line+i]=0;check[2][line-i+n+2]=0;
    	}
    }
}



int main()
{
 	freopen("1219.in","r",stdin);
// 	freopen("1219.out","w",stdout);
	scanf("%d",&n);
	dfs(1);
	cout<<sum;


 	return 0;
}

