#include<iostream>
#include<cstdio>
using namespace std;
int data[100],in,ans=0;
int  main()
{
	freopen("1427.in","r",stdin);
	for(cin>>in;in!=0;ans++)
	{
		data[ans]=in;
		cin>>in;
	}
	for(ans--;ans>=0;ans--)
	{
		cout<<data[ans]<<" ";
	}
} 
