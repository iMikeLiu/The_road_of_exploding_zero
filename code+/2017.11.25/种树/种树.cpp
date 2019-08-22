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
#define MAXN 200011
using namespace std;
int n,s,l;
int h[MAXN],a[MAXN];
int tree;
int data[MAXN];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
 	freopen("ÖÖÊ÷.in","r",stdin);
// 	freopen("ÖÖÊ÷.out","w",stdout);
	scanf("%d%d%d",&n,&s,&l);
	tree=ceil((double)s/l);
	//cout<<tree;
	for(int i=0;i<n;i++)
		scanf("%d",&h[i]),h[i]=l-h[i];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		data[i]=ceil((double)h[i]/a[i]);
	sort(data,data+n);
	printf("%d",data[tree-1]);
 	return 0;
}

