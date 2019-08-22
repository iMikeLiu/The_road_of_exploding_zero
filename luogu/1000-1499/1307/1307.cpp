#include <iostream>
#include <cstring>
using namespace std;
char a[10000000000];
int b=0;
int y=0;
int main()
{
	//freopen("1307.in","r",stdin);
	cin>>a;
	if(a[b]=='-')
	{	
		cout<<"-";
		b++;
	}
	for(long long int c=strlen(a)-1;c>=b;c--)
	{
		if(a[c]!='0'||y==1)
		{
			cout<<a[c];
			y=1;
		}
		
	}
}
