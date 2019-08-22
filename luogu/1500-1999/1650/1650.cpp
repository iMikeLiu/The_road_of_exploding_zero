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
#define MAXN 1000011
int a[MAXN],b[MAXN];
bool cmp(int a,int b){return a>b;}
int main()
{
 	freopen("1650.in","r",stdin);
// 	freopen("1650.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	sort(a,a+n,cmp);
	sort(b,b+n,cmp);
  	int win = 0;
  	int fail = 0;
  	int draw = 0;
  	int ib = 0, jb = 0;//ºÃÂí 
  	int ie = n - 1, je = n - 1;//²îÂí 
	while ( ib <= ie )
	{
   		if (a[ie] > b[je])
   		{
			win++;
	        ie--;
	        je--;
   		}
		else 
		{
			if (a[ie] < b[je])
   			{
      			fail++;
      			ie--;
      			jb++;
   			}
			else
   			{
    			if (a[ib] > b[jb])
    			{
       				win++;
       				ib++;
       				jb++;
    			}
				else
    			{
     				if (a[ie] < b[jb])
				        fail++;
				    ie--;
				    jb++;
    			}
   			}
   		}
	}
	printf("%d",(win-fail)*200);
 	return 0;
}

