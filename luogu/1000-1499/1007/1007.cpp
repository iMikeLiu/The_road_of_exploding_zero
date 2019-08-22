#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int l,n; 
int s,maxn,minn;
int main()
{
	scanf("%d%d",&l,&n);
	if(n==0)
	{
		cout<<"0 0";
		return 0;
	}
	for(int a=0;a<n;a++)
	{
		scanf("%d",&s);
		maxn+=max(0,max(s,l-s+1)-maxn);
        minn+=max(0,min(s,l-s+1)-minn);
	}
	cout<<minn<<" "<<maxn;
	return 0;
	
}
