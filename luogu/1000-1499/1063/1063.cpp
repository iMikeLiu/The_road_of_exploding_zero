#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN 222
int n,F[MAXN][MAXN],in[MAXN];//Fij��ʾ��i-j������� 
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
			int r=l+i;//������������Ҷ˵�  
          	for (int k=l;k<r;k++)//ö������ϵ� ע��l<=k<r 
            	F[l][r]=max(F[l][r],F[l][k]+F[k+1][r]+in[l]*in[(k+1)]*in[(r+1)]);
		} 
	}
	for (int i=0;i<=n;i++)//DP��ɺ��ǰ������һ��� 
      ans=max(ans,F[i][i+n-1]);
    printf("%d",ans);

 	return 0;
}
