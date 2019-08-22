#include<iostream>
#include <cstdio>
using namespace std;
int n;
int data[4][10000];
int x,y;
int ditan[2][100000];
int main()
{
	scanf("%d",&n);
	for(int a=0;a<n;a++)
	{
		scanf("%d%d%d%d",&data[0][a],&data[1][a],&data[2][a],&data[3][a]);
	}
	cin>>x>>y;
	for(int a=n;a>=0;a--)
	{
		if(x>=data[0][a]&&x<=data[2][a]+data[0][a]&&y>=data[1][a]&&y<=data[3][a]+data[1][a])
		{
			cout<<a+1;
			return 0;
		}
	}
	cout<<"-1";
	return 0;
} 
