#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;
int n;
int dat[100011];
int main()
{
    freopen("1177.in","r",stdin);
 //   freopen("1177.out","w",stdout);
 	scanf("%d",&n);
 	for(int i=0;i<n;i++)
 		scanf("%d",&dat[i]);
 	sort(dat,dat+n);
 	for(int i=0;i<n;i++)
 		printf("%d ",dat[i]);

    return 0;
}
