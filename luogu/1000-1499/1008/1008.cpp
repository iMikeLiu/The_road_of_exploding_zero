#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,c,A[10];
	bool h;
	for(int i=100;i<=333;i++)
	{
		h=1;
		a=i;
		b=i*2;
		c=i*3;
		A[0]=a/100;//把a，b，c三个数各个位数分离存到判断数组里面
        A[1]=a%100/10;
        A[2]=a%10;
        A[3]=b/100;
        A[4]=b%100/10;
        A[5]=b%10;
        A[6]=c/100;
        A[7]=c%100/10;
        A[8]=c%10;
        for(int m=0;m<9;m++)
        {
        	for(int n=0;n<9;n++)
        	{
        		if((m!=n&&A[m]==A[n])||A[m]==0)
        		{
        			h=0;
        		}
        	}
        }
		if(h==1)
		{
			cout<<a<<" "<<b<<" "<<c<<endl;
		}
	}
	return 0;	
} 
