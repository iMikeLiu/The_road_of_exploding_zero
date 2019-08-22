#include<iostream>
#include<cstdio>
using namespace std;
int a[10],b,ans=0;
int main ()
{
	freopen("1424.in","r",stdin);
	cin>>a[0];
	cin>>a[1];
	cin>>a[2];
	cin>>a[3];
	cin>>a[4];
	cin>>a[5];
	cin>>a[6];
	cin>>a[7];
	cin>>a[8];
	cin>>a[9];
	cin>>b;
	b=b+30;
	if(a[0]<=b)ans++;
	if(a[1]<=b)ans++;
	if(a[2]<=b)ans++;
	if(a[3]<=b)ans++;
	if(a[4]<=b)ans++;
	if(a[5]<=b)ans++;
	if(a[6]<=b)ans++;
	if(a[7]<=b)ans++;
	if(a[8]<=b)ans++;
	if(a[9]<=b)ans++;
	cout<<ans;
}
