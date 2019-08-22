#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#include<time.h>
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
#define MAXN 2000
struct hole
{
	int x,y,w;
};
hole data[MAXN];
int n;
double getenergy(double x,double y)
{
	double sum=0;
	for(int i=0;i<n;i++)
	{
		double delx=x-data[i].x;
		double dely=y-data[i].y;
		sum+=sqrt(delx*delx+dely*dely)*data[i].w;
	}
	return sum;
}
double ansx,ansy;
double ans=1e18+7,t;//势能与温度
const double delta=0.998;//降温系数
const double eps=1e-15;
void solve()
{
    t=200;//t是温度
    while(t>eps)
    {
        double nowx=ansx+(rand()*2-RAND_MAX)*t;
        double nowy=ansy+(rand()*2-RAND_MAX)*t;
		double DE=getenergy(nowx,nowy)-getenergy(ansx,ansy);
		if(DE<0)//如果是一个更优解
			ansx=nowx,ansy=nowy;
		else if(exp(-DE/t)*RAND_MAX>rand())//能否接受这个差 
			ansx=nowx,ansy=nowy;
		t*=delta;//降温 
    }
}
int main()
{
 	freopen("1337.in","r",stdin);
// 	freopen("1337.out","w",stdout);
	n=read();
	srand(19260817);
	for(R int i=0;i<n;i++)
		data[i].x=read(),data[i].y=read(),data[i].w=read(),ansx+=data[i].x,ansy+=data[i].y;
	ansx/=(double)n;
	ansy/=(double)n;
	solve();
	printf("%.3lf %.3lf",ansx,ansy);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
