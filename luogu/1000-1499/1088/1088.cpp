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
int a[10005],n,m;


int main()
{
 	freopen("1088.in","r",stdin);
// 	freopen("1088.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
    while(m--)    
		next_permutation(a,a+n);
    for(int i=0;i<n-1;i++)    
		printf("%d ",a[i]);    
	printf("%d",a[n-1]);
    return 0;
}

