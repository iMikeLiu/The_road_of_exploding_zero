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
long long  a,b,c;


int main()
{
 	freopen("1634.in","r",stdin);
// 	freopen("1634.out","w",stdout);
	cin>>a>>b;
	a++;
	c=1;
	for(long long i=0;i<b;i++)
		c*=a;
	cout<<c;
 	return 0;
}
