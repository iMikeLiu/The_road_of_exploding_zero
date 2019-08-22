#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
int q[101][101];
int sum=0;
int sx,sy,x,y,ex,ey;
void dfs(int a,int b)
{
	if (a==ex&&b==ey)
	{
		sum++;
		return;
	}
	q[a][b]=0;
	if(q[a-1][b]!=0)
		dfs(a-1,b),q[a-1][b]=1;
	if(q[a][b-1]!=0)
		dfs(a,b-1),q[a][b-1]=1;
	if(q[a][b+1]!=0)
		dfs(a,b+1),q[a][b+1]=1;
	if(q[a+1][b]!=0)
		dfs(a+1,b),q[a+1][b]=1;
}
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
int main()
{
 	freopen("1605.in","r",stdin);
// 	freopen("1605.out","w",stdout);
	int n=read(),m=read(),t=read();
    cin>>sx>>sy>>ex>>ey;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            q[i][j]=1;
    for(int i=1;i<=t;i++)
		q[read()][read()]=0;
    dfs(sx,sy);
    cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
