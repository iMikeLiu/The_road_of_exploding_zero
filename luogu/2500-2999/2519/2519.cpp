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
#include<vector>
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
int f[100005];
vector<int>l[100005];
map<pair<int,int>,int>s;



int main()
{
 	freopen("2519.in","r",stdin);
// 	freopen("2519.out","w",stdout);
	int n=read();
	for(int i=0;i<n;i++)
	{
		int j=read()+1,k=read();
		k=n-k;
		if(j>k)
			continue;
		if(++s[make_pair(j,k)]==1)
			l[k].push_back(j);
	}
	for(int i=1;i<=n;++i)
	{
		f[i]=f[i-1];
		for(int j=0;j<(int)l[i].size();++j)
			f[i]=max(f[i],f[l[i][j]-1]+min(i-l[i][j]+1,s[make_pair(l[i][j],i)]));
	}
	printf("%d\n",n-f[n]);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}