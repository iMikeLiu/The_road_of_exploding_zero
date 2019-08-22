#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#include<ctime>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<(x)<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<(x)<<":"<<#y<<"="<<(y)<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define L long
#define LL long long
#define I inline
#define U unsigned
#define START clock_t __start=clock();
#define STOP fprintf(stderr,"\n\nUse Time:%fs\n",((double)(clock()-__start)/CLOCKS_PER_SEC));
using namespace std;
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
I char readc()
{
	char c;
	for (;((c=getchar())<'A'||c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9'););
	return c;
}
#define MAXN 44
int n,k,a[MAXN];
#define BIG_INT_LENGTH 44
struct bigint
{
	int size;
	int a[BIG_INT_LENGTH];
	bigint()
	{
		size=1;
		memset(a,0,sizeof(a));
	}
	bigint(int in)
	{
		size=0;
		do{a[size++]=in%10;in/=10;}while(in);
	}	
	bigint &operator=(int in)
	{
		size=0;
		do{a[size++]=in%10;in/=10;}while(in);
		return *this;
	}
};
bigint ans;
bool operator < (bigint a,bigint b)
{
	if (a.size<b.size)
		return true;
	if (a.size>b.size)
		return false;
	for(int i=a.size-1;i>=0;i--)
		if (a.a[i]<b.a[i])
			return true;
		else if(a.a[i]>b.a[i])
			return false;
    return false;
}
bigint operator*(bigint a,bigint b)
{
	bigint c;
	c.size=a.size+b.size-1;
	for(int i=0;i<a.size;i++)
		for(int j=0;j<b.size;c.a[i+j]+=a.a[i]*b.a[j],c.a[i+j+1]+=c.a[i+j]/10,c.a[i+j]%=10,j++);
	for(;c.a[c.size];c.a[c.size+1]=c.a[c.size]/10,c.a[c.size]%=10,c.size++);
	return c;
}
ostream & operator<<(ostream &out, bigint &a)
{
	for(int i=a.size-1;i>=0;i--)
		out<<a.a[i];
	return out;
}
bigint getnum(int l,int r)
{
	bigint num;
	num.size=r-l+1;
	for(int i=0;i<num.size;num.a[i]=a[r-i],i++);
	return num;
}
void s(int st,bigint temp)
{
	if(k==0)
	{
		bigint last=getnum(st,n-1);
		temp=last*temp;
		ans=max(ans,temp);
		return;
	}
    else
		for(int i=st;i<n-1;i++)
			k--,s(i+1,temp*getnum(st,i)),k++;
}
int main()
{
 	freopen("1018.in","r",stdin);
// 	freopen("1018.out","w",stdout);
    n=read(),k=read();
    for(int i=0;i<n;a[i++]=readc()-'0');
	bigint buf=1;
    s(0,buf);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}