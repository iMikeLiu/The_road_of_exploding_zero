#include<iostream>
#include<cstdio>
using namespace std; 
bool tree[10000000]={0};
int ans=0,linshi,linshi1,linshi2;
int main ()
{
	freopen("1047.in","r",stdin);
	cin>>linshi;
	for(int a=0;a<=linshi;a++)
	{
		tree[a]=1;//ÖÖÊ÷ 
	}
	cin>>linshi;
	for(int a=0;a<linshi;a++)
	{
		cin>>linshi1>>linshi2;
		for(int b=linshi1;b<=linshi2;b++)
		{
			tree[b]=0;//·¥Ä¾ 
		}
	}
	for(int a=0;a<10000000;a++)
	{
		if(tree[a]==1)
		{
			ans++;
		}
	}
	cout<<ans;
}
