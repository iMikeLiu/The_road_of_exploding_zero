#include<cstdio>
#include<iostream>
using namespace std;
float out;
int in;
int main()
{
	freopen("1422.in","r",stdin);
	cin>>in;
	if(in<=150)
	{
		out=in*0.4463;
	}
	else
	{
		if(in<=400)
		{
			out=150*0.4463+(in-150)*0.4663;
		}
		else
		{
			out=150*0.4463+(400-150)*0.4663+(in-400)*0.5663;
		}
	}
	printf("%0.1f",out);
} 
