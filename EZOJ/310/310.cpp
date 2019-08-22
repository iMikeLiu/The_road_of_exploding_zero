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
#define MAXN 1011 
struct lun
{
	int x,y;
	bool operator < (const lun &b) const
	{
    	if(x==b.x)
    		return y<b.y;
    	return x<b.x;
	} 
};
lun lunzi[MAXN];
bool lunzii[40044][40044];
bool cmp(lun a,lun b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
map<lun,int> mp;
int main()
{
 	freopen("310.in","r",stdin);
// 	freopen("310.out","w",stdout);
	int n=read();
	for(int i=0;i<n;i++)
		lunzi[i].x=read(),lunzi[i].y=read(),mp[lunzi[i]]++;
	sort(lunzi,lunzi+n,cmp);
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			int dx=abs(lunzi[i].x-lunzi[j].x);
			int dy=abs(lunzi[i].y-lunzi[j].y);
			int x3=lunzi[i].x+dy;
			int y3=lunzi[i].y+dx;
			int x4=lunzi[j].x+dy;
			int y4=lunzi[j].y+dx;
			if(lunzi[j].y>lunzi[i].y)
				if(mp[lun{x3,y3}]&&mp[lun{x4,y4}])	
					cnt++;
		}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}

