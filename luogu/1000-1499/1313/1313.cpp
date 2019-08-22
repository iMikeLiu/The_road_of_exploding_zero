#include<iostream>
#include<cstdio>
using namespace std;

int a,b,k,n,m;
long long ans;
#define ha 10007

long long pow(long long dishu,long long zhishu)
{
	if (zhishu == 0) 
		return 1;
	long long re = pow(dishu,zhishu/2);
	re = (long long)re*re%ha;
	if (zhishu%2 == 1) 
		re = (long long)re*dishu%ha;
	return re;
}
long long jiecheng(long long from,long long to)
{
	long long ans=1;
	for(long long i=from;i<=to;i++)
		ans=i*ans%ha;
	return ans;
}
int main()
{
//	freopen("1313.in","r",stdin);
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	
	//ans=pow(2,10);
	long long c,d;
	
	c=jiecheng(1,n);
	d=jiecheng(k-n+1,k);
	
	d=d*pow(c,ha-2)%ha;
	d=d*pow(a,n)*pow(b,m)%ha;
	printf("%lld",d);
	
	return 0;
}

