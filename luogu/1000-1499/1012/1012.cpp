#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<map>
using namespace std;
int n;
string dat[21];
bool cmp(string a,string b)
{
	return a+b>b+a;
}
int main()
{
 	freopen("1012.in","r",stdin);
// 	freopen("1012.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		cin>>dat[i];
	sort(dat,dat+n,cmp);
	for(int i=0;i<n;i++)
		cout<<dat[i];
 	return 0;
}

