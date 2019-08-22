#include<cstdio>
using namespace std;
int x,y;
int gcd(int a,int b,int &x,int &y)
{
    if(!b)
	{
		y=0;
        x=1;
        return a;
    }
    int ans=gcd(b,a%b,x,y);
    int c=x;
    x=y;
    y=c-a/b*y;
    return ans;
} 
int a,b;
int main()
{
	freopen("1082.in","r",stdin);
    scanf("%d%d",&a,&b);
    gcd(a,b,x,y);
    printf("%d",(x+b)%b);
}
