#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN 222
int n,F[MAXN][MAXN],in[MAXN];//Fij表示从i-j最大能量 
int ans=0; 
int main()
{
 	freopen("1063.in","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		in[i+n]=in[i];
	}
//for(int i=1;i<=n;i++)
//	printf("%d %d\n",in[i].tou,in[i].wei);
	for(int i=0;i<2*n;i++)
	{ 
		for(int l=0;l<2*n-i;l++)
		{
			int r=l+i;//这里是区间的右端点  
          	for (int k=l;k<r;k++)//枚举区间断点 注意l<=k<r 
            	F[l][r]=max(F[l][r],F[l][k]+F[k+1][r]+in[l]*in[(k+1)]*in[(r+1)]);
		} 
	}
	for (int i=0;i<=n;i++)//DP完成后从前往后搜一遍答案 
      ans=max(ans,F[i][i+n-1]);
    printf("%d",ans);

 	return 0;
}
