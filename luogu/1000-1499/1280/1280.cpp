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
LL sum[10001],f[10001];
struct task_struct
{
	LL ks,js;
};
task_struct task[10001];
bool cmp(task_struct a,task_struct b)
{
	return a.ks>b.ks;
}

int main()
{
 	freopen("1280.in","r",stdin);
// 	freopen("1280.out","w",stdout);
	int n=read(),k=read(),num=0;
	for(int i=0;i<k;task[i].ks=read(),task[i].js=read(),sum[task[i].ks]++,i++);
	sort(task,task+k,cmp);
	for(int i=n;i>=0;i--)
		if(sum[i]==0)
			f[i]=f[i+1]+1;
		else
			for(int j=1;j<=sum[i];j++,num++)
				f[i]=max(f[i],f[i+task[num].js]);
	cout<<f[1];
	

	fclose(stdin);
	fclose(stdout);
 	return 0;
}