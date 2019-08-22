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
int a[1000000],ans;
int main()
{
 	freopen("1094.in","r",stdin);
// 	freopen("1094.out","w",stdout);
    int n,w;
    scanf("%d%d",&w,&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int z=0,y=n-1;
    while(z<=y)
        if(a[z]+a[y]<=w)
			ans++,z++,y--;
        else 
			y--,ans++;
    printf("%d",ans);


 	return 0;
}

