#include<cstdio>
#include<iostream>
using namespace std;
int a,b,c,d;
int main()
{
	//freopen("1425.in","r",stdin);
	cin>>a>>b>>c>>d;
	if(d<b)
		cout<<c-1-a<<" "<<d+60-b;
	else
		cout<<c-a<<" "<<d-b;
} 
