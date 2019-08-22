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
#include <functional>
using namespace std;
int dat[10000000];
int n,size,op,x;


int main()
{
 	freopen("3378.in","r",stdin);
// 	freopen("3378.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&dat[size++]);
			push_heap(dat,dat+size,greater<int>());
		}
		if(op==2)
		{
			printf("%d\n",dat[0]);
		}
		if(op==3)
		{
			pop_heap(dat,dat+size,greater<int>());
			size--;
		}
	}
 	return 0;
}

