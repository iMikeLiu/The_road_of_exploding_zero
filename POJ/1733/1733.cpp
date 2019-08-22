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
#define MAXN 5011
struct node_
{
	int from,to;
	char s[10];
}data[MAXN];
int main()
{
    freopen("1733.in","r",stdin);
    freopen("1733.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d%s",data[i].from,data[i].to,data[i].s);
	

    return 0;
}

