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
int n,m,pre[3]={2,0,1},nxt[3]={1,2,0},ans[30005][3],ans_cnt,cnt;
void work(int x,int y,int t)
{
    if(ans_cnt>n)
		return;
    else if(x==y)
		ans_cnt+=t+1;
    else if(x>y)
		ans_cnt+=2,work(y,x-y,nxt[t]);
    else
		ans_cnt++,work(y-x,x,pre[t]);
}



int main()
{
 	freopen("2646.in","r",stdin);
// 	freopen("2646.out","w",stdout);
	for(n=read(),m=read();n!=-1&&m!=-1;n=read(),m=read())
	{
        cnt=0;
        for(int i=1;i<m;i++)
        {
            int j=m-i;
            ans_cnt=0;
            work(i,j,(n-1)%3);
            if(ans_cnt==n)
				ans[++cnt][nxt[(n-1)%3]]=i,ans[cnt][(n-1)%3]=m,ans[cnt][pre[(n-1)%3]]=j;
        }
        printf("%d\n",cnt);
        if((n-1)%3==1)
			for(int i=cnt;i>0;i--)
				printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
        else
			for(int i=1;i<=cnt;i++)
				printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);		
	}

	fclose(stdin);
	fclose(stdout);
 	return 0;
}